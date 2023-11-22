CXX = g++
CPPFILES = main.cpp Semaphore.cpp
CPPFLAGS = -Wall
LDFLAGS = -pthread 
EXE = prodCon

SRCS = $(CPPFILES)
OBJS = $(subst .cpp,.o,$(CPPFILES))

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS)

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXE)
