class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, 
        vector<vector<int>> &dp) {
            if (i == 0 && j == 0) return grid[0][0];
            if (i < 0 || j < 0) return 1e5;
            int up = grid[i][j] + dfs(i-1, j, grid, dp);
            int left = grid[i][j] + dfs(i, j-1, grid, dp);

            return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dfs(n-1, m-1, grid, dp);
    }
};