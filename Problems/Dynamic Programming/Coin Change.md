# Coin Change

[Category: Dynamic Programming]

Related Problem: [Perfect Square](./Perfect Squares.md)

Given an integer array **coins** representing coins of different denominations and an integer **amount** representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of coins, return $-1$.

**Example:**

```
Input: coins = [1, 2, 5], amount = 11;
Output: 3;
Input: coins = [2], amount = 3;
Output: -1;
```

**Constraints:**

- $1 \le l_{coins} \le 12$
- $1 \le coins_i \le 2^{31} -1$
- $0\le amount \le 10^4$

### Solution

```cpp
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
```

**Explanation:**

**dp[i]** represents the minimum number of coins that makes up the amount $i$. Assume that the values from **dp[0]** to **dp[i-1]** are already known, thus the transition equation of **dp[i]** can be duduced as

$$
dp_i=min_{j=0}^{l_{coins}-1}dp_{i-coins_j}+1
$$

which means the value of **dp[i]** is determined by **dp[i - coins[j]]**, if **dp[i]** can transfer from **dp[i - coins[j]]** via **coins[j]**, the number of coins that used should add $1$.
