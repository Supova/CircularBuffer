CC = gcc
CFLAGS = -Wall -Wextra -O0 -I include/

# Build directory
BUILD_DIR = build

# Source files
CB_SRC = src/circular_buffer.c
CB_OBJ = $(BUILD_DIR)/src/circular_buffer.o

MAIN_SRC = src/main.c
MAIN_OBJ = $(BUILD_DIR)/src/main.o
MAIN_BIN = $(BUILD_DIR)/main

# Test files
TEST_SRC = tests/c/test_runner.c $(wildcard tests/c/test_*.c)
TEST_OBJ = $(TEST_SRC:tests/c/%.c=$(BUILD_DIR)/tests/c/%.o)
TEST_BIN = $(BUILD_DIR)/test

# Ensure build directories exist
$(shell mkdir -p $(BUILD_DIR)/src $(BUILD_DIR)/tests/c)

# Default target: build main program
all: $(MAIN_BIN)

# Build main program
$(MAIN_BIN): $(CB_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Run main program
run: $(MAIN_BIN)
	./$(MAIN_BIN)

# Build and run tests
test: $(CB_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_BIN) $^
	./$(TEST_BIN)

# Pattern rules for compiling .c to .o in build directory
$(BUILD_DIR)/src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/tests/c/%.o: tests/c/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf $(BUILD_DIR)
