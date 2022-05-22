#include "utils.h"

namespace utils {

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

double measureTimeOfFunction(std::function<int *(int *, int)> f, int arr[], int n) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  double cpu_time_used;
  f(arr, n);
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
  return cpu_time_used;
}

class CSV {
private:
  std::string filename;
  std::ofstream file;
  std::string delimiter;

public:
  CSV(std::string filename) {
    this->filename = filename;
    this->file.open(filename);
  }

  ~CSV() { this->file.close(); }

  template <typename T>
  void writeVector(std::vector<T> v) {
    int sizeMinusOne = v.size() - 1;
    for (int i = 0; i < sizeMinusOne; i++) {
      file << v[i] << delimiter;
    }
    file << v[sizeMinusOne] << std::endl;
  }

  template <typename T>
  void writeWithDelimiter(T t) {
    file << t << delimiter;
  }

  template <typename T>
  void writeRaw(T t) {
    file << t;
  }
};

} // namespace utils
