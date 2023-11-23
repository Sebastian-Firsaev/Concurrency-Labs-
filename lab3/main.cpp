/**
 * @file main.cpp
 * @brief Usage of Barrier synchronization primitive
 * @version 1.0
 * @license This lab is licensed under the GPL-3
 * @author Sebastian Firsaev
 */

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>

/**
 * @brief Function executed by each thread
 * @param barrierObj A shared pointer to Barrier object
 */
void task(std::shared_ptr<Barrier> barrierObj){
  std::cout << "first " << std::endl;
  barrierObj->waitForAll();
  std::cout << "second" << std::endl;
}

/**
 * @brief Main function
 * @return Program exit status
 */
int main(void){
  /*!< An array of threads*/
  std::vector<std::thread> threadArray(5);
  /*!< Pointer to barrier object*/
  std::shared_ptr<Barrier> barrierObj( new Barrier);

  barrierObj->setCount(5);

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}
