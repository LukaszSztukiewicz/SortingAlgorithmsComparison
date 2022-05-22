#include "utils.h"

namespace utils {

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

double measureTimeOfFunction(std::function<int *(int *, int)> f, int arr[], int n) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  f(arr, n);
  // LOG array
  utils::printArray(arr, 10);
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
  return time_taken_ch;
}

} // namespace utils
