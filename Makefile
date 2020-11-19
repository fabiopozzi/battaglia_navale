CFLAGS = -Wall

SRCS := $(wildcard *.c)

main: main.c
	$(CC) $(CFLAGS) -lncurses main.c -o $@

all: main

clean:
	rm main
