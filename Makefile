CC = gcc
CFLAGS = -Wall -O3 -mavx -march=native
TARGET = interpola
SRCS = main.c point.c interpolate.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

purge:
	rm -f $(TARGET) $(OBJS)
