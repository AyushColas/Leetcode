class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) 
            return "";
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (s.find(tolower(ch)) != string::npos && s.find(toupper(ch)) != string::npos) {
                continue;  
            }
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));
            return left.length() >= right.length() ? left : right;
        }
        
        return s;
    }
};
