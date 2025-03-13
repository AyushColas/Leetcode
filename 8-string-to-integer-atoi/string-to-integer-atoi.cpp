class Solution {
public:
    int myAtoi(string s) {

        long res=0;
        bool isNeg = false;
        int i=0;
        int sign=1;
        bool foundDigit = false;

        while(i< s.size() && s[i]==' ')
        {
            i++;
        }

        if(i< s.size() && (s[i] == '-' || s[i] == '+'))
        {
            sign=(s[i] == '-')?-1:1;
            i++;
        }


        while(i< s.size() && s[i]=='0')
        {
            i++;
        }

        while(i<s.size() && isdigit(s[i]))
        {   
            foundDigit = true;
            res=res*10 + (s[i]- '0');

            if(res*sign > INT_MAX)
            {
                return INT_MAX;
            }

            if(res*sign < INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }

        if(foundDigit) return static_cast<int>(res*sign);

        else return 0;
    }
};