#include "experiment.h"
#include "generators.h"
#include "sorting-algos.h"
#include "utils.h"

namespace experiment {

void effectivenessComparison(int n, int steps, std::string outputFile,
                             std::vector<std::function<int *(int *, int)>> sorting_algorithms,
                             std::vector<std::string> sorting_algorithms_names,
                             std::vector<std::function<void(int *, int)>> array_generators,
                             std::vector<std::string> array_generators_names) {
  for (int k = 0; k < array_generators.size(); k++) {
    CSV csv("./data/out/" + array_generators_names[k] + "Array_" + outputFile);
    csv.writeWithDelimiter("n");
    csv.writeVector(sorting_algorithms_names);

    const int num_algos = sorting_algorithms.size();
    double temp_results[num_algos];

    for (int i = 1; i <= steps; i++) {
      int arrsize = n * i;
      int *arr    = new int[arrsize];

      array_generators[k](arr, arrsize);

      for (int j = 0; j < num_algos; j++) {
        int *arr_copy = new int[arrsize];
        std::copy(arr, arr + arrsize, arr_copy);
        double time_taken_ch = utils::measureTimeOfFunction(sorting_algorithms[j], arr_copy, arrsize);
        temp_results[j]      = time_taken_ch;
        // LOG
        printf("%d %s %s %f\n", arrsize, sorting_algorithms_names[j].c_str(), array_generators_names[k].c_str(), time_taken_ch);
        delete[] arr_copy;
      }
      csv.writeWithDelimiter(i);
      csv.writeArray(temp_results, num_algos);
      delete[] arr;
    }
  }
}

} // namespace experiment

int main(int argc, char const *argv[]) {
  // first exercise
  int n     = 5000;
  int steps = 20;

  std::vector<std::function<int *(int *, int)>> sorting_algorithms_1 = {
      sorting_algos::bubbleSort,
      sorting_algos::heapSort,
      sorting_algos::countingSort,
      sorting_algos::shellSort};

  std::vector<std::string> sorting_algorithms_names_1 = {
      "bubbleSort",
      "heapSort",
      "countingSort",
      "shellSort"};

  std::vector<std::function<void(int *, int)>> array_generators_1 = {
      generators::generateRandomArray,
  };

  std::vector<std::string> array_generators_names_1 = {
      "random",
  };

  experiment::effectivenessComparison(n, steps, "speed_comparison.csv", sorting_algorithms_1, sorting_algorithms_names_1, array_generators_1, array_generators_names_1);

  //-----------------------------------------------------------------------------------------
  // second exercise
  n     = 100000;
  steps = 20;

  std::vector<std::function<int *(int *, int)>> sorting_algorithms_2 = {
      sorting_algos::quickSort,
      sorting_algos::heapSort,
      sorting_algos::mergeSort,
  };

  std::vector<std::string> sorting_algorithms_names_2 = {
      "quickSort",
      "heapSort",
      "mergeSort"};

  std::vector<std::function<void(int *, int)>> array_generators_2 = {
      generators::generateRandomArray,
      generators::generateConstantArray,
      generators::generateIncreasingArray,
      generators::generateDecreasingArray,
      generators::generateReversedVShapedArray,
      generators::generateVShapedArray,
  };

  std::vector<std::string> array_generators_names_2 = {
      "random",
      "constant",
      "increasing",
      "decreasing",
      "reversedVShaped",
      "vShaped",
  };
  experiment::effectivenessComparison(n, steps, "effectiveness_comparison.csv", sorting_algorithms_2, sorting_algorithms_names_2, array_generators_2, array_generators_names_2);

  return 0;
}
