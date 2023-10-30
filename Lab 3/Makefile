#Lab 3
#Sebastian Firsaev
#GPL-3 licence
#https://github.com/Sebastian-Firsaev/Concurrency-Labs-/tree/main

CC=g++
CFLAGS=-std=c++11 -pthread -Wall
BARRIER_FILES=main.o Semaphore.o Barrier.o

# This rule specifies that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Build the 'RELEASE' executable from the source files in $(BARRIER_FILES)
RELEASE: $(BARRIER_FILES)
	$(CC) -o main $(BARRIER_FILES) $(CFLAGS)

# Build the 'DEBUG' executable from the source files in $(BARRIER_FILES) with debugging flags
DEBUG: CFLAGS += -g -O0
DEBUG: $(BARRIER_FILES)
	$(CC) -o main $(BARRIER_FILES) $(CFLAGS)

# Define a target to remove used .o files that are no longer needed
CLEAN:
	rm *.o