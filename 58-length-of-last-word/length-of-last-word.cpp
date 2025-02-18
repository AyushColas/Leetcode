
class Solution {
public:
    int lengthOfLastWord(string str) {
        int length =0;
        int i = str.size()-1;

        while(i>=0 && isspace(str[i]))
        {
            i--;
        }
        while(i>=0 && !isspace(str[i]))
        {
            length++;
            i--;
        }
        
        return length;
    }
};