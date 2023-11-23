# Author: Sebastian Firsaev
# License: GPL-3
# Git URL: https://github.com/Sebastian-Firsaev/Concurrency-Labs-/tree/main
# Lab 4

CXX = g++
CPPFILES = main.cpp Semaphore.cpp SafeBuffer.cpp Event.cpp
CPPFLAGS = -Wall
LDFLAGS = -pthread 
EXE = prodCon

SRCS = $(CPPFILES)
OBJS = $(subst .cpp,.o,$(CPPFILES))

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS)

ALL: $(OBJS)
	$(CXX) $(OBJS) -o $(EXE) $(LDFLAGS)

doc:
	doxygen Doxyfile

clean:
	rm -f $(OBJS) $(EXE) -r html latex
