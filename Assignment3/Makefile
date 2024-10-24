CXX = g++
CXXFLAGS = -g -Wall -pthread -I/path/to/googletest/include
GTEST_LIBS = -L/path/to/googletest/lib -lgtest -lgtest_main

SRCS = Test1.cpp Test2.cpp Test3.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = test1 test2 test3

all: $(TARGET)

test1: Test1.o $(OBJS)
	$(CXX) -o $@ $^ $(GTEST_LIBS)

test2: Test2.o $(OBJS)
	$(CXX) -o $@ $^ $(GTEST_LIBS)

test3: Test3.o $(OBJS)
	$(CXX) -o $@ $^ $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
