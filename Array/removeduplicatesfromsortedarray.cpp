#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int writeIndex = 1;
        for (int readIndex = 1; readIndex < nums.size(); ++readIndex) {
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        return writeIndex;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1);
    cout << "k = " << k1 << ", nums = ";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl; 
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2);
    cout << "k = " << k2 << ", nums = ";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;  

    return 0;
}