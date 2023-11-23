#include "SafeBuffer.h"

template<typename T>
void SafeBuffer<T>::put(T item) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return buffer.size() < capacity; });
    buffer.push(item);
    cv.notify_all();
}

template<typename T>
T SafeBuffer<T>::get() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !buffer.empty(); });
    T item = buffer.front();
    buffer.pop();
    cv.notify_all();
    return item;
}

// Include any other member function definitions here if needed
