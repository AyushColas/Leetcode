class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> hehe;
        string word;

        while(ss >> word)
        {
            hehe.push_back(word);
        }

        reverse(hehe.begin(),hehe.end());

        string result;

        for(size_t i =0;i<hehe.size();i++)
        {
            result+=hehe[i];

            if(i!= hehe.size()-1) result+=" ";
        }

        return result;
    }
};