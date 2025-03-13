class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') check.push(s[i]);

            if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(check.empty()) return false;

                char top= check.top();

                if ((s[i] == ')' && top == '(') || 
                (s[i] == '}' && top == '{') || 
                (s[i] == ']' && top == '[')) check.pop();

                else return false;
            }
        }
    return check.empty();
    }
};