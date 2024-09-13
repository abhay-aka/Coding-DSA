#include <vector>
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &matrix,
            vector<vector<int>>& dp) {
        if (j<0 || j>=matrix[0].size()) return 1e6;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != -1) return dp[i][j];
        int leftDiagonal = matrix[i][j] + dfs(i-1, j-1, matrix, dp);
        int top = matrix[i][j] + dfs(i-1, j, matrix, dp);
        int rightDiagonal = matrix[i][j] + dfs(i-1, j+1, matrix, dp);
        //cout<<leftDiagonal<<" "<<top<<" "<<rightDiagonal<<endl;
        return dp[i][j] = min(leftDiagonal, min(top, rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1e6;
        // for recursion
        // for (int i = 0; i < n; i++) {
        //     ans = min (ans, dfs(n-1, i, matrix, dp));
        // }
        for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int bottom = matrix[i][j] + dp[i-1][j];
                int left = 1e6, right = 1e6;
                if (j > 0)  left = matrix[i][j] + dp[i-1][j-1];
                if (j < m-1)  right = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(bottom, min(left, right));
            }
        }
        for (int j = 0; j < m; j++) ans = min(dp[n-1][j], ans);
        return ans;
    }
};
