#include <iostream>
#include <vector>

class IrkutskSegmentTree {
 private:
  std::vector<int> city_;
  int size_;

 public:
  explicit IrkutskSegmentTree(int n) : size_(n) {
    city_.assign(4 * size_, 0);
  }
  void AddSnow(int index, int snow) {
  }
  int RequestSnow(int start, int final) {
  }
};

int main() {
  int number_streets = 0;
  int number_requests = 0;
  std::cin >> number_streets;
  std::cin >> number_requests;
  IrkutskSegmentTree irkutsk(number_streets);
  for (int i = 0; i < number_requests; ++i) {
    int request = 0;
    std::cin >> request;
    if (request == 1) {
      int street = 0;
      int snow = 0;
      std::cin >> street >> snow;
      irkutsk.AddSnow(street, snow);
    } else {
      int first_street = 0;
      int second_street = 0;
      std::cin >> first_street >> second_street;
      std::cout << irkutsk.RequestSnow(first_street, second_street) << "\n";
    }
  }
  return 0;
}
