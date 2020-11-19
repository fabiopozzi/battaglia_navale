CFLAGS = -Wall

SRCS := $(wildcard *.c)

battaglia_navale: main.c
	$(CC) $(CFLAGS) -lncurses main.c -o $@

all: battaglia_navale

clean:
	rm battaglia_navale
