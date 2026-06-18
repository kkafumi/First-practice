#include <iostream>
#include <vector>

class Graph {
 private:
  std::vector<std::vector<int>> tree_;
  int vertexes_number_;

 public:
  explicit Graph(int n) : vertexes_number_(n) {
    tree_.resize(n);
  }

  void AddEdge(int from, int to) {
    tree_[from].push_back(to);
    tree_[to].push_back(from);
  }

  std::vector<int>& GetChildren(int vertex) {
    return tree_[vertex];
  }

  void DFS(int start, std::vector<bool>& used) {
    used[start] = true;
    std::vector<int> children = GetChildren(start);
    for (int i = 0; i < static_cast<int>(children.size()); ++i) {
      int ch = children[i];
      if (!used[ch]) {
        DFS(ch, used);
      }
    }
  }
};

int main() {
  int number_vertexes = 0;
  int number_edges = 0;
  std::cin >> number_vertexes;
  std::cin >> number_edges;
  std::vector<bool> used(number_vertexes, false);
  Graph moon_system(number_vertexes);

  for (int i = 0; i < number_edges; ++i) {
    int from = 0;
    int to = 0;
    std::cin >> from;
    std::cin >> to;
    moon_system.AddEdge(from - 1, to - 1);
  }

  int count_components = 0;
  for (int i = 0; i < number_vertexes; ++i) {
    if (!used[i]) {
      moon_system.DFS(i, used);
      count_components += 1;
    }
  }

  std::cout << count_components - 1 << "\n";
  return 0;
}