#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min = prices[0];
        int cur = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            }
            else if(prices[i] - min > cur) {
                cur = prices[i] - min;
            }
        }
        return cur;
    }
};