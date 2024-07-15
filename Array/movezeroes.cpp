#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }
        
        for (int i = k; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; 
    
    vector<int> nums2 = {0};
    sol.moveZeroes(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl; 
    return 0;
}