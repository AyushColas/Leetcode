class Solution {
public:
    int romanToInt(string s) {
        int romanValues[26] = {0};
        romanValues['I' - 'A'] = 1;
        romanValues['V' - 'A'] = 5;
        romanValues['X' - 'A'] = 10;
        romanValues['L' - 'A'] = 50;
        romanValues['C' - 'A'] = 100;
        romanValues['D' - 'A'] = 500;
        romanValues['M' - 'A'] = 1000;

        int result =0;

        for(int i=0; i<s.length()-1; i++)
        {
            int current = romanValues[s[i]-'A'];
            int next=romanValues[s[i+1] - 'A' ];

            if(current<next) result -= current;

            else result += current;
        }
        result+= romanValues[s.back()-'A'];
        return result;
    }
};