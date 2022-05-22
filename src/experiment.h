#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

void speedComparison(int n, int steps, std::string outputFile,
                     std::vector<std::function<int *(int *, int)>> sorting_algorithms,
                     std::vector<std::string> sorting_algorithms_names);

void effectivenessComparison(int n, int steps, std::string outputFile,
                             std::vector<std::function<int *(int *, int)>> sorting_algorithms,
                             std::vector<std::string> sorting_algorithms_names,
                             std::vector<std::function<void(int *, int)>> array_generators,
                             std::vector<std::string> array_generators_names);

#endif // EXPERIMENT_H
