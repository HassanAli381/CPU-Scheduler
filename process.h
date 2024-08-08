//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#ifndef CPU_SCHEDULER_PROCESS_H
#define CPU_SCHEDULER_PROCESS_H

#include <iostream>
#include <queue>

struct PCB {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;

    bool operator <(const PCB& other) const {
        return this->process_id < other.process_id;
    }
};

extern std::queue<PCB> processes;

void generate_processes();

void load_processes();

void debug_processes_queue(std::queue<PCB> all_processes);

#endif //CPU_SCHEDULER_PROCESS_H
