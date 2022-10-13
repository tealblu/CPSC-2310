#include "functions.h"

int main(int argc, char* argv[])
{
	int totalPages, desiredPage;

	if(argc<2) {
		puts("Not enough command line arguments! Exiting the program!");
		exit(1);
	}

	// Opening the file
	FILE * fp = fopen(argv[1], "r");
	if(fp == NULL) {
		puts("File did not open successfully! Exiting the program!");
		exit(1);
	}

	// Loading the data
	readData(fp, &totalPages, &desiredPage);

	howManyTurns(totalPages, desiredPage);

	return 0;
}
