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
long merge(int toSort[], int leftFirst, int leftLast, int rightFirst, int rightLast);

/* An implementation of merge sort*/
long mergeSort(int toSort[], int left, int right);

/* An overlad implementation of merge sort using the first n values specified by the user. */
long mergeSort(int toSort[], int sortSize);

/* An implementation of heap sort*/
long heapSort(int toSort[], int numValues);

/* Function for reconstructing a heap after swaps have taken place. */
long ReheapDown(int toSort[], int root, int bottom);

/* A method that creates the partition for a given quicksort. */
int partition_low(int toSort[], int left, int right);

/* Another method for partitioning for a quicksort. */
int partition_high(int toSort[], int left, int right);

/* A method for generating random pivots for partitions. */
int rand_partition(int toSort[], int left, int right);

/* An implementation of quicksort with the first value as the pivot. */
long quickSortFP(int toSort[], int left, int right);

/* An implementation of quicksort using a random pivot.*/
long quickSortRP(int toSort[], int low, int high);

/* A function for taking input from the user for how many values of the list to sort before
passing the array and input to the overloaded functions. */
void experiments(int toSort[]);

#endif