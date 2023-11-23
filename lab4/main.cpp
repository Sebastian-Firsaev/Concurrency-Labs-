#include "SafeBuffer.h"
#include "Event.h"
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>

const int num_threads = 100;
const int buffer_size = 20;

void producer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < numLoops; ++i) {
        std::shared_ptr<Event> e = std::make_shared<Event>(std::rand() % 26);
        theBuffer->put(e);
    }

    std::shared_ptr<Event> e = std::make_shared<Event>(-1); // Signify end of production
    theBuffer->put(e);
}

void consumer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, Semaphore& sem, std::vector<int>& charCount) {
    while (true) {
        std::shared_ptr<Event> e = theBuffer->get();
        int eventId = e->consume();
        if (eventId == -1) break; // End of consumption

        sem.Wait();
        charCount[eventId]++;
        sem.Signal();
    }
}

int main() {
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> aBuffer(new SafeBuffer<std::shared_ptr<Event>>(buffer_size));
    Semaphore sem(1); // Semaphore initialized with count 1
    std::vector<int> charCount(26, 0); // Character count initialized with 0

    const int numProducers = 5;
    const int numConsumers = 5;
    const int numCharPerProducer = 10;

    for (int i = 0; i < numProducers; ++i) {
        producers.emplace_back(producer, aBuffer, numCharPerProducer);
    }

    for (int i = 0; i < numConsumers; ++i) {
        consumers.emplace_back(consumer, aBuffer, std::ref(sem), std::ref(charCount));
    }

    for (auto& producerThread : producers) {
        producerThread.join();
    }

    for (auto& consumerThread : consumers) {
        consumerThread.join();
    }

    for (int i = 0; i < 26; ++i) {
        std::cout << "Character " << static_cast<char>('a' + i) << ": " << charCount[i] << std::endl;
    }

    return 0;
}
