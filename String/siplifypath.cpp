#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stack;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            else stack.push_back(token);
        }
        
        string canonicalPath = "";
        while (!stack.empty()) {
            canonicalPath += "/" + stack.front();
            stack.pop_front();
        }
        
        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};

int main() {
    Solution sol;
    
    vector<string> paths = {
        "/home/", 
        "/home//foo/", 
        "/home/user/Documents/../Pictures", 
        "/../", 
        "/.../a/../b/c/../d/./"
    };
    
    for (const string& path : paths) {
        cout << "Input: " << path << "\nOutput: " << sol.simplifyPath(path) << "\n\n";
    }
    
    return 0;
}
