#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

#include <algorithm>
#include <stdio.h>

namespace sorting_algos {

int *bubbleSort(int arr[], int n);
int *mergeSort(int arr[], int n);
int *quickSort(int arr[], int n); // TODO middle selected
int *selectionSort(int arr[], int n);
int *insertionSort(int arr[], int n);
int *heapSort(int arr[], int n);
int *shellSort(int arr[], int n);
int *countingSort(int arr[], int n);

} // namespace sorting_algos

#endif // SORTING_ALGOS_H