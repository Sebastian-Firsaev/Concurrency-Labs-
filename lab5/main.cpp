#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <chrono>

const int COUNT = 5;
const int THINK_TIME = 3;
const int EAT_TIME = 5;

std::vector<Semaphore> forks(COUNT);

void think(int myID) {
    int seconds = rand() % THINK_TIME + 1;
    std::cout << myID << " is thinking! " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void get_forks(int philID) {
    if (philID == COUNT - 1) {
        forks[(philID + 1) % COUNT].Wait();
        forks[philID].Wait();
    } else {
        forks[philID].Wait();
        forks[(philID + 1) % COUNT].Wait();
    }
}

void put_forks(int philID) {
    if (philID == COUNT - 1) {
        forks[(philID + 1) % COUNT].Signal();
        forks[philID].Signal();
    } else {
        forks[philID].Signal();
        forks[(philID + 1) % COUNT].Signal();
    }
}

void eat(int myID) {
    int seconds = rand() % EAT_TIME + 1;
    std::cout << myID << " is chomping! " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void philosopher(int id) {
    while (true) {
        think(id);
        get_forks(id);
        eat(id);
        put_forks(id);
    }
}

int main() {
    srand (time(NULL)); // initialize random seed
    std::vector<std::thread> vt;

    for (Semaphore& s : forks) {
        // Semaphores need to be at 1 otherwise no one will ever even get a fork
        s.Signal();
    }

    for (int i = 0; i < COUNT; ++i) {
        vt.emplace_back(philosopher, i);
    }

    for (auto& v : vt) {
        v.join();
    }

    return 0;
}
