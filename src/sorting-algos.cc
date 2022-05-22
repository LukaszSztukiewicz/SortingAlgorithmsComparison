#include "sorting-algos.h"

namespace sorting_algos {

int *bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
  return arr;
}

int *merge(int arr[], int l, int m, int r) {
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
  return arr;
}

int *mergeSortFunction(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSortFunction(arr, l, m);
    mergeSortFunction(arr, m + 1, r);
    merge(arr, l, m, r);
  }
  return arr;
}

int *mergeSort(int arr[], int n) {
  return mergeSortFunction(arr, 0, n - 1);
}

int *quickSortFunction(int arr[], int l, int r) {
  if (l < r) {
    int x = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
      if (arr[j] <= x) {
        i++;
        std::swap(arr[j], arr[i]);
      }
    }
    std::swap(arr[r], arr[i + 1]);
    quickSortFunction(arr, l, i);
    quickSortFunction(arr, i + 2, r);
  }
  return arr;
}

int *quickSort(int arr[], int n) {
  return quickSortFunction(arr, 0, n - 1);
}

int *selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    std::swap(arr[i], arr[min_idx]);
  }
  return arr;
}

int *countingSort(int arr[], int n) {
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

  return arr;
}

int *shellSort(int arr[], int n) {
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
  return arr;
}

int *heapify(int arr[], int n, int i) {
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
  return arr;
}

int *heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int *insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j   = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j          = j - 1;
    }
    arr[j + 1] = key;
  }
  return arr;
}
} // namespace sorting_algos