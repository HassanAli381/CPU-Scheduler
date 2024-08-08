//
/// Created by Al-Hassan Ali on 8/8/2024.
//

#include "process.h"
#include <iostream>
#include <ctime>
#include <fstream>


std::queue<PCB> processes;

void generate_processes() {
    srand(time(0));

    std::ofstream output_file("processes.txt");
    if(!output_file.is_open()) {
        std::cout << "Cannot open the file, please try again";
        exit(0);
    }

    int n;
    n = rand() % 50 + 1;
    output_file << n << "\n";

    int arrival_time = 1;
    for(int i = 1; i <= n; ++i) {
        int id = i;
        arrival_time += rand() % 10; // process are coming in order
        int burst_time = rand() % 15 + 1;
        int remaining_time = burst_time;
        int priority = rand() % 10 + 1;  // [1 => is the highest priority], [10 => is the lowest priority]
        output_file << id << ' ' << arrival_time << ' ' << burst_time << ' ' << remaining_time << ' ' << priority << '\n';
    }

    output_file.flush();
    output_file.close();
    std::cout << "Processes generated successfully!\n";
}

void load_processes() {
    std::ifstream file("processes.txt");
    if(!file.is_open()) {
        std::cout << "Cannot open the file, please try again!";
        exit(0);
    }

    int n ;
    file >> n;
//    std::cout << "Number of processes are = " << n << std::endl;

    PCB process;
    for(int i = 0; i < n; i++) {
        file >> process.process_id;
        file >> process.arrival_time;
        file >> process.burst_time;
        file >> process.remaining_time;
        file >> process.priority;
        processes.push(process);
    }

    std::cout << "Filled processes successfully!\n";
    file.close();
}

void debug_processes_queue(std::queue<PCB> all_processes) {
    while(!all_processes.empty()) {
        PCB process = all_processes.front();
        all_processes.pop();

        std::cout << process.process_id << ' ' << process.arrival_time << ' ' << process.burst_time << ' '
                  << process.remaining_time << ' ' << process.priority << std::endl;
    }
}
