class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        if(s == "") return true;

        for(int i=0; i <t.length(); i++)
        {
                if(s[j] == t[i])
                {
                    j++;
                    if(j == s.length())
                    return true;
                }
                else continue;
        }

        return false;
    }
};