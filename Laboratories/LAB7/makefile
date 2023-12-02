CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.c tradestocks.c tradestocks.h
	$(CC) $(CFLAGS) -o main main.c tradestocks.c

clean:
	rm -f main