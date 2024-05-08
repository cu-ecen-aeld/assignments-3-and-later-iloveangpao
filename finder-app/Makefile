# Set the compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -O2

# Check if CROSS_COMPILE is set
ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
endif

# Define the target application
TARGET := writer
SRC := writer.c
OBJ := $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Rule to make the object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to make the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: all clean
