#include <iostream>
int main() {
  int height = 0;
  int width = 0;
  std::cin >> height;
  std::cin >> width;

  int start_x = width;
  int start_y = height;
  int finish_x = -1;
  int finish_y = -1;

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      int value = 0;
      std::cin >> value;
      if (value == 1) {
        start_x = std::min(start_x, j);
        start_y = std::min(start_y, i);
        finish_x = std::max(finish_x, j);
        finish_y = std::max(finish_y, i);
      }
    }
  }

  std::cout << start_y - 1 << " " << start_x - 1 << " " << finish_y + 1 << " " << finish_x + 1 << "\n";
  return 0;
}