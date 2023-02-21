#include <iostream>
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(target > nums.back()) {
            return nums.size();
        }
        if(target < nums.front()) {
            return 0;
        }
        int lower, upper, current, val, narrowed;
        lower = 0;
        upper = nums.size() - 1;
        current = (upper-lower)/2;
        val = nums[current];
        
        while(val != target) {
            current = (upper+lower)/2;
            if(upper-lower < 2) {
                nums[current] < target ? current++ : current = current;
                return current;
            }
            val = nums[current];
            if(target > val) {
                lower = current;
            }
            else if(target < val) {
                upper = current;
            }
            else {
                return current;
            }
        }
        return current;
    }
};