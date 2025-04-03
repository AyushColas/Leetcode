class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if(s.empty()) return 0;

        string a="";
        string top,btm;
        int totalScore =0,topScore=0, btmScore=0;
        
        if(x>y){
            top="ab";
            topScore=x;
            btm="ba";
            btmScore=y;
        }
        else {
            top="ba";
            topScore=y;
            btm="ab";
            btmScore=x;
        }

        for(char c: s)
        {
         if(!a.empty() && a.back() == top[0] && c == top[1]) 
         {
            a.pop_back();
            totalScore+=topScore;
         }else
         {
            a.push_back(c);
         }
        }
        s = a;
        a.clear();
        cout << a;
        if(!s.empty())
        {
        for(char c: s)
        {
         if(!a.empty() &&a.back() == btm[0] && c == btm[1] ) 
         {
            a.pop_back();
            totalScore+=btmScore;
         }else
         {
            a.push_back(c);
         }
        }
        }
        return totalScore;
    }
};