#Lab 2
#Sebastian Firsaev
#GPL-3 licence
#https://github.com/Sebastian-Firsaev/Concurrency-Labs-/tree/main


# Define the C++ compiler and compile flags
CC=g++
CFLAGS=-std=c++11 -pthread -Wall
MUTFILES=Semaphore.cpp Semaphore.h
DFLAGS=-O8 -g

# This rule specifies that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Build the 'REND' executable from rendezvous.cpp and Semaphore.cpp
REND: rendezvous.cpp Semaphore.cpp
	$(CC) $(CFLAGS) $^ -o REND

# Build the 'MUTUAL' executable from the source files in $(MUTFILES)
MUTUAL: $(MUTFILES)
	$(CC) $(CFLAGS) $^ -o muty

# Build the 'DEBUG' executable from Semaphore.cpp with debugging flags
DEBUG: $(MUTFILES)
	$(CC) $(CFLAGS) $(DFLAGS) Semaphore.cpp -o muty

# Define a target to clean up generated files
CLEAN:
	rm -f *.o rendezvous muty
