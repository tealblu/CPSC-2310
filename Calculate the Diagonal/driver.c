/*  Charlie Hartsell
    CPSC 2310, Spring 2021
    Dr. Yvon Feaster
    Calculating the Diagonal */

#include "diagonal.h"

int main(int argc, char* argv[])
{
  FILE * in = fopen(argv[1], "r");
  assert(in != NULL);
  int sz = 0;
  int **data = readData(in, &sz);
  assert(data != NULL);
  calculateDiagonal(sz, data);

  return 0;
}
