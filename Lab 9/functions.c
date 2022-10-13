/*
Charlie Hartsell
CPSC 2311 Sec 002
Lab 9
April 1, 2021
*/

#include "functions.h"

/* 
 * absValue - returns the absolute value of x
 *   Example: absValue(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absValue(int i) {
    int mask = i >> 31; // Mask = integer right shifted by 31 to determine whether number is neg or pos
    i = i ^ mask; // XOR i and mask
    i = i - mask; // Subtract mask
    return i;
}


/* 
 * binaryAnd - x&y using only ~ and | 
 *   Example: binaryAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int binaryAnd(int a, int b) {
    // Algorithm: a & b = ~a NOR ~b
    // NOR = ~(a | b)
    // So we ~ the ints and then NOR them
    a = ~a;
    b = ~b;
    return ~(a | b);
}

/* 
 * binaryNotOr - ~(x|y) using only ~ and & 
 *   Example: binaryNotOr(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 */
int binaryNotOr(int a, int b) {
    return (~a & ~b);
}

/* 
 * binaryOr - x|y using only ~ and & 
 *   Example: binaryOr(6, 5) = 7
 *   Legal ops: ~ &
 */
int binaryOr(int a, int b) {
    // a or b = ~a nand ~b
    return ~(~a & ~b);
}

/* 
 * binaryXor - x^y using only ~ and & 
 *   Example: binaryXor(4, 5) = 1
 *   Legal ops: ~ &
 */
int binaryXor(int a, int b) {
    // a xor b = (~a nor ~b) nor (a nor b)
    // where nor = ~a & ~b
    // so a xor b = ~(a & b) & ~(~a & ~b)
    return ~(a&b) & ~(~a & ~b);
}

/*
 * unsignedAddOk - determines if two unsigned int's can be added
 * without an overflow
 * Legal ops: all
 */

int unsignedAddOK(unsigned a, unsigned b) {
    // This said all operators are legal so I'm assuming we can use if/else statements?
    // We were told we could use any operators listed in the "legal ops" section
    // And the legal ops section here says we can do whatever we want
    
    int result = a + b;
    
    if(result < 0) {
        // Overflow detected, return false
        return 0;
    } else {
        // Overflow not detected, ok to add
        return 1;
    }
}

/*
 * twosAddOk - determines if two int's can be added
 * without an overflow
 * Legal ops: all
 */

int twosAddOk(int a, int b) {
    // This said all operators are legal so I'm assuming we can use if/else statements?
    // We were told we could use any operators listed in the "legal ops" section
    // And the legal ops section here says we can do whatever we want
    if(a > 0 && b > 0 && (a+b) < 0) {
        // Overflow detected, return false
        return 0;
    } else if(a < 0 && b < 0 && (a+b) > 0) {
        // Overflow detected return false
        return 0;
    } else {
        // Overflow not detected, ok to add
        return 1;
    }
}


/*
 *  int twosSubOk - Determine whether arguments can be subracted 
 *  without overflow
 *  Legal ops: all
 */

int twosSubtractOK(int a, int b) {
    /* Subtraction can be expressed as the addition of the complement of a number.
    So, we take the complement of one of the numbers, find the signs of all numbers,
    and make sure they make sense. */
    int result = a + (1 + ~b); // dif is x - y
    return (!((a >> 31) ^ (b >> 31)) | !((result >> 31) ^ (a >> 31)));
}