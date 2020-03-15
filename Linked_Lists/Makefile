src = $(wildcard *.c)
obj = $(src:.c=.o)
TARGET = list

CC = gcc

CFLAGS = -g -O0 -Wall

$(TARGET): $(obj)
	$(CC) $(CFLAGS) -o $(TARGET) $(obj)

.PHONY: clean
clean:
	rm -f $(obj) $(TARGET)
