# CPU Scheduler Simulator

A comprehensive CPU scheduling simulator developed in C++ that implements various CPU scheduling algorithms such as FCFS, Round-Robin, Highest Priority First (preemptive), and Shortest Remaining Time Next (SRTN). This project also calculates key metrics like CPU Utilization, Average Waiting Time, Average Turnaround Time, and Average Response Time for better analysis and comparison of scheduling strategies.

## Features

- **Generate Processes:** Randomly generates a set of processes with varying arrival times, burst times, and priorities.
- **Multiple Scheduling Algorithms:** Supports FCFS, Round-Robin, HPF (preemptive), and SRTN.
- **Metric Calculation:** Automatically calculates and displays CPU Utilization, Average Waiting Time, Turnaround Time, and Response Time.
- **Multithreading:** Utilizes threads and multithreading to simulate real-time CPU scheduling and manage concurrent execution of processes.
- **User Interaction:** Interactive menu to choose and run different scheduling algorithms.

## Algorithms Implemented

1. **First Come, First Served (FCFS):** Non-preemptive scheduling where the process that arrives first is executed first.
2. **Round-Robin (RR):** Preemptive scheduling with a fixed time quantum.
3. **Highest Priority First (HPF):** Preemptive scheduling based on process priority.
4. **Shortest Remaining Time Next (SRTN):** Preemptive scheduling where the process with the shortest remaining time is executed next.

## Getting Started

### Prerequisites
  - C++11 or higher
  - A C++ compiler that supports threads and multithreading

- C++ Compiler (e.g., GCC)
- CMake (optional, for building the project)

### Building the Project

1. Clone the repository:
    ```bash
    git clone https://github.com/HassanAli381/CPU-Scheduler.git
    cd CPU-Scheduler
    ```

2. Compile the project:
    ```bash
    g++ -o cpu_scheduler main.cpp process.cpp clock.cpp scheduler.cpp scheduler_metrics.cpp comparator.cpp debugger.cpp -lpthread
    ```

3. Run the simulator:
    ```bash
    ./cpu_scheduler
    ```

### Using the Simulator

1. The program will first generate and load a set of processes.
2. You will then be prompted to choose a scheduling algorithm from the menu.
3. After choosing, the simulator will run the algorithm, outputting the sequence of process executions and calculating the relevant metrics.

## File Structure

- `main.cpp`: The entry point of the program.
- `process.h/cpp`: Manages process generation, loading, and basic process-related operations.
- `scheduler.h/cpp`: Contains the implementation of the scheduling algorithms.
- `scheduler_metrics.h/cpp`: Contains functions to calculate and display scheduling metrics.
- `clock.h/cpp`: Manages the simulation clock and time-related operations.
- `comparator.h`: Provides custom comparison functions for priority queues.
- `debugger.h/cpp`: Utility functions for debugging and visualizing the process queues.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you have any ideas for improvements or encounter any bugs.
