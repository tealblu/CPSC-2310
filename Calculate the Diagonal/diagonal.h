/*  Charlie Hartsell
    CPSC 2310, Spring 2021
    Dr. Yvon Feaster
    Calculating the Diagonal */

#ifndef DIAGONAL_H
#define DIAGONAL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// Reads the data from a file. Returns a 2d array of ints, stored as int**
int** readData(FILE* fp, int* size);

// Calculates absolute sum of diagonal and prints to stdout
void calculateDiagonal(int sz, int** mat);

#endif