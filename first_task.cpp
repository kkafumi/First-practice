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
  for(int i = 0; i < height - 1; ++i){
    for(int j = 0; j < static_cast<int>(moon_mountain[i].size()) - 1; ++j){
        int minimum = std::min(moon_mountain[i + 1][j], moon_mountain[i + 1][j + 1]);
        path[i + 1] = minimum;
        path_len += minimum;
    }
  }
  std::cout << path_len << "\n";
  for(auto i : path){
    std::cout << i << " ";
  }
  std::cout << "\n";

//   for (int i = 0; i < static_cast<int>(moon_mountain.size()); ++i) {
//     for (auto j : moon_mountain[i]) {
//       std::cout << j << " ";
//     }
//     std::cout << "\n";
//   }
  return 0;
}