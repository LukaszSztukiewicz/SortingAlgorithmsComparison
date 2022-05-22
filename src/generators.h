#ifndef GENERATORS_H
#define GENERATORS_H

#include <algorithm>
#include <stdio.h>
namespace generators {
void generateRandomArray(int arr[], int n);
void generateIncreasingArray(int arr[], int n);
void generateDecreasingArray(int arr[], int n);
void generateConstantArray(int arr[], int n);
void generateVShapedArray(int arr[], int n);
void generateReversedVShapedArray(int arr[], int n);
} // namespace generators
#endif // GENERATORS_H
