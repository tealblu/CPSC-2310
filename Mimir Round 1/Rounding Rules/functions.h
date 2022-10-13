#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

int* readData(FILE*, int*);
void determineGrade(int* , int);
void printGrade(int, int* );
void checkArguments(int);
void checkFile(FILE*);
void calculatePercent(int, int*);
void printGraph(int);

#endif