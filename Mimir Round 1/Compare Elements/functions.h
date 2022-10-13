#ifndef FUNCTIONS
#define FUNCTIONS

#include <stdio.h>
#include <stdlib.h>

int readSize(FILE* fp);
void readData(FILE* fp, int, int*, int*);
int* allocateMemory(int sz);
int* compareElements(int sz, int* arr1, int* arr2);

#endif