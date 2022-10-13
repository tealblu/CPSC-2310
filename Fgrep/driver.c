/*  CPSC 2311
    Charlie Hartsell
    ckharts@clemson.edu
    Fgrep mimir assignment 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char* fileName, FILE* fp, char* str) {
    char temp[200];
    
    // While loop to go line by line through file
    while(!feof(fp)) {
        // Store the current line in temp
        fgets(temp, 200, fp);

        // Use strstr to determine if str is in temp
        if(strstr(temp, str) != NULL) {
            printf("%s:", fileName);
            fputs(temp, stdout);
        }
    }

    // Insert a newline. Just for formatting.
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Verify the correct number of command line arguments are being used
    if(argc != 4) {
        fprintf(stderr, "Usage: executable string file ...\n");
        exit(1);
    }
    
    // Start the loop
    for(int i = 2; i <= 3; i++) {
        // Open the file pointer
        FILE* fp = fopen(argv[i], "r");

        // Verify the file pointer opened correctly before calling search
        if(fp == NULL) {
            // File pointer opened incorrectly
            perror(argv[i]);
        } else {
            // File pointer opened correctly, call search
            search(argv[i], fp, argv[1]);

            // Close the file pointer
            fclose(fp);
        }
    }

    return 0;
}