#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* pruneTree() {
  TreeNode* root;


  std::stack<TreeNode*> dfStack;
  std::stack<std::pair<TreeNode*,int>*> dbStack;

  dfStack.push(root);
  TreeNode* currNode;
  while(!dfStack.empty()) {
    // Push right side first, so left processes first
    currNode = dfStack.top();
    dfStack.pop();


    if(currNode->val != 1) {
      if(currNode->left != nullptr && currNode->right != nullptr) {
        dbStack.push(new std::pair<TreeNode*,int> {currNode,0});
      }
      else if(currNode == nullptr && currNode->right == nullptr) {
        if(dbStack.top()->second == 0) {
          delete dbStack.top()->first->left;
          dbStack.top()->first->left = nullptr;
        }
        else {
          delete dbStack.top()->first->right;
          dbStack.top()->first->right = nullptr;
        }
        dbStack.top()->second++;
      }

      if(currNode->right != nullptr) {
        dfStack.push(currNode->right);
      }
      if(currNode->left != nullptr) {
        dfStack.push(currNode->left);
      }

    }

    if(dbStack.top()->second == 2) {
      dbStack.pop();
    }
  }

  return root;
}

int main() {
  return 0;
}