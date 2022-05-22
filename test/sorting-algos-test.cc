#include "generators.cc"
#include "sorting-algos.cc"
#include "gtest/gtest.h"
#include <algorithm>

TEST(bubbleSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  bubbleSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(bubbleSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  bubbleSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(bubbleSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  bubbleSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for merge sort
TEST(mergeSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  mergeSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(mergeSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  mergeSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(mergeSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  mergeSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for quick sort
TEST(quickSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  quickSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(quickSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  quickSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(quickSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  quickSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for selection sort
TEST(selectionSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  selectionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(selectionSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  selectionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(selectionSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  selectionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for insertion sort
TEST(insertionSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  insertionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(insertionSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  insertionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(insertionSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  insertionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for heap sort
TEST(heapSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  heapSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(heapSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  heapSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(heapSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  heapSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for shell sort
TEST(shellSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  shellSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(shellSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  shellSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(shellSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  shellSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for counting sort
TEST(countingSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  countingSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(countingSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  countingSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(countingSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  countingSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
