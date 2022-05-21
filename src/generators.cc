#include "generators.h"

namespace generators {

// array of uniformly distributied values
void generateRandomArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = rand() % n;
}
// generate array with increasing values
void generateIncreasingArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = i;
}
// generate array with decreasing values
void generateDecreasingArray(int arr[], int n) {
  --n; // 99..0
  for (int i = 0; i <= n; i++)
    arr[i] = n - i;
}
// generate constant array
void generateConstantArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = 1;
}
// generate array with v shaped values
void generateVShapedArray(int arr[], int n) {
  --n; // values 99,97..96,98
  for (int i = 0; i <= n; i++)
    if (i % 2 == 0)
      arr[i / 2] = n - i;
    else
      arr[n - (i / 2)] = n - i;
}
// generate array with reversed v shaped values
void generateReversedVShapedArray(int arr[], int n) {
  --n; // values 99,97..96,98
  for (int i = 0; i <= n; i++)
    if (i % 2 == 0)
      arr[n - (i / 2)] = i;
    else
      arr[i / 2] = i;
}

// select generation function programatically
void selectGenerationAlgorithm(int arr[], int n, int choice) {
  switch (choice) {
  case 1:
    generateRandomArray(arr, n);
    break;
  case 2:
    generateIncreasingArray(arr, n);
    break;
  case 3:
    generateDecreasingArray(arr, n);
    break;
  case 4:
    generateVShapedArray(arr, n);
    break;
  case 5:
    generateReversedVShapedArray(arr, n);
    break;
  case 6:
    generateConstantArray(arr, n);
    break;
  default:
    printf("Invalid choice\n");
  }
}
} // namespace generators
