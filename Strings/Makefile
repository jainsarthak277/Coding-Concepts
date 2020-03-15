src = $(wildcard *.c)
obj = $(src:.c=.o)

CC = gcc

CFLAGS = -g -O0 -Wall

strcpy: $(obj)
	$(CC) $(CFLAGS) -o strcpy $(obj)

.PHONY: clean
clean:
	rm -f $(obj) strcpy
