CXX = g++
CXXFLAGS = -g -Wall -std=c++17
CCFiles = $(wildcard *.cc)
OFiles = $(CCFiles:cc=o)

TARGETS = multi-queues

all: $(TARGETS)
multi-queues: $(OFiles)
	$(CXX) $(OFiles) -o $@
	-rm -rf *.o *~
