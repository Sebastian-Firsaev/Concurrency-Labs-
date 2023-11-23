#include "Barrier.h"

/*! \file Barrier.cpp
    \brief Implementation of Barrier class methods.
*/

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores.

    Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads.
*/

/*! \brief Barrier constructor */
Barrier::Barrier(){
    this->count = 0;
    threadNum = 0;
    condition = false;
    mutex = std::make_shared<Semaphore>(1);
    barrier1 = std::make_shared<Semaphore>(0);
}

/*! \brief Barrier constructor with count parameter */
Barrier::Barrier(int count){
    this->count = count;
    threadNum = 0;
    condition = false;
    mutex = std::make_shared<Semaphore>(1);
    barrier1 = std::make_shared<Semaphore>(0);
}

/*! \brief Barrier destructor */
Barrier::~Barrier(){

}

/*! \brief Sets the count value */
void Barrier::setCount(int x){
    this->count = x;
}

/*! \brief Returns the count value */
int Barrier::getCount(){
    return this->count;
}

/*! \brief Waits for all the threads before starting the second half of the code */
void Barrier::waitForAll(){
    mutex->Wait();
    threadNum++;

    if(threadNum == count){
        barrier1->Signal();
        threadNum = 0;
    }
    mutex->Signal();
    barrier1->Wait();
    barrier1->Signal();
}

