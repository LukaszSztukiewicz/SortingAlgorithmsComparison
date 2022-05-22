#include "experiment.h"
#include "generators.cc"
#include "sorting-algos.cc"
#include "utils.cc"

namespace experiment {

void speedComparison(int n, int steps, std::string outputFile,
                     std::vector<std::function<int *(int *, int)>> sorting_algorithms,
                     std::vector<std::string> sorting_algorithms_names) {

  utils::CSV csv(outputFile);
  csv.writeWithDelimiter("n");
  csv.writeVector(sorting_algorithms_names);

  const int num_algos = sorting_algorithms.size();
  std::vector<double> temp_results;

  for (int i = 1; i <= steps; i++) {
    int arrsize = n * i;
    int arr[arrsize];
    generators::generateRandomArray(arr, arrsize);

    for (int j = 0; j < num_algos; j++) {
      int arr_copy[arrsize];
      std::copy(arr, arr + n, arr_copy);
      double time_taken_ch = utils::measureTimeOfFunction(sorting_algorithms[i], arr, arrsize);
      temp_results.push_back(time_taken_ch);
    }
    csv.writeWithDelimiter(i);
    csv.writeVector(temp_results);
  }
}

void effectivenessComparison(int n, int steps, std::string outputFile,
                             std::vector<std::function<int *(int *, int)>> sorting_algorithms,
                             std::vector<std::string> sorting_algorithms_names,
                             std::vector<std::function<void(int *, int)>> array_generators,
                             std::vector<std::string> array_generators_names) {

  for (int k = 0; k < array_generators.size(); k++) {
    utils::CSV csv(outputFile + "_" + array_generators_names[k]);
    csv.writeWithDelimiter("n");
    csv.writeVector(sorting_algorithms_names);

    const int num_algos = sorting_algorithms.size();
    std::vector<double> temp_results;
    std::vector<double> results_array[steps];

    for (int i = 1; i <= steps; i++) {
      int arrsize = n * i;
      int arr[arrsize];

      array_generators[k](arr, arrsize);

      for (int j = 0; j < num_algos; j++) {
        int arr_copy[arrsize];
        std::copy(arr, arr + n, arr_copy);
        double time_taken_ch = utils::measureTimeOfFunction(sorting_algorithms[i], arr, arrsize);
        temp_results.push_back(time_taken_ch);
      }
      csv.writeWithDelimiter(i);
      csv.writeVector(temp_results);
    }
  }
}

} // namespace experiment

int main(int argc, char const *argv[]) {
  // first exercise
  int n     = 100000;
  int steps = 20;

  std::vector<std::function<int *(int *, int)>> sorting_algorithms = {
      sorting_algos::bubbleSort,
      sorting_algos::heapSort,
      sorting_algos::countingSort,
      sorting_algos::shellSort};

  std::vector<std::string> sorting_algorithms_names = {
      "bubbleSort",
      "heapSort",
      "countingSort",
      "shellSort"};

  experiment::speedComparison(n, steps, "speed_comparison.csv", sorting_algorithms, sorting_algorithms_names);

  //-----------------------------------------------------------------------------------------
  // second exercise
  n     = 100000;
  steps = 20;

  std::vector<std::function<int *(int *, int)>> sorting_algorithms = {
      sorting_algos::quickSort,
      sorting_algos::heapSort,
      sorting_algos::mergeSort,
  };

  std::vector<std::string> sorting_algorithms_names = {
      "quickSort",
      "heapSort",
      "mergeSort"};

  std::vector<std::function<void(int *, int)>> array_generators = {
      generators::generateRandomArray,
      generators::generateConstantArray,
      generators::generateIncreasingArray,
      generators::generateDecreasingArray,
      generators::generateReversedVShapedArray,
      generators::generateVShapedArray,
  };

  std::vector<std::string> array_generators_names = {
      "random",
      "constant",
      "increasing",
      "decreasing",
      "reversedVShaped",
      "vShaped",
  };
  experiment::effectivenessComparison(n, steps, "effectiveness_comparison.csv", sorting_algorithms, sorting_algorithms_names, array_generators, array_generators_names);

  return 0;
}
