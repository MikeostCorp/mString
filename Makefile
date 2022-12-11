TARGET = myString
CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(TARGET) clean

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o main

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)