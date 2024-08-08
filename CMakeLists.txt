cmake_minimum_required(VERSION 3.21)
project(CPU_Scheduler)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPU_Scheduler
        main.cpp process.h process.cpp clock.h clock.cpp scheduler.h scheduler.cpp scheduler_metrics.h scheduler_metrics.cpp debugger.h debugger.cpp comparator.h)
