#include <iostream>
#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::string tree2str(TreeNode* root) {
  return dfs(root);
}

std::string dfs(TreeNode* node) {
  std::string current = std::to_string(node->val);

  if(node->left != nullptr) {
    current += '(';
    current += dfs(node->left);
    current += ')';
  }
  if(node->right != nullptr) {
    if(node->left == nullptr) {
      current += "()";
    }
    current += '(';
    current += dfs(node->right);
    current += ')';
  }
  return current;
}

int main() {
  return 0;
}