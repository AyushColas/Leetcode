class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int dp0=0;
       int dp1=-prices[0];
       int n= prices.size(); 

       if(n==0) return 0;
       
       for(int i=0; i<n ; i++)
        {
            dp0=max(dp0, dp1+prices[i]);
            dp1=max(dp1, -prices[i]);
        }

        return dp0;
    }
};