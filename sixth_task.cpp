#include <iostream>

int main() {
  int request_number = 0;
  std::cin >> request_number;
  for (int i = 0; i < request_number; ++i) {
    int a_controller_number = 0;
    int b_controller_number = 0;
    int module_number_1 = 0;
    int module_number_2 = 0;
    std::cin >> a_controller_number >> b_controller_number >> module_number_1 >> module_number_2;

    int b_1 = std::min(b_controller_number, module_number_1);  // контроллеры B можно сочитать только с модулями 1
    module_number_1 -= b_1;
    int a_12 = std::min(a_controller_number, module_number_1 + module_number_2);  // контроллеры А с любыми модулями
    std::cout << b_1 + a_12 << " ";
  }
  std::cout << "\n";

  return 0;
}