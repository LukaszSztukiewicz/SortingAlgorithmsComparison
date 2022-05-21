#include "utils.h"

namespace utils {

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

double measureTimeOfFunction(std::function<int *(int *, int)> f, int arr[], int n) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  double cpu_time_used;
  f(arr, n);
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
  return cpu_time_used;
}

} // namespace utils
