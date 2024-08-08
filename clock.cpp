//
/// Created by Al-Hassan Ali on 8/8/2024.
//
#include "clock.h"
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>

std::atomic<int> tick_count(1);
std::atomic<bool> running(true);

bool tick_updated = false;
std::mutex mtx;
std::condition_variable cv;

using namespace std::chrono_literals;

void increment_tick() {
    std::this_thread::sleep_for(1000ms); // sleep thread for 1 sec

    {
        std::lock_guard<std::mutex> guard(mtx); // lock the mutex
        ++tick_count;
        tick_updated = true;
    }

    cv.notify_all(); // Notify all waiting threads!
//    std::cout << "t= " << tick_count << std::endl;
}

void clockHandler() {
    while(running) {
        increment_tick();
    }
}

void wait_for_next_tick() {
    std::unique_lock<std::mutex> lock(mtx); // lock the mutex
    // (used here unique_lock not lock_guard because wait requires temporarily release the mutex while the thread is waiting for the condition to be met,
    // additionally the lock_guard will cause deadlock! so lock_guard isn't suitable for use with condition variables )

    // wait untill the tick_updated is true
    cv.wait(lock, [] {
        return tick_updated;
    });

    tick_updated = false; // restet it again
}
