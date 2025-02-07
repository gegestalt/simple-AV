flags=-O2 -Wall -std=c17
ldflags=-lbu 
.PHONY: all clean
all: clean simple-av
simple-av: simple-av.o
	$(CC) $(flags) $^ -o $@ $(ldflags)
simple-av.o: simple-av.c simple-av.h
	$(CC) $(flags) -c $< 
clean:
	rm -f *.o simple-av
	