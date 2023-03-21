#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        int old = 0;
        int older = 0;
        int max = 0;
        int prev = 0;
        std::map<int,int> vals;
        for(int i = 0; i < nums.size(); i++) {
            vals.find(nums[i]) == vals.end() ? vals[nums[i]] = nums[i] : vals[nums[i]] += nums[i];
        }
        for(auto pain : vals) {
            if(pain.first > prev+1) {
                old = max;
                older = max;
            } 
            older + pain.second > old ? max = older + pain.second : max = old;
            older = old;
            old = max;
            prev = pain.first;
        }
        return max;
    }
};