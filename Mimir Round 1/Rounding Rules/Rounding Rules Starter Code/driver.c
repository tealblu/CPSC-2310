int main(int argc, char* argv[])
{
  int size = 0;
  checkArguments(argc);
  FILE* in =fopen(argv[1], "r");
  checkFile(in);
  int* arr = readData(in, &size);
  determineGrade(arr, size);
  printGrade(size, arr);
  calculatePercent(size, arr);

  return 0;
}
