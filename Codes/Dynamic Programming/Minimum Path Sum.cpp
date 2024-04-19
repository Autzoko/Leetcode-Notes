#include <bits/stdc++.h>
using namespace std;

class MinimumPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        int **dp = new int*[n_row];
        for(int i = 0; i < n_row; i++) {
            dp[i] = new int[n_col];
            fill_n(dp[i], n_col, INT_MAX);
        }
        dp[0][0] = grid[0][0];

        for(int i = 0; i < n_row; i++) {
            for(int j = 0; j < n_col; j++) {
                if(i) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j] < dp[i][j] ? dp[i - 1][j] + grid[i][j] : dp[i][j];
                }
                if(j) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j] < dp[i][j] ? dp[i][j - 1] + grid[i][j] : dp[i][j];
                }
            }
        }
        return dp[n_row - 1][n_col - 1];
    }
};