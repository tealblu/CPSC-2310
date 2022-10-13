/*
 *Charlie Hartsell
 *CPSC2310 Spring 2021
 *UserName: ckharts
 *Instructor:  Dr. Yvon Feaster
*/


#include "functions.h"

int main(void) {
    puts("TEST PROGRAM FOR CUSTOM MACROS BEGINNING NOW...");
    // test case for malloc macro
    puts("Beginning malloc macro test:");
    int * ptr = NULL;
    ptr = MALLOC(5, ptr)
    if(ptr!=NULL) {
        printf("The address of num is: 0x%x\n", &ptr);
    }
    free(ptr);

    // Other test cases, as required
    printf("MAX of 10 and 20 is %i\n", MAX(10,20));
    printf("MIN of 16 and 53 is %i\n", MIN(16,53));
    printf("ABS of -53 is %i\n", ABS(-53));
    printf("LARGEST of 5 3 and 6 is %i\n", LARGEST(5,3,6));
    printf("SMALLEST of 29 53 and 12 is %i\n", SMALLEST(29,53,12));
    puts("The following statement is the result of DEBUG_FPRINT:");
    DEBUG_FPRINT;
    puts("ISEVEN_ODD with 15 and 16:");
    ISEVEN_ODD(15);
    ISEVEN_ODD(16);
    // Malloc test would go here but it has already been done
    // sum test:
    int sum1 = 1;
    Add_to_Sum(1,15);
    printf("Add_to_Sum: %i\n", sum1);
    // printReturn tests:
    puts("printReturn tests with actions 1-4, a=5, b=6");
    printReturn(5,6,1);
    printReturn(5,6,2);
    printReturn(5,6,3);
    printReturn(5,6,4);

    return 0;
}
