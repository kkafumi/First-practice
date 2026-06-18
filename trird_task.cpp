#include <iostream>
#include <vector>

class IrkutskSegmentTree {
 private:
  std::vector<int> city_;
  int size_;

  void Add(int current_street, int finish_street, int left_street, int right_street, int snow) {
    if (left_street == right_street) {
      city_[current_street] += snow;
    } else {
      int middle = (right_street + left_street) / 2;
      if (finish_street <= middle) {
        Add(current_street * 2 + 1, finish_street, left_street, middle, snow);
      } else {
        Add(current_street * 2 + 2, finish_street, middle + 1, right_street, snow);
      }
      city_[current_street] = city_[current_street * 2 + 1] + city_[current_street * 2 + 2];
    }
  }
  int Request(int current_street, int left_street, int right_street, int start_request, int finish_request) {
    if (start_request > finish_request) {
      return 0;
    }
    if (start_request == left_street && finish_request == right_street) {
      return city_[current_street];
    }
    int middle = (left_street + right_street) / 2;
    int left_sum =
        Request(current_street * 2 + 1, left_street, middle, start_request, std::min(middle, finish_request));
    int right_sum =
        Request(current_street * 2 + 2, middle + 1, right_street, std::max(start_request, middle + 1), finish_request);
    return left_sum + right_sum;
  }

 public:
  explicit IrkutskSegmentTree(int n) : size_(n) {
    city_.assign(4 * size_, 0);
  }
  void AddSnow(int street, int snow) {
    Add(0, street, 0, size_ - 1, snow);
  }
  int RequestSnow(int start, int finish) {
    return Request(0, 0, size_ - 1, start, finish);
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
      irkutsk.AddSnow(street - 1, snow);
    } else {
      int first_street = 0;
      int second_street = 0;
      std::cin >> first_street >> second_street;
      std::cout << irkutsk.RequestSnow(first_street - 1, second_street - 1) << "\n";
    }
  }
  return 0;
}
