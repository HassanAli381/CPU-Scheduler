//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#include "process.h"
#include "scheduler_metrics.h"
#include <iostream>

void calc_cpu_utilization(int running_time, int idle_time) {
    int total_time = (running_time + idle_time);

    std::cout << "CPU Utilization = " <<  ((running_time * 1.0) / (total_time * 1.0)) * 100.0 << " %\n";
}

void calculate_times(std::map<PCB, std::pair<int, int> >& process_to_time) {
    int total_response_time = 0;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    for(auto &process : process_to_time) {
        auto actual_process = process.first;

        int start_time = process.second.first; // time that cpu started working on this process
        int finish_time = process.second.second; // time that process finished it's work and terminated!

        int response_time = start_time - actual_process.arrival_time; // Time from when a process arrives to when it first starts executing
        int turnaround_time = finish_time - actual_process.arrival_time + 1; // Total time taken from the arrival to the completion of the process
        int waiting_time = turnaround_time - actual_process.burst_time;

        total_response_time += response_time;
        total_turnaround_time += turnaround_time;
        total_waiting_time += waiting_time;

        std::cout << "Process number " << actual_process.process_id << " => started working at " << start_time << ", and finished it's work at " << finish_time
        << ", with response time = " << response_time << ", waiting time = " << waiting_time << ", and turnaround time = " << turnaround_time << std::endl;
    }

    int number_of_processes = (int)process_to_time.size();

    std::cout << "Average response time = " << (total_response_time * 1.0) / (number_of_processes * 1.0) << " seconds" << std::endl;
    std::cout << "Average turnaround time = " << (total_turnaround_time * 1.0) / (number_of_processes * 1.0) << " seconds" << std::endl;
    std::cout << "Average waiting time = " << (total_waiting_time * 1.0) / (number_of_processes * 1.0) << " seconds" << std::endl;

}