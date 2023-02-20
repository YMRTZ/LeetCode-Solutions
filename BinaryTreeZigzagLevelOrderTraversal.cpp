#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> bigVec;
        if(root == nullptr) return bigVec;
        std::vector<int> tempVec;
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;
        s2.push(root);
        while(s1.size() > 0 || s2.size() > 0) {
            if(!s1.empty()) {
                while(!s1.empty()) {
                    tempVec.push_back(s1.top()->val);
                    if(s1.top()->right != nullptr) {
                        s2.push(s1.top()->right);
                    }
                    if(s1.top()->left != nullptr) {
                        s2.push(s1.top()->left);
                    }
                    s1.pop();
                }
                bigVec.push_back(tempVec);
                tempVec.clear();
            }
            if(!s2.empty()) {
                while(!s2.empty()) {
                    tempVec.push_back(s2.top()->val);
                    if(s2.top()->left != nullptr) {
                        s1.push(s2.top()->left);
                    }
                    if(s2.top()->right != nullptr) {
                        s1.push(s2.top()->right);
                    }
                    s2.pop();
                }
                bigVec.push_back(tempVec);
                tempVec.clear();
            }
        }
        return bigVec;
    }
};