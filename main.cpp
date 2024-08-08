#include "process.h"
#include "scheduler.h"


void showMenu() {
    std::cout << "Choose The Algorithm\n";
    std::cout << "1- First Come First Served (FCFS) \n";
    std::cout << "2- Round-Robin(RR) \n";
    std::cout << "3- preemptive Highest Priority First(HPF)\n";
    std::cout << "4- Shortest Remaining Time Next(SRTN)\n";
}

int main()
{
    generate_processes();
    load_processes();

    showMenu();
    int choice;
    std::cin >> choice;
    if(choice == 1) {
        fcfs(); // First come, first served
    }
    else if(choice == 2) {
        rr(); // Round Robin
    }
    else if(choice == 3) {
        hpf(); // Highest priority first
    }
    else if(choice == 4) {
        srtn(); // Shortest Remaining Time Next
    }
    else {
        std::cout << "Wrong choice\n";
    }

    std::cout << "End\n";

    return 0;
}
