class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int len= needle.size();
        int i=0, j=0;
        while(i<n)
        {
            if(needle == haystack.substr(i,len)) return i;

            i++;

        }

        return -1;
    }
};