# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Target
TARGET = $(BIN_DIR)/rpg

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Rules
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# For debugging purposes
print-%:
	@echo $* = $($*)
