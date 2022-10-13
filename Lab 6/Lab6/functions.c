/*
 *Charlie Hartsell
 *CPSC2310 Spring 2021
 *UserName: ckharts
 *Instructor:  Dr. Yvon Feaster
*/

#include "functions.h"

int printReturn( int a, int b, int action) {
    // Idk what to comment, she literally just told us to throw this code in here and run it
    // Action tells the function what to check, and then it returns the value of the chosen statement
    // Kind of like a switch statement
    return action == 1 ? a==b
    : action == 2 ? a < b
    : action == 3 ? a > b
    : -50000;
}
