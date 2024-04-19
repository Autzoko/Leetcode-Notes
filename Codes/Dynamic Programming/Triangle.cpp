#include <bits/stdc++.h>
using namespace std;

class Triangle {
public:
    int mininumTotal(vector<vector<int>>& triangle) {
        size_t size = triangle.size();
        vector<vector<int>> dp;
        for(int i = 0; i < size; i++) 
            dp.push_back(vector<int>(triangle[i].size(), 0));
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < size; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if(j == triangle[i].size() - 1) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
        return *min_element(dp[size - 1].begin(), dp[size - 1].end());
    }
};