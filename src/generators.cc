#include "generators.h"

namespace generators {

// array of uniformly distributied values
void generateRandomArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 10000;
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
// generate array with reversed v shaped values
void generateReversedVShapedArray(int arr[], int n) {
  --n; //  values 1,3..2,0
  for (int i = 0; i <= n; i++)
    if (i % 2 == 0)
      arr[n - (i / 2)] = i;
    else
      arr[i / 2] = i;
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

} // namespace generators
