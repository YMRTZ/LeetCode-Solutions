#include <iostream>
#include <vector>
#include <algorithm>

int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {

  // Sorting credit to kamyu104
  std::sort(begin(properties),end(properties), [](auto &lhs, auto &rhs) {
    return lhs[0] == rhs[0] ? lhs[1]>rhs[1] : lhs[0]<rhs[0];
  });
  
  int count = 0;
  int maxDef = properties[properties.size()-1][1];
  int maxAtk = properties[properties.size()-1][0];

  for(int i = properties.size()-2; i >= 0; i--) {
    if(properties[i][1] < maxDef && properties[i][0] != maxAtk) {
      count++;
    }
    else {
      maxDef = properties[i][1];
      maxAtk = properties[i][0];
    }
  }
  return count;
}





int main() {

  return 0;
}