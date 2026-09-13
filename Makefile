CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11 -Include -g
LDFLAGS := 

SRC_DIR := src
INC_DIR := include
TEST_DIR := test
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(BUILD_DIR)/*.c, $(BUILD_DIR)/*.o, $(SRCS))

TEST_SRC := $(TEST_DIR)/main.c
TEST_OBJ := $(BUILD_DIR)/test_main.o

TARGET := test_runner

.PHONY: all clean run valgrind

all: $(TARGET)

$(TARGET): $(OBJS) $(TEST_OBJ)
	$(CC) $(OBJS) $(TEST_OBJ) -o $@ $(LDFLAGS)
	@echo "Build done: ./$(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "Cleaning done"
