#pragma once

CC = g++
FLAGS = -Wall -pedantic-errors

main: main.o BinaryTree.o
	$(CC) $(FLAGS) -o main main.o

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp
run: compile
	./main

clean:
	rm -f *.o *.gch main