//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#include "process.h"
#include "comparator.h"

void debug_priority_queue(std::priority_queue<PCB, std::vector<PCB>, compare_PCB_by_remaining_time> q) {
    while(!q.empty()) {
        PCB process = q.top();
        q.pop();
        std::cout << process.process_id << ' ' << process.arrival_time << ' ' << process.burst_time << ' '
                  << process.remaining_time << ' ' << process.priority << std::endl;
    }
}
