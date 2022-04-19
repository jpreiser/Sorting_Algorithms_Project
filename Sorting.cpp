#include <cstdlib>
#include <iostream>
#include <limits>
#include <iterator>
#include "Sorting.h"

void swap(int *index1, int *index2) {
    int temp = *index1;
    *index1 = *index2;
    *index2 = temp;
}

void selectionSort(int toSort[]) {
    int i, j, min_index;
    long count = 0;

    for (i = 0; i < 9999; i++) {
        min_index = i;
        for (j = i + 1; j < 10000; j++) {
            count++;
            if (toSort[j] < toSort[min_index]) {
                min_index = j;
            }
            swap(&toSort[min_index], &toSort[i]);
        }
    }
    std::cout << "\t#Selection-sort comparisons: " << count << std::endl;

    return;
}

void selectionSort(int toSort[], int sortSize) {
    int i, j, min_index;
    long count = 0;

    for (i = 0; i < sortSize - 1; i++) {
        min_index = i;
        for (j = i + 1; j < sortSize; j++) {
            count++;
            if (toSort[j] < toSort[min_index]) {
                min_index = j;
            }
            swap(&toSort[min_index], &toSort[i]);
        }
    }
    std::cout << "1 2 3 4 5 ... " << toSort[sortSize - 1] << std::endl;
    std::cout << "\t#Selection-sort comparisons: " << count << std::endl;

    return;
    

}

long merge(int toSort[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    long comparison = 0;
    int tempArray[10000];
    int index = leftFirst;
    int saveFirst = leftFirst;
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        if (toSort[leftFirst] < toSort[rightFirst]) {
            tempArray[index] = toSort[leftFirst];
            leftFirst++;
        } else {
            tempArray[index] = toSort[rightFirst];
            rightFirst++;
        }
        comparison++;
        index++;
    }

    while (leftFirst <= leftLast) {
        tempArray[index] = toSort[leftFirst];
        leftFirst++;
        index++;
    }
    while (rightFirst <= rightLast) {
        tempArray[index] = toSort[rightFirst];
        rightFirst++;
        index++;
    }
    for (index = saveFirst; index <= rightLast; index++) {
        toSort[index] = tempArray[index];
    }
    return comparison;
} // merge

long mergeSort(int toSort[], int first, int last) {
    long comparison = 0;
    if (first < last) {
        int middle = (first + last) / 2;
        comparison = comparison + mergeSort(toSort, first, middle);
        comparison = comparison + mergeSort(toSort, middle + 1, last);
        comparison = comparison + merge(toSort, first, middle, middle + 1, last);
    }

    return comparison;
} // full mergeSort

long mergeSort(int toSort[], int sortSize) {
    long comparison = 0;
    int first, last;
    first = 0; 
    last = sortSize - 1;
    if (first < last) {
        int middle = (first + last) / 2;
        comparison = comparison + mergeSort(toSort, first, middle);
        comparison = comparison + mergeSort(toSort, middle + 1, last);
        comparison = comparison + merge(toSort, first, middle, middle + 1, last);
    }

    return comparison;
} // experimental mergeSort

long heapSort(int toSort[], int numValues) {
    int index;
    long comparison = 0;
    for (index = numValues / 2 - 1; index >= 0; index --) {
        comparison = comparison + ReheapDown(toSort, index, numValues - 1); 
    }
    
    for (index = numValues - 1; index >= 1; index--) {
        swap(&toSort[0], &toSort[index]);
        comparison = comparison + ReheapDown(toSort, 0, index - 1); 
    }
    return comparison;
}

long ReheapDown(int toSort[], int root, int bottom) {
    long comparison = 0;
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom) {
        comparison += 2;
        if (leftChild == bottom) {
            maxChild = leftChild;
        } else {
            if (toSort[leftChild] <= toSort[rightChild]) {
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            }
        }
        if (toSort[root] < toSort[maxChild]) {
            swap(&toSort[root], &toSort[maxChild]); 
            comparison = comparison + ReheapDown(toSort, maxChild, bottom);
        }
    }
    return comparison;
}

int partition_low(int toSort[], int left, int right) {
    int j, temp, i = left + 1;

    for (j = left + 1; j < right; j++) {
        if (toSort[j] <= toSort[left]) {
            swap(&toSort[j], &toSort[left]);
        }
    }

    temp = toSort[i-1];
    toSort[i-1] = toSort[left];
    toSort[left] = temp;
    return i;
}

int partition_high(int toSort[], int left, int right) {
    int pivot = toSort[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (toSort[j] <= pivot) {
            swap(&toSort[i], &toSort[j]);
        }
    }
    swap(&toSort[i + 1], &toSort[right]);
    return (i + 1);
}

int rand_partition(int toSort[], int left, int right) {
    srand(time(NULL));
    int random = left + rand() % (right - left);
    swap(&toSort[random], &toSort[right]);
    return partition_high(toSort, left, right);
}

long quickSortFP(int toSort[], int left, int right) {
    long comparison = 0;
    int count = 0;
    if(left < right - 1) {
        count = count + right - left - 1;
        int q = partition_low(toSort, left, right);
        comparison = count + comparison + quickSortFP(toSort, left, q-1);
        comparison = count - 1 + comparison + quickSortFP(toSort, q + 1, right);
    }
    return comparison;
}

long quickSortRP(int toSort[], int left, int right) {
    long comparison = 0;
    int count = 0;
    if(left < right - 1) {
        int q = rand_partition(toSort, left, right);
        comparison = count + comparison + quickSortRP(toSort, left, q - 1);
        comparison = count - 1 + comparison + quickSortRP(toSort, q + 1, right);
    }
    return comparison;
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
            long comparison = 0;
            comparison = comparison + mergeSort(toSort, 0, nSorts);
            std::cout << "1 2 3 4 5 ... " << toSort[nSorts] << std::endl;
            std::cout << "\t #Merge-sort number of comparisons: " << comparison << std::endl;
        } else if (type == "h") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            long comparison = 0;
            comparison = heapSort(toSort, nSorts);
            std::cout << "1 2 3 4 5 ... " << toSort[nSorts] << std::endl;
            std::cout << "\t #Heap-sort number of comparisons: " << comparison << std::endl;
        } else if (type == "q") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            long comparison = 0;
            comparison = quickSortFP(toSort, 0, nSorts);
            std::cout << "1 2 3 4 5 ... " << toSort[nSorts] << std::endl;
            std::cout << "\t #Quick-sort-fp number of comparisons: " << comparison << std::endl;
        } else if (type == "r") {
            std::cout << "Enter the first n values to sort: ";
            std::cin >> nSorts;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            long comparison = 0;
            comparison = quickSortRP(toSort, 0, nSorts);
            std::cout << "1 2 3 4 5 ... " << toSort[nSorts] << std::endl;
            std::cout << "\t #Quick-sort-rp number of comparisons: " << comparison << std::endl;
        } else if (type == "x") {
            return;    
        } else {
            std::cout << "Not a valid sorting algorithm.";
        }
    }
} // experiments 
