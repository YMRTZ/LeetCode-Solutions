#include <iostream>
#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int upper = nums.size();
        int lower = 0;
        int current;
        if(nums.size() == 1) return nums[0];
        if(nums[1] != nums[0]) return nums[0];
        if(nums[nums.size()-2] != nums[nums.size()-1]) return nums[nums.size()-1];

        while(true) {
            current = (upper+lower)/2;
            if(nums[current-1] == nums[current]) {
                current%2 == 0 ? upper = current : lower = current;
            }
            else if(nums[current+1] == nums[current]) {
                current%2 == 0 ? lower = current : upper = current;
            }
            else {
                return nums[current];
            }
        }
    }
};