flags=-O2 -Wall -std=c17
ldflags=-lbu 
.PHONY: all clean
all: clean simple-af-av
simple-av: simple-af-av.o
	$(CC) $(flags) $^ -o $@ $(ldflags)
simple-av.o: simple-af-av.c simple-af-av.h
	$(CC) $(flags) -c $< 
clean:
	rm -f *.o simple-av
	