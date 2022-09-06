#include <iostream>
#include <vector>
#include <queue>

class Node {
  public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

std::vector<std::vector<int>> levelOrder() {
  Node* root;


  std::vector<std::vector<int>> levelVector;
  std::queue<Node*> q;
  int count = 0;
  q.push(root);
  if(q.front() == nullptr) {
    return std::vector<std::vector<int>>{};
  }
  while(q.size() != 0) {
    count = q.size();
    levelVector.push_back(std::vector<int>{});
    for(int i = 0; i < count; i++) {
      for(int j = 0; j < q.front()->children.size(); j++) {
        q.push(q.front()->children[j]);
      }
      levelVector.back().push_back(q.front()->val);
      q.pop();
    }
  }
  
  return levelVector;
}


int main() {

  return 0;
}