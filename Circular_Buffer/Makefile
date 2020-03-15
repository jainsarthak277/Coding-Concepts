src = $(wildcard *.c)
obj = $(src:.c=.o)

CC = gcc

CFLAGS = -g -O0 -Wall

buffer: $(obj)
	$(CC) $(CFLAGS) -o buffer $(obj)

.PHONY: clean
clean:
	rm -f $(obj) buffer
