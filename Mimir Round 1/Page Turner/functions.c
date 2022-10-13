#include "functions.h"

/**
 * Return: N/A
 * Parameters: Size of the book and the target page
 * Description: Using the size of the book and the target page, this
 * function calculates the most efficient number of page turns
 * to arrive at said target.
 */
void howManyTurns(int size, int page) {
    int middle = size / 2;
    int turns;
    int backwards = 0;

    if(page==1 || page==size) {
        turns = 0;
    } else {
        // Check to see if page is odd
        if(page % 2 != 0) {
            // Page is odd, make it even
            page = page - 1;
        } 
        // Is page to the right or the left of the middle?
        if(page > middle) {
            turns = (size - page) / 2;
            backwards = 1;
        } else if(page < middle) {
            turns = page / 2;
        } else if(page==middle) {
            turns = page / 2;
        }
    }

    if(backwards != 1) {
        // Turn from the front
        if(turns==1) {
            printf("1 page from the front\n");
        } else {
            printf("%i pages from the front\n", turns);
        }
    } else {
        if(turns==1) {
            printf("1 page from the back\n");
        } else {
            printf("%i pages from the back\n", turns);
        }
    }


}

/**
 * Return: N/A
 * Parameters: File pointer, pointer to total pages, pointer to desired page
 * Description: This function reads in the data from the specified file
 */
void readData(FILE* in, int* totalPages, int* desiredPage) {

    // Read the data
    fscanf(in, "%d\n%d", totalPages, desiredPage);

    checkData(*totalPages, *desiredPage);
}

/**
 * Return: N/A
 * Parameters: Values of total pages and desired pages
 * Description: Verifies that the desired page is actually inside the book
*/
void checkData(int totalPages, int desiredPage)
{
    if(totalPages < desiredPage) {
        puts("The total pages in the book is smaller than the page you are looking for! Exiting the program!");
        exit(1);
    }
}
