CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lSDL2

SRCS = main.c window.c
OBJS = $(SRCS:.c=.o)
TARGET = my_program

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

clean:
	rm -f $(OBJS) $(TARGET)
