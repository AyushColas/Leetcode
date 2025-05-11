class Solution {
public:
    void dfs(vector<vector<char>>& s, int i, int j){
        int m = s.size();
        int n = s[0].size();

        if(i < 0 || j <0 || i>=m || j>=n || s[i][j] != 'O') return;

        s[i][j] = 'W';
        dfs(s, i+1 ,j);
        dfs(s, i-1, j);
        dfs(s, i, j+1);
        dfs(s, i, j-1);
    }

    void solve(vector<vector<char>>& s) {
        int m = s.size();
        if(m==0) return;
        int n = s[0].size();

        for(int i =0 ; i<m ; i++){
            if(s[i][0] == 'O') dfs(s, i, 0);
            if(s[i][n-1] == 'O') dfs(s, i, n-1);
        }

        for(int j=0; j<n; j++){
            if(s[0][j] == 'O') dfs(s, 0, j);
            if(s[m-1][j] == 'O') dfs(s, m-1, j);
        }

        for(int i =0; i < m; i++){
            for(int j=0; j< n; j++){
                if(s[i][j] == 'O') s[i][j] = 'X';
                else if(s[i][j] == 'W') s[i][j] = 'O';
            }
        }
    }
};