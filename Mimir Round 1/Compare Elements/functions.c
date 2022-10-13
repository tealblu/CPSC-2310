#include "functions.h"

/**
 * Return: integer representing the length of each array
 * Parameters: fp - a pointer to the file that contains the arrays
 * Description: this function reads the first char of the file, which contains
 * the size of the arrays. It then converts this char into an int, which
 * is subsequently returned.
*/
int readSize(FILE* fp) {
    int sz;

    // Take the first int from the file and save it into sz
    fscanf(fp, "%i\n", &sz);

    return sz;
}

/**
 * Return: n/a
 * Parameters:
 *  fp - pointer to file stream
 *  sz - size of each array
 *  arr1 - pointer to first array
 *  arr2 - pointer to second array
 * Description: Reads the data from file and stores it in the correct arrays
 */
void readData(FILE* fp, int sz, int* arr1, int* arr2) {
    // Populate the first array
    for(int i = 0; i < sz; i++) {
        fscanf(fp, "%i ", &arr1[i]);
    }

    // Populate the second array
    for(int i = 0; i < sz; i++) {
        fscanf(fp, "%i ", &arr2[i]);
    }
}

/**
 * Return: pointer to the allocated array
 * Parameters: sz - the size of the array to allocate
 * Description: This function makes sure the correct amt of memory is allocated
 * for each array
 */
int* allocateMemory(int sz) {
    // Self explanatory
    int *arr = (int *)malloc(sz * sizeof(int));

    return arr;
}

/**
 * Return: pointer to the array containing point tallies
 * Parameters:
 *  sz - size of the arrays
 *  arr1 - first array containing numbers
 *  arr2 - second array containing numbers
 * Description: Tallies points for warrays
 */
int* compareElements(int sz, int* arr1, int* arr2) {
    // Create the point container and initialize to 0
    int *compare = (int *)malloc(2 * sizeof(int));
    compare[0] = compare[1] = 0;

    // Tally the points by iterating through each array
    for(int i = 0; i < sz; i++) {
        if(arr1[i] > arr2[i]) {
            // Array 1 element is greater, add point
            compare[0]++;
        } else if(arr2[i] > arr1[i]) {
            // Array 2 element is greater, add point
            compare[1]++;
        } else {
            // Items are equal, do nothing
        }
    }

    return compare;
}
