#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {
            if (bracketMap.count(ch)) {
                if (stk.empty() || stk.top() != bracketMap[ch]) {
                    return false;
                }
                stk.pop();
            } 
            else {
                stk.push(ch);
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution solution;
    
    string s1 = "()";
    cout << (solution.isValid(s1) ? "true" : "false") << endl;  

    string s2 = "()[]{}";
    cout << (solution.isValid(s2) ? "true" : "false") << endl;  

    string s3 = "(]";
    cout << (solution.isValid(s3) ? "true" : "false") << endl;  

    return 0;
}
