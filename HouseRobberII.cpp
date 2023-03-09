#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if(nums.size() == 2) {
            if(nums[0] > nums[1]) return nums[0];
            return nums[1];
        }
        std::vector<int> nums2 = nums;
        nums2.erase(nums2.begin());
        int a = robsingle(nums2);
        nums2 = nums;
        nums2.pop_back();
        int b = robsingle(nums2);
        if(a > b) return a;
        return b;
    }


    int robsingle(std::vector<int>& nums) {
        nums[0] > nums[1] ? nums[1] = nums[0] : NULL;
        for(int i = 2; i < nums.size(); i++) {
            nums[i] + nums[i-2] > nums[i-1] ? nums[i] = nums[i] + nums[i-2] : nums[i] = nums[i-1];
        }
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums[nums.size()-1];
        return nums[nums.size()-2];
    }
};