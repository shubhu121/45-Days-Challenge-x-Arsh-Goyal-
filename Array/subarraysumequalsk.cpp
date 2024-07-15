#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cum_sum_freq;
        int cum_sum = 0, count = 0;
        cum_sum_freq[0] = 1;
        
        for (int num : nums) {
            cum_sum += num;
            if (cum_sum_freq.find(cum_sum - k) != cum_sum_freq.end()) {
                count += cum_sum_freq[cum_sum - k];
            }
            cum_sum_freq[cum_sum]++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << "Result for nums1: " << sol.subarraySum(nums1, k1) << endl; 
    
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "Result for nums2: " << sol.subarraySum(nums2, k2) << endl; 
    
    return 0;
}