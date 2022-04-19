Jacob Reiser
jpreiser@uga.edu
810 687 011

To compile the code, type 'make' into the command line.

To run, type './main <input file>' into the command line.

To clean the directory, type 'make clean' in the command line.

The program runs with input names of 'ordered.txt', 'random.txt', and 'reverse.txt'.
To customize input, modify these files directly or replace them with files of the same name.
These files and this program assumes inputs of size 10,000 or less, while the experimental
section can create arrays of up to 1,000,000. There is a bug with merge sort that prevents
it from going above 10000 that I ran out of time to fix. 

The experimental section is implemented within the main function. To access this 
mode, type 'e' for the algorithm type. Once in this experimental mode, the user will be 
prompted for an array size. This size will be used to initialize an array of that size
full of random ints between 0 and 1,000,000. This experimental mode loops and shuffles
the array after each sort using the Fisher-Yates shuffle so that the same size can be used
for various sort methods. Once the array size has been specified, the program operates the
same as the main function, with the looping to allow for multiple iterations of the same 
sorting algorithm or all algorithms of the same size. To exit this experimental mode, type
'x' as the algorithm type.

The accompanying report is submitted on eLc. 

Code for sorting alogrithms taken from class slides, geeksforgeeks.com, and progamiz.com