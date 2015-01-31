#include <stdlib.h>
#include <time.h>

void intgen(int n, int min, int max, int *arr) {
  srand((unsigned)time(0));

  for (int i = 0; i < n; i++) {
    *arr++ = min + (rand() % (max - min) + 1);
  }
}

void printints(int *arr, int n) {
  printf("{");

  for (int i = 0; i < n - 1; i++) {
    printf("%i, ", *arr++);
  }

  printf("%i", *arr);
  printf("}\n");
}
