#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <iterator>
#include <vector>
#include "Sorting.h"
    
/* Main function that takes the file name and creates a vector to be pushed to an array
that will be passed to each function as called. */
int main (int argc, char *argv[]) {

    int num;
    std::vector<int> initVals;

    if (argc != 2) {
        std::cout << "Usage: ./main [inputfile.txt]" << std::endl;
        return 1;
    }

    if (strcmp(argv[1], "ordered.txt") == 0 || strcmp(argv[1], "random.txt") == 0 || 
    strcmp(argv[1], "reverse.txt") == 0) {
        std::string filename = argv[1];
        std::ifstream File(filename.c_str());
        while(File>>num) {
            initVals.push_back(num);
        }
    } else {
        std::cout << "Please enter ./main [ordered.txt || random.txt || reverse.txt]"
        << std::endl;
        return 1;
    }

    int toSort[10000];
    for (int i = 0; i < 10000; i++) {
        toSort[i] = initVals.at(i);
    }

    std::string type;
    std::cout << "selection-sort (s)   merge-sort (m)   heap-sort (h)   quick-sort-fp (q)\n";
    std::cout << "quick-sort-rp (r)   experimental (e)" << std::endl;
    std::cout << "Enter the algorithm: ";
    std::cin >> type;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (type == "s") {
        selectionSort(toSort);
    } else if (type == "m") {
        long comparison = 0;
        comparison = comparison + mergeSort(toSort, 0, 10000);
        std::cout << "1 2 3 4 5 ... " << toSort[9999] << std::endl;
        std::cout << "\t #Merge-sort number of comparisons: " << comparison << std::endl;
    } else if (type == "h") {
        long comparison = 0;
        comparison = heapSort(toSort, 10000);
        std::cout << "1 2 3 4 5 ... " << toSort[9999] << std::endl;
        std::cout << "\t #Heap-sort number of comparisons: " << comparison << std::endl;
    } else if (type == "q") {
        long comparison = 0;
        comparison = quickSortFP(toSort, 0, 10000);
        std::cout << "1 2 3 4 5 ... " << toSort[9999] << std::endl;
        std::cout << "\t #Quick-sort-fp number of comparisons: " << comparison << std::endl;
    } else if (type == "r") {
        long comparison = 0;
        comparison = quickSortRP(toSort, 0, 10000);
        std::cout << "1 2 3 4 5 ... " << toSort[9999] << std::endl;
        std::cout << "\t #Quick-sort-rp number of comparisons: " << comparison << std::endl;
    } else if (type == "e") {
        experiments(toSort);
    } else {
        std::cout << "Not a valid sorting algorithm." << std::endl;
    }

    return 0;
} // main