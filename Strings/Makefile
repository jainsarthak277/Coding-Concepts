src = $(wildcard *.c)
obj = $(src:.c=.o)

CC = gcc

CFLAGS = -g -O0 -Wall

strings: $(obj)
	$(CC) $(CFLAGS) -o strings $(obj)

.PHONY: clean
clean:
	rm -f $(obj) strings
