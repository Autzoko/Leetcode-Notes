# Perfect Squares

[Category: Dynamic Programming]

Related Problem: [Coin Change](./Coin Change.md)

Given an integer $n$, return the least number of perfect square numbers that sum to $n$.

A ***perfect square*** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9 and 16 are perfect squares while 3 and 11 are not.

**Example:**

```
Input: n = 12;
Output: 3;
//Explanation: 12 = 4 + 4 + 4;
```

**Constraints:**

- $1 \le n \le 10^4$

### Solution

```cpp
class PerfectSquares {
public:
    int numSquares(int n) {
        int *dp = new int[n + 1];
        fill_n(dp, n + 1, n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; i - j * j >= 0; j++) {
                dp[i] = dp[i] < dp[i - j * j] + 1 ? dp[i] : dp[i - j * j] + 1;
            }
        }
        return dp[n];
    }
};
```

**Explanation:**
