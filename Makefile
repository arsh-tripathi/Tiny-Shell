# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./src/include

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# List of source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# List of object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Executable name
EXECUTABLE = shell

# Main target
all: $(EXECUTABLE)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
