# Author: Sebastian Firsaev
# License: GPL-3
# Git URL: https://github.com/Sebastian-Firsaev/Concurrency-Labs-/tree/main
# Lab 5

CC=g++
CFLAGS=-std=c++11 -pthread -Wall
CPPFILES=main.cpp Semaphore.cpp
LDFLAGS=-pthread
EXE=prodCon

SRCS=$(CPPFILES)
OBJS=$(subst .cpp,.o,$(CPPFILES))

# This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LDFLAGS)

CLEAN:
	rm -f *.o $(EXE)

