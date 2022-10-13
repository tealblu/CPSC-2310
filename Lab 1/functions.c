#include "functions.h"
#define TRUE 1
#define FALSE 0

/* Parameters: fp: pointer pointing to the file
*  Return: N/A
*  Description: This function checks to make sure that the file was opened successfully
*/
void checkFile(FILE* fp) {
    // Checks to see if the file pointer points to nothing
    if(fp==NULL) {
        puts("File did not open!!");
        exit(0);
    }
}

/* Parameters: num: number of command line arguments
*  Return: N/A
*  Description: This function checks to make sure there are the appropriate
*    amount of command line arguments for the file to function
*/
void checkArguments(int num) {
    // Checks to see if there are 0 command line arguments
    if(num==1) {
        puts("Not enough command line arguments!!");
        exit(0);
    }
}

/* Parameters: fp: pointer pointing to the file
*  Return: N/A
*  Description: This function tracks the number of unopened brackets in a file
*/
void checkBraces(FILE* fp) {
    int balance=0;
    int totalOpen=0, totalClose=0;
    int prev=FALSE;
    char c;

    // Loop iterates through the file character by character
    while(1) {
        // reading the file
        c = fgetc ( fp ) ;

        // Checks to see if the character is the end of field character, open bracket, or close bracket
        if ( c == EOF ) {
            break;
        } else if(c=='{') {
            balance++;
            totalOpen++;
            prev=TRUE;
        } else if(c=='}') {
            balance--;
            totalClose++;
            if(totalOpen<totalClose && prev==FALSE) {
                puts("Found a '}' closing bracket before an '{' opening bracket!");
            }
            prev=FALSE;
        }
    }

    // Conditional to print the number of unmatched opening brackets.
    // We were not told to print the number of unmatched closing brackets.
    if(balance>0) {
        printf("There were %i unmatched opening brackets.\n", balance);
    } else {
        puts("There were 0 unmatched opening brackets.");
    }
}