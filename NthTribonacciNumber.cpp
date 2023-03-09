#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, int> umap;
    int tribonacci(int n) {
        if (n == 1 || n == 2) return 1;
        else if (n == 0) return 0;
        else {
            if(umap.find(n) == umap.end()) {
                umap[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
            }
            return umap[n];
        }
    }
};