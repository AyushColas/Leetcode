class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] =0;

        for(int i=1;i<=amount;i++){
            for(int coin: coins){
                if(i>=coin && dp[i-coin] != INT_MAX){
                    dp[i]=min(dp[i], 1 + dp[i-coin]);
                }
            }
        }

        return (dp[amount] == INT_MAX)? -1 : dp[amount];
    //     if(amount == 0) return 0;
    //     queue<pair<int,int>> q;
    //     unordered_set<int> visited;

    //     q.push({0,0});
    //     visited.insert(0);

    //     while(!q.empty())
    //     {
    //         auto [curr_amount,steps]=q.front();
    //         q.pop();

    //         for(int coin:coins)
    //         {
    //             int new_amount= curr_amount + coin;

    //             if(new_amount == amount) return steps+1;

    //             if(new_amount < amount && visited.find(new_amount) == visited.end()){
    //                 visited.insert(new_amount);
    //                 q.push({new_amount,steps+1});
    //             }
    //         }
    //     }
    //     return -1;
    }
};