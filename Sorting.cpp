#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>
#include "Sorting.h"


void selectionSort(int toSort[]) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void selectionSort(int toSort[], int sortSize) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void mergeSort(int toSort[]) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void mergeSort(int toSort[], int sortSize) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void heapSort(int toSort[]) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void heapSort(int toSort[], int sortSize) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void quickSortFP(int toSort[]) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void quickSortFP(int toSort[], int sortSize) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void quickSortRP(int toSort[]) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

void quickSortRP(int toSort[], int sortSize) {
    std::cout << "Compiled and running" << std::endl;

    return;
}

/* A function for taking input from the user for how many values of the list to sort before
passing the array and input to the overloaded functions. */
void experiments(int toSort[]) {
    int nSorts;
    while(1) {
        std::string type;
        std::cout << "selection-sort (s)   merge-sort (m)   heap-sort (h)   quick-sort-fp (q)\n";
        std::cout << "quick-sort-rp (r)   exit (x)" << std::endl;
        std::cout << "Enter the algorithm for experiment: ";
        std::cin >> type;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (type == "s") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selectionSort(toSort, nSorts);
        } else if (type == "m") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mergeSort(toSort, nSorts);
        } else if (type == "h") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            heapSort(toSort, nSorts);
        } else if (type == "q") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            quickSortFP(toSort, nSorts);
        } else if (type == "r") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            quickSortRP(toSort, nSorts);
        } else if (type == "x") {
            return;    
        } else {
            std::cout << "Not a valid sorting algorithm.";
        }
    }
} // experiments 
