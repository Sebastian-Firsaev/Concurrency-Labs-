#include "Barrier.h"

/*! Barrier constructor*/
Barrier::Barrier(){
  this->count = 0;
  threadNum = 0;
  condition = false;
  mutex = std::make_shared<Semaphore>(1);
  barrier1 = std::make_shared<Semaphore>(0);
  barrier2 = std::make_shared<Semaphore>(1); // Add the second turnstile semaphore
}

/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){
  this->count = count;
  threadNum = 0;
  condition = false;
  mutex = std::make_shared<Semaphore>(1);
  barrier1 = std::make_shared<Semaphore>(0);
  barrier2 = std::make_shared<Semaphore>(1); // Add the second turnstile semaphore
}

/*! waits for all the threads before starting second half of code*/ 
void Barrier::waitForAll(){
  mutex->Wait();
  threadNum++;

  if(threadNum == count){
    barrier1->Signal(); // First half of the barrier
  }

  mutex->Signal();

  barrier1->Wait();
  barrier1->Signal();

  mutex->Wait();

  threadNum++;

  if(threadNum == count){
    barrier2->Signal(); // Second half of the barrier
    threadNum = 0;
  }

  mutex->Signal();

  barrier2->Wait();
  barrier2->Signal();
}
