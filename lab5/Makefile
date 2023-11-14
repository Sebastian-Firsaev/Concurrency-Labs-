CXX = g++
CPPFILES = main.cpp Semaphore.cpp
CPPFLAGS = -Wall
LDFLAGS = -pthread # You might need to add other libraries here
EXE = dining_philosophers

SRCS = $(CPPFILES)
OBJS = $(subst .cpp,.o,$(CPPFILES))

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS)

ALL: $(OBJS)
	$(CXX) $(OBJS) -o $(EXE) $(LDFLAGS)