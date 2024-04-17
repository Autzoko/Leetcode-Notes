#include <bits/stdc++.h>
using namespace std;

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        int **dp = new int*[m];
        for(int i = 0; i < m; i++) {
            dp[i] = new int[n];
            fill_n(dp[i], n, INT_MAX);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i && j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else dp[i][j] = (i & j) + 1;
            }
        }
        return dp[m - 1][n - 1];
    }
};