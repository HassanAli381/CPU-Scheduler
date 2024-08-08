//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#ifndef CPU_SCHEDULER_COMPARATOR_H
#define CPU_SCHEDULER_COMPARATOR_H

#include "process.h"
struct compare_PCB_by_remaining_time{
    bool operator()(PCB& first, PCB& second) {
        return first.remaining_time > second.remaining_time;
    }
};

struct compare_PCB_by_priority {
    bool operator()(PCB& first, PCB& second) {
        return first.priority > second.priority;
    }
};

#endif //CPU_SCHEDULER_COMPARATOR_H
