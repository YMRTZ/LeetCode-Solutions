#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        nums[0] > nums[1] ? nums[1] = nums[0] : NULL;
        for(int i = 2; i < nums.size(); i++) {
            nums[i] + nums[i-2] > nums[i-1] ? nums[i] = nums[i] + nums[i-2] : nums[i] = nums[i-1];
        }
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums[nums.size()-1];
        return nums[nums.size()-2];
    }
};