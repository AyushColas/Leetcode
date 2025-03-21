class Solution {
public:
vector<vector<int>> dp;

int minPathSum(vector<vector<int>> &grid, int i, int j) {
    if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;

    if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int right = minPathSum(grid, i, j + 1);
    int down = minPathSum(grid, i + 1, j);

    return dp[i][j] = grid[i][j] + min(right, down);
}

int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    dp = vector<vector<int>>(m, vector<int>(n, -1)); 
    return minPathSum(grid, 0, 0);
}
};