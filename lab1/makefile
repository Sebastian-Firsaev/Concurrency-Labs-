#Lab1
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.
#Sebastian Firsaev
#GPL-3 licence
#https://github.com/Sebastian-Firsaev/Concurrency-Labs-/tree/main



# Define the C++ compiler and compile flags
CC=g++
CFLAGS=-std=c++11 -pthread -Wall
MUTFILES = mutualEx.cpp Semaphore.cpp
DFLAGS = -O3 -g

# This rule specifies that each .o file depends on a .cpp file with the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Build the 'HELLO' executable from helloThreads.o and Semaphore.o
HELLO: helloThreads.o Semaphore.o
	$(CC) $(CFLAGS) helloThreads.o Semaphore.o -o HELLO

# Build the 'MUTUAL' executable from the source files in $(MUTFILES)
MUTUAL: $(MUTFILES)
	$(CC) $(CFLAGS) $(MUTFILES) -o MUTUAL

# Build the 'DEBUG' executable from the source files in $(MUTFILES) with debugging flags
DEBUG: $(MUTFILES)
	$(CC) $(CFLAGS) $(DFLAGS) $(MUTFILES) -o DEBUG

# Define a target to clean up generated files
CLEAN:
	rm -f *.o HELLO MUTUAL DEBUG
