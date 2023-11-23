#ifndef SAFE_BUFFER_H
#define SAFE_BUFFER_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

template<typename T>
class SafeBuffer {
private:
    std::queue<T> buffer;
    size_t capacity;
    std::mutex mtx;
    std::condition_variable cv;

public:
    SafeBuffer(size_t size) : capacity(size) {}
    void put(T item);
    T get();
};

#include "SafeBuffer.cpp" // Include the implementation file at the end of the header file

#endif // SAFE_BUFFER_H
