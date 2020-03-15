src = $(wildcard *.c)
obj = $(src:.c=.o)

CC = gcc

CFLAGS = -g -O0 -Wall

merge_arrays: $(obj)
	$(CC) $(CFLAGS) -o merge_arrays $(obj)

.PHONY: clean
clean:
	rm -f $(obj) merge_arrays
