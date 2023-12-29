CC = gcc
CFLAGS = -g -Wall
LDGAGS = 
LDLIBS = 

game: game.o

game.o: game.c

.PHONY: clean
clean:
	rm -f *.o a.out core game
.PHONY: all
all: clean game
