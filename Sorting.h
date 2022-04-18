#ifndef SORTING_H
#define SORTING_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>

/* An implementation of selection sort.*/
void selectionSort(int toSort[]);

/* An overlad implementation of selection sort using the first n values specified by the user. */
void selectionSort(int toSort[], int sortSize);

/* An implementation of merge sort*/
void mergeSort(int toSort[]);


/* An overlad implementation of merge sort using the first n values specified by the user. */
void mergeSort(int toSort[], int sortSize);

/* An implementation of heap sort*/
void heapSort(int toSort[]);


/* An overlad implementation of heap sort using the first n values specified by the user. */
void heapSort(int toSort[], int sortSize);

/* An implementation of quicksort with the first value as the pivot. */
void quickSortFP(int toSort[]);

/* An overlad implementation of quicksort with the first value as the pivot,
using the first n values specified by the user. */
void quickSortFP(int toSort[], int sortSize);

/* An implementation of quicksort using a random pivot.*/
void quickSortRP(int toSort[]);

/* An overlad implementation of quicksort with a ranbom pivot,
using the first n values specified by the user. */
void quickSortRP(int toSort[], int sortSize);

/* A function for taking input from the user for how many values of the list to sort before
passing the array and input to the overloaded functions. */
void experiments(int toSort[]);

#endif