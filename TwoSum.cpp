#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> getIndices() {
  int target = 6;
  std::vector<int> nums{3,2,4};

  std::vector<int> returnVec;
  std::unordered_map<int,int> diffMap;
  diffMap[target - nums[0]] = 0;
  for(int i = 1; i < nums.size(); i++) {
    if(diffMap.count(nums[i]) != 0) {
      // std::cout << "Match" << std::endl;
      returnVec.push_back(diffMap[nums[i]]);
      returnVec.push_back(i);
      return returnVec;
    }
    else {
      // std::cout << "No Match" << std::endl;
      diffMap[target - nums[i]] = i;
    }
  }
  std::vector<int> notWork{0,0};
  return notWork;
  // std::vector<int> notWork{0,0};
  // return notWork;
}

int main() {
  std::vector<int> indices = getIndices();
  std::cout << indices[0] << std::endl;
  std::cout << indices[1] << std::endl;

  return 0;
}