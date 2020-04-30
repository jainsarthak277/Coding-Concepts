src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

CC = g++

CFLAGS = -g -O0 -Wall

lock_log: $(obj)
	$(CC) $(CFLAGS) -o lock_log $(obj)

.PHONY: clean
clean:
	rm -f $(obj) lock_log
