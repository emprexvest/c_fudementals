CC = gcc
CFLAGS = -Wall -Werror -Iinclude
all: bin/main

bin/main: src/main.o src/file.c
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c include/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f bin/* src/*.o