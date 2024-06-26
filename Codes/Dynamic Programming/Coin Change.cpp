#include <bits/stdc++.h>
using namespace std;

class CoinChange{
public:
    int coinChange(vector<int>& coins, int amount) {
        int *dp = new int[amount + 1];
        fill_n(dp, amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i)
                    dp[i] = dp[i - coins[j]] + 1 < dp[i] ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};