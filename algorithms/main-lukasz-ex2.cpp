#include <math.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;

// bubble sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// merge
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
// merge sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

// quick sort
void quickSort(int arr[], int l, int r) {
  if (l < r) {
    int x = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
      if (arr[j] <= x) {
        i++;
        swap(arr[j], arr[i]);
      }
    }
    swap(arr[r], arr[i+1]);
    quickSort(arr, l, i);
    quickSort(arr, i + 2, r);
  }
}

// selection sort
void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    swap(arr[i], arr[min_idx]);
  }
}

// counting sort
void countingSort(int arr[], int n) {
  int output[n];
  int i, max = arr[0];
  for (i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];

  int count[max + 1];
  for (i = 0; i <= max; i++)
    count[i] = 0;

  for (i = 0; i < n; i++)
    count[arr[i]]++;

  for (i = 1; i <= max; i++)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

// shell sort
void shellSort(int arr[], int n) {
  int gap = n / 2;
  while (gap > 0) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = temp;
    }
    gap /= 2;
  }
}

// heapify
void heapify(int arr[], int n, int i) {
  int largest = i;
  int l       = 2 * i + 1;
  int r       = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    int temp     = arr[i];
    arr[i]       = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}
// heap sort
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0],arr[i]);
    heapify(arr, i, 0);
  }
}

// insertionSort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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
//generate constant array
void generateConstantArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = 1;
}
// generate array with v shaped values
void generateVShapedArray(int arr[], int n) {
  --n; // values 99,97..96,98
  for (int i = 0; i <= n; i++)
    if (i % 2 == 0)
      arr[i/2] = n-i;
    else
      arr[n-(i/2)] = n-i;
}
// generate array with reversed v shaped values
void generateReversedVShapedArray(int arr[], int n) {
  --n; // values 99,97..96,98
  for (int i = 0; i <= n; i++)
    if (i % 2 == 0)
      arr[n-(i/2)] = i;
    else
      arr[i/2] = i;
}
// print array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
// select from sorting algorithms programatically
void selectSortingAlgorithm(int arr[], int n, int choice) {
  switch (choice) {
  case 1:
    insertionSort(arr, n);
    break;
  case 2:
    bubbleSort(arr, n);
    break;
  case 3:
    selectionSort(arr, n);
    break;
  case 4:
    mergeSort(arr, 0, n - 1);
    break;
  case 5:
    quickSort(arr, 0, n - 1);
    break;
  case 6:
    heapSort(arr, n);
    break;
  case 7:
    countingSort(arr, n);
    break;
  case 8:
    shellSort(arr, n);
    break;
  default:
    printf("Invalid choice\n");
  }
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
/*
 void tests(){
  int n=21;
   for(int i = 1; i<=6; i++){
     int arr[n];
     for(int j = 1; j<=8; j++){
         selectGenerationAlgorithm(arr, n, i);
        selectSortingAlgorithm(arr,n,j);
        printf("G:%d S:%d is ", i,j); printArray(arr, n);
     }
   }
 }*/
int main(int argc, char const *argv[]) {

  //tests();

  // first exercise
  int n = 100000;
  int steps = 20;
  int algos = 4;
  float result_array[algos*steps];
  float result_array_ch[algos*steps];
  int ex1Array[] = {2,6,7,8};

  for (int i = 0; i < algos; i++) {
    for (int j = 1; j <= steps; j++) {
      int arrsize = n*j;
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
      //freopen ("ex1-results.csv","a",stdout);
      //printf("%d,%d,%f\n", ex1Array[i], arrsize, time_taken);
      //fclose(stdout);

      // measure time with chrono
      generateRandomArray(arr, arrsize);
      auto start_ch = chrono::high_resolution_clock::now();
      selectSortingAlgorithm(arr, arrsize, ex1Array[i]);
      auto end_ch = chrono::high_resolution_clock::now();
      double time_taken_ch = chrono::duration_cast<chrono::nanoseconds>(end_ch - start_ch).count()*1e-9;
      freopen("CON","w",stdout);
      printf("Chrono %d,%d,%f\n", ex1Array[i], arrsize, time_taken_ch);
      freopen ("ex1-results-ch.csv","a",stdout);
      printf("%d,%d,%f\n", ex1Array[i], arrsize, time_taken_ch);
      fclose(stdout);
    }
  }
  // first exercise
  steps = 20;
  algos = 3;
  int generators = 6;
  float result_array2[algos*steps];
  float result_array_ch2[algos*steps];
  int ex2Array[] = {5,6,4};
  int gen2Array[] = {1,6,2,3,5,4};

  for (int r = 0; r < generators; r++){
      for (int i = 0; i < algos; i++) {
        for (int j = 1; j <= steps; j++) {
            int arrsize = n*j;
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
            //freopen ("ex1-results.csv","a",stdout);
            //printf("%d,%d,%d,%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken_ch);
            //fclose(stdout);

            // measure time with chrono
            generateRandomArray(arr, arrsize);
            auto start_ch = chrono::high_resolution_clock::now();
            selectSortingAlgorithm(arr, arrsize, ex2Array[i]);
            auto end_ch = chrono::high_resolution_clock::now();
            double time_taken_ch = chrono::duration_cast<chrono::nanoseconds>(end_ch - start_ch).count()*1e-9;
            freopen("CON","w",stdout);
            printf("Chrono G:%d, S:%d, N:%d T:%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken_ch);
            freopen ("ex2-results-ch.csv","a",stdout);
            printf("%d,%d,%d,%f\n", gen2Array[r], ex2Array[i], arrsize, time_taken_ch);
            fclose(stdout);
        }
    }
  }
  return 0;
}
