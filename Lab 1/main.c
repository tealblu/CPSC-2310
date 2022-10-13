#include "functions.h"

int main(int argc, char *argv[])
{
    checkArguments(argc);
    FILE* file = fopen(argv[1], "r");
    checkFile(file);
    checkBraces(file);

    return 0;
}
