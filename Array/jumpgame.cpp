#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int max_reachable = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > max_reachable) {
            return false;
        }
        max_reachable = max(max_reachable, i + nums[i]);
        if (max_reachable >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    bool result1 = canJump(nums1);
    bool result2 = canJump(nums2);

    cout << "Result for nums1: " << (result1 ? "true" : "false") << endl;
    cout << "Result for nums2: " << (result2 ? "true" : "false") << endl;

    return 0;
}