CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all: tokenizar

tokenizar: tokenizar.o
	$(CC) $(CFLAGS) -o tokenizar tokenizar.o

tokenizar.o: tokenizar.c
	$(CC) $(CFLAGS) -c tokenizar.c

clean:
	rm -f tokenizar *.o
