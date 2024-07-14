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