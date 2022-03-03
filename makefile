CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -ggdb

BIN = bin
EXEC = main

$(EXEC): *.c
	@printf "\033[33mBuilding...\033[m\n"
	$(CC) $^ -o $(BIN)/$@ $(CFLAGS) 
clean:
	@echo "cleaning"
	rm $(BIN)/*
