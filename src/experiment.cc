#include "experiment.h"
#include "sorting-algos.cc"

namespace experiment {

void speedComparison() {
  std::vector<std::function<int *(int *, int)>> sorting_algorithms_1 = {
      sorting_algos::bubbleSort,
      sorting_algos::heapSort,
      sorting_algos::countingSort,
      sorting_algos::shellSort};
}

void main() {

  std::string names[] = {"bubbleSort", "insertionSort"};
  int array_sizes[]   = {10, 100, 1000, 10000, 100000, 1000000};
  sorting_algo[1](array_sizes, 6);
}
int main(int argc, char const *argv[]) {

  // tests();

  // first exercise
  int n     = 100000;
  int steps = 20;
  int algos = 4;
  float result_array[algos * steps];
  float result_array_ch[algos * steps];
  int ex1Array[] = {2, 6, 7, 8};

  for (int i = 0; i < algos; i++) {
    for (int j = 1; j <= steps; j++) {
      int arrsize = n * j;
      int arr[arrsize];

      // measure time
      /*
      generateRandomArray(arr, arrsize);
      clock_t start = clock();
      selectSortingAlgorithm(arr, n, ex1Array[i]);
      clock_t end       = clock();
      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
      printf("Clock %d,%d,%f\n", ex1Array[i], arrsize, time_taken);
      */
      // freopen ("ex1-results.csv","a",stdout);
      // printf("%d,%d,%f\n", ex1Array[i], arrsize, time_taken);
      // fclose(stdout);

      // measure time with chrono
      generateRandomArray(arr, arrsize);
      auto start_ch = chrono::high_resolution_clock::now();
      selectSortingAlgorithm(arr, arrsize, ex1Array[i]);
      auto end_ch          = chrono::high_resolution_clock::now();
      double time_taken_ch = chrono::duration_cast<chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
      freopen("CON", "w", stdout);
      printf("Chrono %d,%d,%f\n", ex1Array[i], arrsize, time_taken_ch);
      freopen("ex1-results-ch.csv", "a", stdout);
      printf("%d,%d,%f\n", ex1Array[i], arrsize, time_taken_ch);
      fclose(stdout);
    }
  }
  // first exercise
  steps          = 20;
  algos          = 3;
  int generators = 6;
  float result_array2[algos * steps];
  float result_array_ch2[algos * steps];
  int ex2Array[]  = {5, 6, 4};
  int gen2Array[] = {1, 6, 2, 3, 5, 4};

  for (int r = 0; r < generators; r++) {
    for (int i = 0; i < algos; i++) {
      for (int j = 1; j <= steps; j++) {
        int arrsize = n * j;
        int arr[arrsize];

        // measure time
        /*
        selectGenerationAlgorithm(arr, arrsize, gen2Array[r]);
        clock_t start = clock();
        selectSortingAlgorithm(arr, n, ex2Array[i]);
        clock_t end       = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        printf("Clock G:%d, S:%d, N:%d T:%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken);
        */
        // freopen ("ex1-results.csv","a",stdout);
        // printf("%d,%d,%d,%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken_ch);
        // fclose(stdout);

        // measure time with chrono
        generateRandomArray(arr, arrsize);
        auto start_ch = chrono::high_resolution_clock::now();
        selectSortingAlgorithm(arr, arrsize, ex2Array[i]);
        auto end_ch          = chrono::high_resolution_clock::now();
        double time_taken_ch = chrono::duration_cast<chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
        freopen("CON", "w", stdout);
        printf("Chrono G:%d, S:%d, N:%d T:%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken_ch);
        freopen("ex2-results-ch.csv", "a", stdout);
        printf("%d,%d,%d,%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken_ch);
        fclose(stdout);
      }
    }
  }
  return 0;
}
