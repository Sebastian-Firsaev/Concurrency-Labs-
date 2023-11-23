#include "Semaphore.h"

/*! \file Semaphore.cpp
    \brief Implementation of Semaphore class methods.
*/

/*! \class Semaphore
    \brief A Semaphore Implementation using C++11 features such as mutex and condition variables.
*/

/*! 
    \brief Closes the thread until the semaphore count is greater than 0.
*/
void Semaphore::Wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [&]() -> bool { return m_uiCount > 0; });
    --m_uiCount;
}

/*! 
    \brief Allows a thread to open.
*/
void Semaphore::Signal() 
{
    std::unique_lock<std::mutex> lock(m_mutex);
    ++m_uiCount;
    m_condition.notify_one();
}
