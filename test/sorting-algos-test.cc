#include "generators.h"
#include "sorting-algos.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(bubbleSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::bubbleSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(bubbleSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::bubbleSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(bubbleSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::bubbleSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for merge sort
TEST(mergeSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::mergeSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(mergeSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::mergeSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(mergeSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::mergeSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for quick sort
TEST(quickSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::quickSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(quickSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::quickSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(quickSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::quickSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for selection sort
TEST(selectionSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::selectionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(selectionSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::selectionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(selectionSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::selectionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for insertion sort
TEST(insertionSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::insertionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(insertionSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::insertionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(insertionSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::insertionSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for heap sort
TEST(heapSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::heapSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(heapSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::heapSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(heapSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::heapSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for shell sort
TEST(shellSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::shellSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(shellSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::shellSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(shellSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::shellSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
// create tests for counting sort
TEST(countingSort, randomArray) {
  int n = 100;
  int arr[n];
  generators::generateRandomArray(arr, n);
  sorting_algos::countingSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(countingSort, vShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  sorting_algos::countingSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
TEST(countingSort, decreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  sorting_algos::countingSort(arr, n);
  EXPECT_EQ(std::is_sorted(arr, arr + n), true);
}
