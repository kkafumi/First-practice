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

  int path_len = moon_mountain[0][0];
  std::vector<int> path(height);
  path[0] = moon_mountain[0][0];
  int side = 0;

  for (int i = 1; i < height; ++i) {
    int left = moon_mountain[i][side];
    int right = moon_mountain[i][side + 1];
    if (left <= right) {
      path[i] = left;
      path_len += left;
    } else {
      path[i] = right;
      path_len += right;
      ++side;
    }
  }

  std::cout << path_len << "\n";
  for (auto i : path) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}