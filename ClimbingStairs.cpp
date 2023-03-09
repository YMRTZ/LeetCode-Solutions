#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        int temp = 1;
        std::pair<int,int> pr(1,1);
        while(temp < n) {
            pr.second = pr.second+pr.first;
            pr.first = pr.second-pr.first;
            temp++;
        }
        return(pr.second);
    }
};