# CXX = g++
# CXXFLAGS = -std=c++17 -g -Wall -Wextra -O2

# PROG ?= main
# OBJS = main.o SimOS.o

# all: $(PROG)

# .cpp.o:
# 	$(CXX) $(CXXFLAGS) -c -o $@ $<

# $(PROG): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# clean:
# 	rm -rf $(EXEC) *.o *.out main 

# rebuild: clean all

CXX = g++
CXXFLAGS = -std=c++17

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = runme

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $
