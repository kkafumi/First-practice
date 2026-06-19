#include <iostream>
#include <vector>
int main() {
  int letters_number = 0;
  int permutation_number = 0;
  std::cin >> letters_number;
  std::cin >> permutation_number;

  std::vector<int> permutation(letters_number);
  std::vector<char> word(letters_number);

  for (int i = 0; i < letters_number; ++i) {
    std::cin >> permutation[i];
    permutation[i]--;
  }
  for (int i = 0; i < letters_number; ++i) {
    std::cin >> word[i];
  }

  std::vector<char> result(letters_number);
  for (int i = 0; i < permutation_number; ++i) {
    for (int i = 0; i < letters_number; ++i) {
      result[permutation[i]] = word[i];
    }
    word = result;
  }
  for (auto& a : result) {
    std::cout << a;
  }
  std::cout << "\n";
  return 0;
}