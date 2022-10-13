#include "functions.h"

/**
 * Return: Pointer to an array holding the data
 * Parameters: Pointer to a file that contains the data
 *  Pointer to an array to put the data in
 * Description: Reads the data in from a file and stores it in an array
 */
int* readData(FILE* in, int* size) {
    
    // Takes the first number from the file and stores it in size
    fscanf(in, "%i\n", size);

    // Allocates the correct amount of memory for the array based on size
    int * arr = (int *)malloc(*size * sizeof(int));

    // Populate the array from the file
    for(int i = 0; i < *size; i++) {
        fscanf(in, "%i\n", &arr[i]);
    }

    // Close the file pointer!
    fclose(in);

    // Return the populated array
    return arr;
}

/** 
 * Return: void
 * Parameters: Pointer to array, integer holding size of array
 * Description: Calculates new grades for each student and prints how many students benefit
*/
void determineGrade(int* arr, int size) {
    float ben = 0;
    float benPer;
    
    for(int i = 0; i < size; i++) {
        int x;

        // Check if the grade is high enough to be rounded
        if(arr[i] >= 38) {
            // Calculate difference between grade and next multiple of 5
            x = 5 - (arr[i] % 5);

            // If difference is less than 3, round the grade up
            if(x < 3) {
                arr[i] = arr[i] + x;

                // Add 1 to the number of students who benefit from the policy
                ben++;
            }
        }
    }

    // Calculate percentage of grades rounded
    benPer = ben / size;

    // Print
    printf("%1.0f = %.2f%% of the students benefited from the grading policy change.\n", ben, benPer);
}

/**
 * Return: void
 * Parameters: Size of the array and the array itself
 * Description: Prints the updated grades
 */
void printGrade(int size, int* arr) {
    // This function is pretty much self explanatory
    puts("The new grades are:");

    for(int i = 0; i < size; i++) {
        printf("%i ", arr[i]);
    }

    // For formatting
    puts("");
}

/**
 * Return: void
 * Parameters: number of command line arguments
 * Description: Exits the program if there are too few command line arguments
 */
void checkArguments(int argc) {
    // This is also self explanatory
    if(argc<2) {
        puts("To few command line arguments. Exiting program.");
        exit(1);
    }
}

/**
 * Return: void
 * Parameters: pointer to the input file stream
 * Description: Exits the program if the file did not open correctly
 */
void checkFile(FILE* in) {
    // This one is also self explanatory
    if(in==NULL) {
        puts("The file did not open successfully. Exiting program.");
        exit(1);
    }
}
void calculatePercent(int size, int* arr) {
    int a, b, c, d, f;
    a = b = c = d = f = 0;
    for(int i = 0; i < size; i++) {
        // A: 100 - 85
        if(arr[i] >= 85) {
            a++;
        }

        // B: 84 - 70
        if(arr[i] <= 84 && arr[i] >= 70) {
            b++;
        }

        // C: 69 - 55
        if(arr[i] <= 69 && arr[i] >= 55) {
            c++; // lol c++
        }

        // D: 54 - 40
        if(arr[i] <= 54 && arr[i] >= 40) {
            d++;
        }

        // F: 39 - 0
        if(arr[i] <= 39) {
            // No grades should be below 0.
            f++;
        }
    }

    // Print the graph:
    printf("The following is a graph that represents the grade distribution for each grade category.");
    printf("\nA:");
    printGraph(a);
    printf("\nB:");
    printGraph(b);
    printf("\nC:");
    printGraph(c);
    printf("\nD:");
    printGraph(d);
    printf("\nF:");
    printGraph(f);
    puts("");
}
void printGraph(int p) {
    for(int i = 0; i < p; i++) {
        printf(" *");
    }
}
