#include <iostream>
#include <vector>

int main() {
  int height = 0;
  std::cin >> height;
  std::vector<std::vector<int>> moon_mountain(height);
  for (int i = 0; i < height; ++i) {
    std::vector<int> moon_row(i + 1);
    for (int j = 0; j < static_cast<int>(moon_row.size()); ++j) {
      std::cin >> moon_row[j];
    }
    moon_mountain[i] = moon_row;
  }

  for (int i = 0; i < static_cast<int>(moon_mountain.size()); ++i) {
    for (auto j : moon_mountain[i]) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }
  return 0;
}