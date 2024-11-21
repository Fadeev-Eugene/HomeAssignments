CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wpedantic

SRC = Transformer.cpp Autobot.cpp Decepticon.cpp Weapon.cpp Vehicle.cpp
OBJ = $(SRC:.cpp=.o)
TEST_SRC = main.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TARGET = main

.PHONY: default all clean cleanall

default: all

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) -o $@ $(OBJ) $(TEST_OBJ)

test: $(TARGET)

clean:
	rm -f *.o

cleanall: clean
	rm -f $(TARGET)
