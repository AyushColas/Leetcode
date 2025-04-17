class Solution {
public:
    bool isPowerof2(int n){
        return n>0 && (n & (n-1)) == 0;
    }
    vector<int> countBits(int n) {
        vector<int> count(n+1,0);
        count[0] = 0;
        if(n==0) return count;

        for(int i=1;i<=n;i++){
            if(isPowerof2(i)) count[i]=1;
            else count[i] = count[i & (i - 1)] + 1;
        }
        return count;
    }
};