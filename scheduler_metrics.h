//
/// Created by Al-Hassan Ali on 8/8/2024.
//


#ifndef CPU_SCHEDULER_SCHEDULER_METRICS_H
#define CPU_SCHEDULER_SCHEDULER_METRICS_H

#include <map>

void calc_cpu_utilization(int running_time, int idle_time);
void calculate_times(std::map<PCB, std::pair<int, int> >& process_to_time);

#endif //CPU_SCHEDULER_SCHEDULER_METRICS_H
