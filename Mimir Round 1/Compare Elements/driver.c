#include "functions.h"

int main(int argc, char* argv[]) {
    // Declare variables
    int sz;
    int *compare;
    FILE * fp;

    // Open the file and check for validity
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        puts("The input file failed to open! Exiting the program!");
        exit(1);
    }

    // Read the size from the file
    sz = readSize(fp);

    // Allocate memory for the arrays
    int *arr1 = allocateMemory(sz);
    int *arr2 = allocateMemory(sz);

    // Read the data into the arrays
    readData(fp, sz, arr1, arr2);

    // Tally the points
    compare = compareElements(sz, arr1, arr2);

    // Print the results
    printf("%i %i\n", compare[0], compare[1]);
}
