class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0, sumFH,sumLH;

        for(int i =low; i< high+1;){
            string s=to_string(i);
            int len=s.size();
            if(len%2 != 0){
                i = pow(10,len);
                if(i> high) return count;
            }else{
                sumLH=0; sumFH =0;

                string FH=s.substr(0, len/2);
                string LH=s.substr(len/2,len-len/2);
                for(char c: FH){
                    sumFH += c- '0';
                }
                for(char c: LH){
                    sumLH += c-'0';
                }
                if(sumFH == sumLH) count++;
            }  
            i++;   
        }
        return count;
    }
};