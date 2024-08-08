//
/// Created by Al-Hassan Ali on 8/8/2024.
//


#ifndef CPU_SCHEDULER_DEBUGGER_H
#define CPU_SCHEDULER_DEBUGGER_H

#include "process.h"
#include "comparator.h"

void debug_priority_queue(std::priority_queue<PCB, std::vector<PCB>, compare_PCB_by_remaining_time> q);


#endif //CPU_SCHEDULER_DEBUGGER_H
