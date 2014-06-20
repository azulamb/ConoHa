# Macro
CC=gcc
CFLAGS=-Wall -O2
prefix=/usr/local/bin

ConoHa:	ConoHa.c
		$(CC) $(CFLAGS) -o ConoHa ConoHa.c

clean:
		rm ConoHa

install:
		cp ConoHa $(prefix)/ConoHa