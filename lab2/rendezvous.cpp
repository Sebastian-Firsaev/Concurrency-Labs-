/**
 * @file main.cpp
 * @brief Usage of Semaphores for thread synchronization
 * @version 1.0
 * @license This lab is licensed under the GPL-3
 * @author Sebastian Firsaev
 */

#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

std::atomic<int> counter(0);

/**
 * @brief Task function executed by each thread
 * @param mutexSem A shared pointer to Semaphore object for mutual exclusion
 * @param barrierSem A shared pointer to Semaphore object for synchronization
 * @param threadCount Number of threads
 */
void task(std::shared_ptr<Semaphore> mutexSem, std::shared_ptr<Semaphore> barrierSem, int threadCount) {
  for (int i = 0; i < threadCount; i++) {
    std::cout << "first" << std::endl;

    // Increment the counter and wait until all threads have incremented it
    counter++;
    if (counter.load() == threadCount) {
      barrierSem->Signal(); // Release the barrier
    } else {
      barrierSem->Wait(); // Wait for others to increment
    }

    std::cout << "second" << std::endl;

    // Increment the counter and wait until all threads have incremented it
    counter++;
    if (counter.load() == 2 * threadCount) {
      barrierSem->Signal(); // Release the barrier
    } else {
      barrierSem->Wait(); // Wait for others to increment
    }
  }
}

/**
 * @brief Main function
 * @return Program exit status
 */
int main(void) {
  std::shared_ptr<Semaphore> mutexSem = std::make_shared<Semaphore>(1);
  std::shared_ptr<Semaphore> barrierSem = std::make_shared<Semaphore>(0);
  int threadCount = 5;

  std::vector<std::thread> threadArray(threadCount);

  for (std::vector<std::thread>::size_type i = 0; i < threadArray.size(); ++i) {
    threadArray[i] = std::thread(task, mutexSem, barrierSem, threadCount);
  }

   for (std::vector<std::thread>::size_type i = 0; i < threadArray.size(); ++i) {
    threadArray[i].join();
  }

  return 0;
}
