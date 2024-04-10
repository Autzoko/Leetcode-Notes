#include <bits/stdc++.h>
using namespace std;

class JumpGameII {
public:
    int jump(vector<int>& nums) {
        int s = nums.size();
        int *dp = (int*)malloc(s * sizeof(int));
        fill_n(dp, s, s + 1);
        dp[0] = 0;
        for(int i = 0; i < s; i++) {
            for(int j = i; j <= i + nums[i] && j < s; j++) {
                dp[j] = dp[i] + 1 < dp[j] ? dp[i] + 1 : dp[j];
            }
        }
        return dp[s - 1];
    }
};