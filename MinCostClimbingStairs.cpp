#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int *size = new int[cost.size()];
        size[cost.size()-1] = cost[cost.size()-1];
        size[cost.size()-2] = cost[cost.size()-2];
        for(int i = cost.size()-3; i >= 0; i--) {
            size[i+1] < size[i+2] ? size[i] = size[i+1] : size[i] = size[i+2];
            size[i] += cost[i];
        }
        int min = 0;
        size[0] < size[1] ? min = size[0] : min = size[1];
        return min;
    }
};