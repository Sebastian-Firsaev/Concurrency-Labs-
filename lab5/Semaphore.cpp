#include "Semaphore.h"

/*! \file Semaphore.cpp
    \brief Implementation of Semaphore class methods.
*/

/*! \class Semaphore
    \brief A Semaphore Implementation using C++11 features such as mutex and condition variables.
*/

/*! 
    \brief Waits until the semaphore's count is greater than 0 and decrements the count.
*/
void Semaphore::Wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [&]() -> bool { return m_uiCount > 0; });
    --m_uiCount;
}

/*! 
    \brief Waits until the semaphore's count is greater than 0 for a specified duration and decrements the count.
    \param crRelTime Duration to wait for the semaphore.
    \return True if the semaphore is signaled within the specified duration, false otherwise.
*/
template<typename R, typename P>
bool Semaphore::Wait(const std::chrono::duration<R, P>& crRelTime)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if (!m_condition.wait_for(lock, crRelTime, [&]() -> bool { return m_uiCount > 0; })) {
        return false;
    }
    --m_uiCount;
    return true;
}

/*! 
    \brief Increases the semaphore's count and notifies one waiting thread.
*/
void Semaphore::Signal()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    ++m_uiCount;
    m_condition.notify_one();
}
