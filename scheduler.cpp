//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#include "scheduler.h"
#include "process.h"
#include "clock.h"
#include "scheduler_metrics.h"
#include "comparator.h"

#include <thread>
#include <map>

void update_process_time(std::map<PCB, std::pair<int, int> >& process_to_time, PCB& process) {
    auto it = process_to_time[process];

    // first time to arrive
    if(it.first == 0 && it.second == 0)
        process_to_time[process].first = tick_count;

    process_to_time[process].second = tick_count;
}

void get_metrics(std::map<PCB, std::pair<int, int> >& process_to_time, int running_time, int idle_time) {
    calc_cpu_utilization(running_time, idle_time);
    calculate_times(process_to_time);
}

/// FCFS
void processFCFS(PCB& process, int& running_time, std::map<PCB, std::pair<int, int> >& process_to_time) {
    while(process.arrival_time <= tick_count && process.remaining_time > 0) {
        update_process_time(process_to_time, process);

        ++running_time;
        --process.remaining_time;
        std::cout << process.process_id << ' ';
        wait_for_next_tick();
    }
}

void fcfs() {
    std::cout << "Starting of fcfs algo\n";

    int idle_time = 0, running_time = 0;
    std::map<PCB, std::pair<int, int> > process_to_time;
    std::thread clock(clockHandler);

    while(!processes.empty()) {
        PCB process = processes.front();
        processes.pop();

        while(process.arrival_time > tick_count) {
            ++idle_time;
            std::cout << "- ";
            wait_for_next_tick();
        }

        processFCFS(process, running_time, process_to_time);
    }

    running = false;
    clock.join();

    std::cout << "\nEnd of FCFS\n";
    std::cout << "running_time = " << running_time << " idle_time = " << idle_time << std::endl;
    get_metrics(process_to_time, running_time, idle_time);
}
/// End of FCFS

/// RR
void rr() {
    std::cout << "Starting of rr algo\n";
    std::queue <PCB> ready_queue;
    int idle_time = 0, running_time = 0;

    std::cout << "please enter the Time quantum for each process";
    int TIME_SLOT = 2;
    std::cin >> TIME_SLOT;
    while(TIME_SLOT <= 0) {
        std::cout << "TIME_SLOT cannot be zero or negative, please enter a postive value";
        std::cin >> TIME_SLOT;
    }

    std::map<PCB, std::pair<int, int> > process_to_time;
    std::thread clock(clockHandler);

    while(!processes.empty() || !ready_queue.empty()) {
        while(!processes.empty() && processes.front().arrival_time <= tick_count) {
            ready_queue.push(processes.front());
            processes.pop();
        }

        int ready_queue_size = (int)ready_queue.size();
        if(ready_queue_size == 0) {
            ++idle_time;
            std::cout << "- ";
            wait_for_next_tick();
            continue;
        }

        for(int i = 0; i < ready_queue_size; ++i) {
            PCB cur_process = ready_queue.front();
            ready_queue.pop();

            int limit = std::min(cur_process.remaining_time, TIME_SLOT);
            for(int j = 0; j < limit; ++j) {
                update_process_time(process_to_time, cur_process);

                cur_process.remaining_time--;
                ++running_time;
                std::cout << cur_process.process_id << ' ';
                wait_for_next_tick();
            }

            if(!processes.empty() && processes.front().arrival_time <= tick_count) {
                ready_queue.push(processes.front());
                processes.pop();
            }

            if(cur_process.remaining_time > 0) {
                ready_queue.push(cur_process);
            }
        }
    }

    running = false;
    clock.join();

    std::cout << "\nEnd of Round-Robin Algorithm\n";
    std::cout << "running_time = " << running_time << " idle_time = " << idle_time << std::endl;
    get_metrics(process_to_time, running_time, idle_time);

}

/// HPF
void hpf() {
    std::cout << "Starting of hpf algo\n";
    std::priority_queue<PCB, std::vector<PCB>, compare_PCB_by_priority> ready_queue;

    int idle_time = 0, running_time = 0;
    std::map<PCB, std::pair<int, int> > process_to_time;
    std::thread clock(clockHandler);

    while(!processes.empty() || !ready_queue.empty()) {
        while(!processes.empty() && processes.front().arrival_time <= tick_count) {
            ready_queue.push(processes.front());
            processes.pop();
        }

        if(ready_queue.empty()) {
            ++idle_time;
            std::cout << "- ";
            wait_for_next_tick();
            continue;
        }

        PCB cur_process = ready_queue.top();
        ready_queue.pop();

        update_process_time(process_to_time, cur_process);

        ++running_time;
        cur_process.remaining_time--;
        if(cur_process.remaining_time > 0)
            ready_queue.push(cur_process);
        std::cout << cur_process.process_id << ' ';

        wait_for_next_tick();
    }

    running = false;
    clock.join();

    std::cout << "\nEnd of HPF\n";
    std::cout << "running_time = " << running_time << " idle_time = " << idle_time << std::endl;
    get_metrics(process_to_time, running_time, idle_time);

}

/// SRTN
void srtn() {
    std::cout << "Starting Shortest Remaining Time Next Algo\n";
    std::priority_queue<PCB, std::vector<PCB>, compare_PCB_by_remaining_time> ready_queue;

    int idle_time = 0, running_time = 0;
    std::map<PCB, std::pair<int, int> > process_to_time;

    std::thread clock(clockHandler);

    while(!processes.empty() || !ready_queue.empty()) {
        while(!processes.empty() && processes.front().arrival_time <= tick_count) {
            ready_queue.push(processes.front());
            processes.pop();
        }

        if(ready_queue.empty()) {
            ++idle_time;
            std::cout << "- ";
            wait_for_next_tick();
            continue;
        }

        PCB cur_process = ready_queue.top();
        ready_queue.pop();

        update_process_time(process_to_time, cur_process);

        ++running_time;
        cur_process.remaining_time--;
        if(cur_process.remaining_time > 0)
            ready_queue.push(cur_process);
        std::cout << cur_process.process_id << ' ';

        wait_for_next_tick();
    }

    running = false;
    clock.join();

    std::cout << "\nEnd of SRTN\n";
    std::cout << "running_time = " << running_time << " idle_time = " << idle_time << std::endl;
    get_metrics(process_to_time, running_time, idle_time);

}
