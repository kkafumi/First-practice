#include <iostream>
#include <vector>
int main() {
  int height = 0;
  int width = 0;
  std::cin >> height;
  std::cin >> width;

  int start_x = -1;
  int start_y = -1;
  int finish_x = -1;
  int finish_y = -1;

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      int value = 0;
      std::cin >> value;
      if (value == 1 && start_x == -1) {
        start_x = j - 1;
        start_y = i - 1;
      }
      if (value == 1) {
        finish_x = j + 1;
        finish_y = i + 1;
      }
    }
  }

  std::cout << start_x << " " << start_y << " " << finish_x << " " << finish_y << "\n";
  return 0;
}