#include "generators.h"
#include "gtest/gtest.h"

// create test for generateVShapedArray
TEST(generators, generateVShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateVShapedArray(arr, n);
  EXPECT_EQ(arr[0], 99);
  EXPECT_EQ(arr[1], 97);
  EXPECT_EQ(arr[n - 1], 98);
  EXPECT_EQ(arr[n - 2], 96);
}
// create test for generateReversedVShapedArray
TEST(generators, generateReversedVShapedArray) {
  int n = 100;
  int arr[n];
  generators::generateReversedVShapedArray(arr, n);
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 3);
  EXPECT_EQ(arr[n - 1], 0);
  EXPECT_EQ(arr[n - 2], 2);
}
// create test for generateConstantArray
TEST(generators, generateConstantArray) {
  int n = 100;
  int arr[n];
  generators::generateConstantArray(arr, n);
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 1);
  EXPECT_EQ(arr[n - 1], 1);
  EXPECT_EQ(arr[n - 2], 1);
}
// create test for generateIncreasingArray
TEST(generators, generateIncreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateIncreasingArray(arr, n);
  EXPECT_EQ(arr[0], 0);
  EXPECT_EQ(arr[1], 1);
  EXPECT_EQ(arr[n - 1], n - 1);
  EXPECT_EQ(arr[n - 2], n - 2);
}
// create test for generateDecreasingArray
TEST(generators, generateDecreasingArray) {
  int n = 100;
  int arr[n];
  generators::generateDecreasingArray(arr, n);
  EXPECT_EQ(arr[0], n - 1);
  EXPECT_EQ(arr[1], n - 2);
  EXPECT_EQ(arr[n - 1], 0);
  EXPECT_EQ(arr[n - 2], 1);
}
