#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getPointer() {
  ListNode* l1;
  ListNode* l2;


  
  int carryOver = 0;
  ListNode* nodePtr1 = l1;
  ListNode* nodePtr2 = l2;

  while(nodePtr1 != nullptr) {

    nodePtr1->val += carryOver;

    if(nodePtr2 != nullptr) {
      nodePtr1->val += nodePtr2->val;
      nodePtr2 = nodePtr2->next;
    }

    carryOver = nodePtr1->val / 10;
    nodePtr1->val = nodePtr1->val%10;

    if(nodePtr1->next == nullptr && carryOver != 0) {
      nodePtr1->next = new ListNode(0);
    }
    else if(nodePtr1->next == nullptr && nodePtr2 != nullptr) {
      nodePtr1->next = new ListNode(0);
    }
    
    nodePtr1 = nodePtr1->next;
  }
  return l1;
}

int main() {
  
  return 0;
}