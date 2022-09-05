#include <iostream>
#include <vector>

std::vector<int> getIndices() {
  int target = 6;
  std::vector<int> nums{1,3,4,2};




  std::vector<int> nums2 = nums;
  std::vector<int> temp;
  int min = nums[0];
  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] < min) {
      min = nums[i];
    }
  }

  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] + min > target) {
      nums.erase(nums.begin() + i);
      if(i > 0) {
        i--;
      }
      
    }
    if(((nums[0] + nums[i]) == target) && (i != 0)) {
      for(int j = 0; j < nums2.size(); j++) {
        if(nums2[j] == nums[0]) {
          temp.push_back(j);
        }
        else if(nums2[j] == nums[i]) {
          temp.push_back(j);
        }
      }
      return temp;
    }
  }
  nums.erase(nums.begin());
  while(nums.size() > 1) {
    for(int i = 0; i < nums.size(); i++) {
      if((nums[0] + nums[i]) == target) {
        for(int j = 0; j < nums2.size(); j++) {
          if(nums2[j] == nums[0]) {
            temp.push_back(j);
          }
          else if(nums2[j] == nums[i]) {
            temp.push_back(j);
          }
        }
        return temp;
      } 
    }
    nums.erase(nums.begin());
  }
  return temp;
}

int main() {
  
  std::vector<int> temp = getIndices();
  std::cout << "New" << std::endl;
  std::cout << temp[0] << std::endl;
  std::cout << temp[1] << std::endl;
  



  // for(int i = 0; i < nums.size(); i++) {
  //   std::cout << nums[i] << std::endl;
  // }
}