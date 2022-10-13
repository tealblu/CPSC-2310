/*
 *Charlie Hartsell
 *CPSC2310 Spring 2021
 *UserName: ckharts
 *Instructor:  Dr. Yvon Feaster
*/

#ifndef MACRO_H
#define MACRO_H

#include <stdio.h>
#include <stdlib.h>

// Defining macros
#define MAX(a,b) a>b? a : b
#define MIN(a,b) a<b? a : b
#define ABS(x) x<0 ? x*(-1) : x
#define LARGEST(a,b,c) a>b ? a>c ? a : c : b>c ? b : c
#define SMALLEST(a,b,c) a<b ? a<c ? a : c : b<c ? b : c 
#define DEBUG_FPRINT printf("In File %s line %i\n", __FILE__, __LINE__);
#define ISEVEN_ODD(x) (x%2)==0 ? printf("%i is Even\n", x) : printf("%i is Odd\n", x)
#define MALLOC(x,t) malloc((x)*sizeof(t));
#define Add_to_Sum(sum_number, value) sum ## sum_number += value

int printReturn( int a, int b, int action);

#endif