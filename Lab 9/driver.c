/*
Charlie Hartsell
CPSC 2311 Sec 002
Lab 9
April 1, 2021
*/

#include "functions.h"

int main(void) {
    // Test absValue
    assert(50 == absValue(-50));
    assert(10 == absValue(10));

    // test binaryAnd
    assert(0 == binaryAnd(1, 0));
    assert(1 == binaryAnd(1,1));

    // test binaryNotOr
    assert((~(10 | 10)) == binaryNotOr(10, 10));
    assert((~(123 | 321)) == binaryNotOr(123, 321));
    
    // test binaryOr
    assert((10 | 10) == binaryOr(10, 10));
    assert((15 | 16) == binaryOr(15, 16));

    // test binaryXor
    assert((100 ^ 100) == binaryXor(100, 100));
    assert((3 ^ 10) == binaryXor(3,10));

    // test unsignedAddOk
    assert(0 == unsignedAddOK(4294967295, 4294967295));
    assert(1 == unsignedAddOK(1, 1));

    // test twosAddOk
    assert(0 == twosAddOk(2147483647, 2147483647));
    assert(0 == twosAddOk(-2147483647, -2147483647));
    assert(1 == twosAddOk(1, 1));

    // test twosSubtractOk
    assert(0 == twosSubtractOK(-2147483647, 2147483647));
    assert(1 == twosSubtractOK(10, 11));
    assert(1 == twosSubtractOK(9, 56));
    assert(1 == twosSubtractOK(-1, -34));

    puts("If this prints, then everything works ok! :)");
    
    return 0;
}