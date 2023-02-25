#include <iostream>
#include <vector>

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int cur = 0;
        for(int i = 0; i < weights.size(); i++) {
            cur += weights[i];
        }
        int max = cur;
        while(true) {
            if(canShip(weights,days,cur)) {
                if(!canShip(weights,days,cur-1)) break;
                max = cur;
                cur = cur/2;
            }
            else {
                cur = (max+cur)/2;
            }
        }
        return cur;
    }
    bool canShip(std::vector<int>&weights, int days, int cap) {
        int temp = cap;
        for(int i = 0; i < weights.size(); i++) {
            temp -= weights[i];
            if(temp <= 0) {
                days--;
                temp == 0 ? NULL : i--;
                if(days == 0 && !(i == weights.size()-1 && temp == 0)) {
                    return false;
                }
                temp = cap;
            }
        }
        return true;
    }
};