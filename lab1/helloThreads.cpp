#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

/*! displays a message first ./HELLO*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay) {
  sleep(delay);
  std::cout << "I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first" << std::endl;
  // Signal the semaphore to allow taskTwo to start
  theSemaphore->Signal();
}

/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore) {
  // Wait until the semaphore is signaled by taskOne
  theSemaphore->Wait();
  std::cout << "This ";
  std::cout << "will ";
  sleep(5);
  std::cout << "appear ";
  std::cout << "second" << std::endl;
}

int main(void) {
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem(new Semaphore);

  /**< Launch the threads */
  int taskOneDelay = 5;
  threadOne = std::thread(taskOne, sem, taskOneDelay);
  threadTwo = std::thread(taskTwo, sem);
  std::cout << "Launched from the main\n";

  /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}

