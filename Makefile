CC = gcc
CFLAGS = -Wall -Wextra -g -pthread

SRC_DIRS = core ui service driver comm logic
SRCS = $(wildcard *.c) $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

TARGET = dcontrol

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
