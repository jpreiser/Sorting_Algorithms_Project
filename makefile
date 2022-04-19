#pragma once

CC = g++
FLAGS = -Wall -pedantic-errors

main: main.o Sorting.o
	$(CC) $(FLAGS) -o main main.o Sorting.o

main.o: main.cpp Sorting.h
	$(CC) $(FLAGS) -c main.cpp

Sorting.o: Sorting.cpp Sorting.h
	$(CC) $(FLAGS) -c Sorting.cpp

run: compile
	./main

clean:
	rm -f *.o *.gch main