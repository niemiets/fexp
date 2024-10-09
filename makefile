CC = g++
CFLAGS = 
LDFLAGS = -lncurses -DNCURSES_STATIC

.PHONY: default all clean

default: all

all: main

main: main.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	help

