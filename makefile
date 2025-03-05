# Compiler and flags
CC = g++
CFLAGS = -Wall -Werror -std=c++17

# Source files
SRC = main.cpp stable_matching.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = stable_matching

# Build rule
build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile source files
main.o: main.cpp stable_matching.h utils.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

stable_matching.o: stable_matching.cpp stable_matching.h
	$(CC) $(CFLAGS) -c stable_matching.cpp -o stable_matching.o

utils.o: utils.cpp utils.h
	$(CC) $(CFLAGS) -c utils.cpp -o utils.o

# Run the program
run: $(TARGET)
	./$(TARGET)
