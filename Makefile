# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# MSYS2 MinGW64 specific paths (assuming Raylib is in C:)
INCLUDES = -I/c/raylib/include
LDFLAGS = -L/c/raylib/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/PongPlusPlus.exe

# Create directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run 