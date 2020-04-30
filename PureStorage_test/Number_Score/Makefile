src = $(wildcard *.c)
obj = $(src:.c=.o)

CC = g++

CFLAGS = -g -O0 -Wall

number_score: $(obj)
	$(CC) $(CFLAGS) -o number_score $(obj)

.PHONY: clean
clean:
	rm -f $(obj) number_score
