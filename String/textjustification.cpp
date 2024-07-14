#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;
        
        while (index < words.size()) {
            int totalChars = words[index].size();
            int last = index + 1;
            
            while (last < words.size()) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }
            
            string line;
            int gaps = last - index - 1;
            
            if (last == words.size() || gaps == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += ' ';
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                int spaces = (maxWidth - totalChars) / gaps;
                int extraSpaces = (maxWidth - totalChars) % gaps;
                
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        line += string(spaces + 1, ' ');
                        if (extraSpaces > 0) {
                            line += ' ';
                            extraSpaces--;
                        }
                    }
                }
            }
            
            result.push_back(line);
            index = last;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = solution.fullJustify(words1, maxWidth1);
    for (const string& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }
    
    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth2 = 16;
    vector<string> result2 = solution.fullJustify(words2, maxWidth2);
    for (const string& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth3 = 20;
    vector<string> result3 = solution.fullJustify(words3, maxWidth3);
    for (const string& line : result3) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}
