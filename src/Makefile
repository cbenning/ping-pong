
CC=g++
CFLAGS := -Wall -Werror -Wshadow -std=gnu++98
BIN_OUTPUT := ../bin/
BIN_FILE := pingpong

all:
	mkdir -p $(BIN_OUTPUT)
	$(CC) $(CFLAGS) -o $(BIN_OUTPUT)$(BIN_FILE) main.cpp
	chmod +x $(BIN_OUTPUT)$(BIN_FILE)

clean:
		rm -rf *.o ../bin
