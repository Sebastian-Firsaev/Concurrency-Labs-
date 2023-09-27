#Sebastian Firsaev 27/09/23
#Makefile



CC=g++
CFLAGS=-std=c++11 -pthread -Wall
MUTFILES=Semaphore.cpp Semaphore.h
DFLAGS=-O8 -g

# This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

REND: rendezvous.cpp Semaphore.cpp
	$(CC) $(CFLAGS) $^ -o REND

MUTUAL: $(MUTFILES)
	$(CC) $(CFLAGS) $^ -o muty

DEBUG: $(MUTFILES)
	$(CC) $(CFLAGS) $(DFLAGS) Semaphore.cpp -o muty

CLEAN:
	rm -f *.o rendezvous muty
