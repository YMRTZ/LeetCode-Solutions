#include<iostream>
#include<stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* pruneTree(TreeNode* root) {
  // std::stack<TreeNode*> dfStack;
  int total = dfs(root);
  if(total == 0) {
    return;
  }
  return root;
}

// Left int: total node value
// Right int: 0 - left, 1 - right, 2 - root
int dfs(TreeNode* currNode) {
  int val = currNode->val;
  int temp;
  if(currNode->left != nullptr) {
    temp = dfs(currNode->left);
    if(temp == 0) {
      currNode->left = nullptr;
    }
    else {
      val += temp;
    }
  }
  if(currNode->right != nullptr) {
    temp = dfs(currNode->right);
    if(temp == 0) {
      currNode->right = nullptr;
    }
    else {
      val += temp;
    }
  }



  return val;
}


int main() {

  return 0;
}