#Lab1
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.



CC=g++
CFLAGS=-std=c++11 -pthread -Wall
MUTFILES = mutualEx.cpp Semaphore.cpp
DFLAGS = -O3 -g

# This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

HELLO: helloThreads.o Semaphore.o
	$(CC) $(CFLAGS) helloThreads.o Semaphore.o -o HELLO

MUTUAL: $(MUTFILES)
	$(CC) $(CFLAGS) $(MUTFILES) -o MUTUAL

DEBUG: $(MUTFILES)
	$(CC) $(CFLAGS) $(DFLAGS) $(MUTFILES) -o DEBUG

CLEAN:
	rm -f *.o HELLO MUTUAL DEBUG