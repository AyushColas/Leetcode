class Solution {
public:
    bool canConstruct(string s, int k) {

        bool flag = false;
        if(s.size()<k) return flag;
        if(s.size() == k) return true;

        int count[26]={0};

        for(int i=0; i<s.size();i++)
        {
            count[s[i]-'a']++;
        }
        int oddCount = 0;
        for(int &i: count)
        {
            if(i % 2 != 0) oddCount++;
        }

        if(oddCount > k) return false;

        return true;
        

        // unordered_map <char,int> count;
        // int numC=0;
        // for(auto &c: s)
        // {
        //     count[c]++;
        // }
        // for(auto &i: count)
        // {
        //     if(i.second > 1) numC++;
        // }

        // if(numC >= k) flag =true;
        // return flag;
    }
};