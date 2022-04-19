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
        }
        swap(&toSort[min_index], &toSort[i]);
    }

    printValues(toSort, 10000);
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
    printValues(toSort, sortSize);
    std::cout << "\t#Selection-sort comparisons: " << count << std::endl;

    return;
    

}

void merge(int toSort[], int leftFirst, int leftLast, int rightFirst, int rightLast, long *comparison) {
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
        *comparison+=1;
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
    return;
} // merge

long* mergeSort(int toSort[], int first, int last, long *comparison) {
    if (first < last) {
        int middle = (first + last) / 2;
        mergeSort(toSort, first, middle, comparison);
        mergeSort(toSort, middle + 1, last, comparison);
        merge(toSort, first, middle, middle + 1, last, comparison);
    }
    return comparison;
} // full mergeSort

void mergeSort(int toSort[], int sortSize, long *comparison) {
    int first, last;
    first = 0; 
    last = sortSize - 1;
    if (first < last) {
        int middle = (first + last) / 2;
        mergeSort(toSort, first, middle, comparison);
        mergeSort(toSort, middle + 1, last, comparison);
        merge(toSort, first, middle, middle + 1, last, comparison);
    }
    return;
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

int partition_low(int toSort[], int left, int right, long *comparison) {
    int pivot = toSort[left];
    int i = right + 1;
    for (int j = right; j > left; j--) {
        if(toSort[j] >= pivot) {
            i--;
            swap(&toSort[i], &toSort[j]);
        }
        *comparison+=1;
    }
    swap(&toSort[left], &toSort[i-1]);
    return i-1;
}

int partition_high(int toSort[], int left, int right, long *comparison) {
    int pivot = toSort[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if(toSort[j] <= pivot) {
            i++;
            swap(&toSort[i], &toSort[j]);
        }
        *comparison+=1;
    }
    swap(&toSort[i+1], &toSort[right]);
    return(i + 1);
}

int rand_partition(int toSort[], int left, int right, long* comparison) {
    srand(time(NULL));
    int random = left + rand() % (right - left + 1);
    swap(&toSort[random], &toSort[left]);
    return partition_high(toSort, left, right, comparison);
}

long* quickSortFP(int toSort[], int left, int right, long *comparison) {
    if(left < right) {
        int q = partition_low(toSort, left, right, comparison);
        quickSortFP(toSort, left, q-1, comparison);
        quickSortFP(toSort, q + 1, right, comparison);
    }
    return comparison;
}

long* quickSortRP(int toSort[], int left, int right, long *comparison) {
    if(left < right) {
        int q = rand_partition(toSort, left, right, comparison);
        quickSortRP(toSort, left, q - 1, comparison);
        quickSortRP(toSort, q + 1, right, comparison);
    }
    return comparison;
}

void printValues(int toPrint[], int numToPrint) {
    int i, j = 0;
    for (i = 0; i < numToPrint; i++) {
        std::cout << toPrint[i] << "\t";
        j++;
        if (j % 9 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void fillRandomArray(int randomArray[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        randomArray[i] = rand()%1000000;
    } 
}

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n -1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

/* A function that asks for the size of array to be generated, which is then created 
and filled with random values between 0 and 1 000 000, then shuffled at the start of
each loop so that the same sized array can be used for multiple experiments on the 
same size of array. Can be called from any type of input, since it generates its own 
random array. */
void experiments() {
    bool loop = true;
    int eSize;
    std::cout << "What size of array to create: ";
    std::cin >> eSize;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int *eArray = new int[eSize];
    fillRandomArray(eArray, eSize);
    while(loop) {
        shuffle(eArray, eSize); // shuffle the array to reuse.
        std::string type;
        std::cout << "selection-sort (s)   merge-sort (m)   heap-sort (h)   quick-sort-fp (q)\n";
        std::cout << "quick-sort-rp (r)   exit (x)" << std::endl;
        std::cout << "Enter the algorithm for experiment: ";
        std::cin >> type;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (type == "s") {
            selectionSort(eArray, eSize);
        } else if (type == "m") {
            long comparison = 0;
            comparison = *mergeSort(eArray, 0, eSize, &comparison);
            std::cout << "\t #Merge-sort number of comparisons: " << comparison << std::endl;
        } else if (type == "h") {
            long comparison = 0;
            comparison = heapSort(eArray, eSize);
            std::cout << "\t #Heap-sort number of comparisons: " << comparison << std::endl;
        } else if (type == "q") {
            long comparison = 0;
            comparison = *quickSortFP(eArray, 0, eSize, &comparison);
            std::cout << "\t #Quick-sort-fp number of comparisons: " << comparison << std::endl;
        } else if (type == "r") {
            long comparison = 0;
            comparison = *quickSortRP(eArray, 0, eSize, &comparison);
            std::cout << "\t #Quick-sort-rp number of comparisons: " << comparison << std::endl;
        } else if (type == "x") {
            exit(EXIT_SUCCESS);    
        } else {
            std::cout << "Not a valid sorting algorithm." << std::endl;
        }
    }
    std::cout << "returning" << std::endl;
    return;
} // experiments 
