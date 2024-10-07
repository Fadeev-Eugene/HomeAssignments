# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -g

# Define the target executable
TARGET = main

# Define source files
SRCS = main.cpp func.cpp

# Define object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp func.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
