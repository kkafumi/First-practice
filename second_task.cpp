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
  std::vector<int> GetChildren(int vertex) {
    return tree_[vertex];
  }
  void DFS(int start, std::vector<bool> used) {
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

  return 0;
}