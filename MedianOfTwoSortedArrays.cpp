#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  double med1, med2;

  if(nums1.size() == 0) {
    if(nums2.size()%2 == 1) {
      med2 = (double)nums2[nums2.size()/2];
    }
    else {
      med2 = (double)(nums2[nums2.size()/2 - 1] + nums2[nums2.size()/2])/2;
    }
    return med2;
  }
  if(nums2.size() == 0) {
    if(nums1.size()%2 == 1) {
      med1 = (double)nums1[nums1.size()/2];
    }
    else {
      med1 = (double)(nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2])/2;
    }
  }

  if(nums1.size()%2 == 1) {
    med1 = (double)nums1[nums1.size()/2];
  }
  else {
    med1 = (double)(nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2])/2;
  }

  if(nums2.size()%2 == 1) {
    med2 = (double)nums2[nums2.size()/2];
  }
  else {
    med2 = (double)(nums2[nums2.size()/2 - 1] + nums2[nums2.size()/2])/2;
  }


  if(nums1 == nums2) {
    return med1;
  }

  std::vector<int> leftVector, rightVector;
  if(med1 < med2) {
    leftVector = nums1;
    rightVector = nums2;
  }
  else {
    leftVector = nums2;
    rightVector = nums1;
  }

  int rightMedIndex = rightVector.size()/2;
  int rightPeg = 0;
  int leftMedIndex = std::max((int)(leftVector.size()-1)/2,0);
  // int leftPeg;
  for(int i = rightMedIndex; i >= 0; i--) {
    if(rightVector[i] < leftVector[leftMedIndex]) {
      rightPeg = i+1;
      break;
    }
  }

  int target = (rightVector.size() + leftVector.size()+1)/2;
  int current = leftMedIndex + rightPeg;
  std::vector<int> temp;

  while(current <= target) {
    if((leftMedIndex <= leftVector.size()-1) && (leftVector[leftMedIndex] < rightVector[rightPeg] || rightPeg >= rightVector.size()-1)) {
      temp.push_back(leftVector[leftMedIndex]);
      leftMedIndex++;
    }
    else if (rightPeg <= rightVector.size()-1) {
      temp.push_back(rightVector[rightPeg]);
      rightPeg++;
    }
    current++;
  }
  if((rightVector.size()+leftVector.size())%2==1) {
    return (double)temp[std::max((int)temp.size()-2,0)];
  }
  else {
    double lc = (double)(temp[temp.size()-2]+temp[temp.size()-1])/2;
    return lc;
  }

// [1,3]
// [2]
// [1,3,7]
// [2,7,8,23]
// [1,3]
// [2,4]
// [-6,-4,-2,-1]
// [-4,7,9]
// []
// [1]
// [1]
// []
// []
// [1,2,7,9]
// [1,2]
// [-1,3]

  // if((rightVector.size() + leftVector.size())%2 == 1) {
  //   while(true) {
  //     if(leftVector[leftMedIndex] < rightVector[rightPeg]) {
  //       leftMedIndex++;
  //       if(current == target) {
  //         return (double)leftVector[leftMedIndex];
  //       }
  //     }
  //     else {
  //       rightPeg++;
  //       if(current == target) {
  //         return (double)rightVector[rightPeg];
  //       }
  //     }
  //     current++;
  //   }
  // }
  // else {
  //   double a, b;
  //   while(true) {
  //     if(leftVector[leftMedIndex] < rightVector[rightPeg]) {
  //       leftMedIndex++;
  //       if(current == target) {
  //         a = leftVector[leftMedIndex];
  //       }
  //       else if(current == target+1) {
  //         b = leftVector[leftMedIndex];
  //         double c = (a+b)/2;
  //         return c;
  //       }
  //     }
  //     else {
  //       rightPeg++;
  //       if(current == target) {
  //         a= rightVector[rightPeg];
  //       }
  //       else if(current == target+1) {
  //         b = rightVector[rightPeg];
  //         double c = (a+b)/2;
  //         return c;
  //       }
  //     }
  //     current++;
  //   }
  // }
  




  // for(int i = leftMedIndex; i < leftVector.size(); i++) {
  //   if(leftVector[i] < rightVector[rightMedIndex]) {
  //     leftPeg = i-1;
  //     break;
  //   }
  // }
  


}


int main() {

  return 0;
}