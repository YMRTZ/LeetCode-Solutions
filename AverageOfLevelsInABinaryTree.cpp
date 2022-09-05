#include <iostream>
#include <queue>

struct TreeNode {
  long val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



std::vector<double> AverageOfLevels() {
  TreeNode* root;


  std::queue<TreeNode*> nodeQueue;
  std::vector<double> averageOfLevels = {1};
  nodeQueue.push(root);
  int total;
  int layer = 0;
  TreeNode* currNode;
  // One level per while loop
  while(nodeQueue.size() > 0) {
    total = 0;
    // One node per for loop, all nodes in level
    for(int i = 0; i < (int)averageOfLevels[layer]; i++) {
      // Set current node
      currNode = nodeQueue.front();
      // Add total
      total += currNode->val;
      // Add children
      if(currNode->left != nullptr) {
        if(averageOfLevels.size() - 1 == layer) {
          averageOfLevels.push_back(0);
        }
        nodeQueue.push(currNode->left);
        averageOfLevels[layer+1] += 1;
      }
      if(currNode->right != nullptr) {
        if(averageOfLevels.size() - 1 == layer) {
          averageOfLevels.push_back(0);
        }
        nodeQueue.push(currNode->right);
        averageOfLevels[layer+1] += 1;
      }
      // Pop queue
      nodeQueue.pop();
    }
    averageOfLevels[layer] = total/averageOfLevels[layer];
    layer++;
  }
  return averageOfLevels;
}


int main() {


  

  return 0;
}