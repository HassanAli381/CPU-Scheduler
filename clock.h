//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#ifndef CPU_SCHEDULER_CLOCK_H
#define CPU_SCHEDULER_CLOCK_H

#include <atomic>

//// clock stuff
// atomic global tick count
extern std::atomic<int> tick_count;
extern std::atomic<bool> running;

void increment_tick();
void clockHandler();
void wait_for_next_tick();

#endif //CPU_SCHEDULER_CLOCK_H
