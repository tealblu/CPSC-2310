/*  Charlie Hartsell
    CPSC 2310, Spring 2021
    Dr. Yvon Feaster
    Calculating the Diagonal */

#include "diagonal.h"

// Reads the data from a file. Returns a 2d array of ints, stored as int**
int** readData(FILE* fp, int* size) {
    fscanf(fp, "%d\n", size);

    // Dynamically declare a 2d array of ints
    int** mat = (int **)malloc(*size * sizeof(int**));
    for(int i = 0; i < *size; i++) {
        mat[i] = (int *)malloc(*size * sizeof(int*));
    }

    // loop through the file
    for(int i = 0; i < *size; i++) {
        for(int j = 0; j < *size; j++) {
            fscanf(fp, "%d", &mat[i][j]);
        }
    }

    return mat;
}

// Calculates absolute sum of diagonal and prints to stdout
void calculateDiagonal(int sz, int** mat) {
    int left = 0;
    int right = 0;

    // left diagonal
    int j = 0;
    for(int i = 0; i < sz; i++) {
        left += mat[i][j];
        j++;
    }

    // print left result
    printf("left:%i\n", abs(left));

    // right diagonal
    j = 1;
    for(int i = 0; i < sz; i++) {
        right += mat[i][sz - j];
        j++;
    }

    // print right result
    printf("right:%i\n", abs(right));
}