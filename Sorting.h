#ifndef SORTING_H
#define SORTING_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>

/* Method for swapping elements in arrays. */
void swap(int *index1, int *index2);

/* An implementation of selection sort.*/
void selectionSort(int toSort[]);

/* An overlad implementation of selection sort using the first n values specified by the user. */
void selectionSort(int toSort[], int sortSize);

/* A function for use by merge sort to merge the arrays. */
void merge(int toSort[], int leftFirst, int leftLast, int rightFirst, int rightLast, long *comaprison);

/* An implementation of merge sort*/
long* mergeSort(int toSort[], int left, int right, long *comparison);

/* An overlad implementation of merge sort using the first n values specified by the user. */
void mergeSort(int toSort[], int sortSize, long *comparison);

/* An implementation of heap sort*/
long heapSort(int toSort[], int numValues);

/* Function for reconstructing a heap after swaps have taken place. */
long ReheapDown(int toSort[], int root, int bottom);

/* A method that creates the partition for a given quicksort using the first element
as the pivot. */
int partition_low(int toSort[], int left, int right);

/* A method that creates the partition for a given quicksort using the rightmost
element as pivot. */
int partition_high(int toSort[], int left, int right);

/* A method for generating random pivots for partitions. */
int rand_partition(int toSort[], int left, int right);

/* An implementation of quicksort with the first value as the pivot. */
long* quickSortFP(int toSort[], int left, int right, long *comparison);

/* An implementation of quicksort using a random pivot.*/
long* quickSortRP(int toSort[], int low, int high, long *comparison);

/* A function for taking input from the user for how many values of the list to sort before
passing the array and input to the overloaded functions. */
void experiments();

/* A function for checking array values. */
void printValues(int toPrint[], int numToPrint);

/* A function for filling an n sized array with random values between 0 and 1 000 000. */
void fillRandom(int randomArray[], int size);

/* A function for shuffling an array for reuse in the experimental section. */
void shuffle(int arr[], int n);

#endif