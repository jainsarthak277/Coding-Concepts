src = $(wildcard *.c)
obj = $(src:.c=.o)

CC = gcc

CFLAGS = -g -O0 -Wall -pthread

counter: $(obj)
	$(CC) $(CFLAGS) -o counter $(obj)

.PHONY: clean
clean:
	rm -f $(obj) counter
