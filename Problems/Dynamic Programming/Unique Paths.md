# Unique Paths

[Category: Dynamic Programming]

There is a robot on an $m \times n$ grid. The robot is initially located at the *top-left corner*. The robot tries to move to the *bottom-right corner.* The robot can only move either down or right at any point in time.

Given the two integers $m$ and $n$, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

**Example:**

```
Input: m = 3, n = 7;
Output: 28;
```

**Constraints:**

$ 1 \le m, n \le 100$

### Solution

```cpp
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
```

**Explanation:**

For at any position excludes first row and first column, each has two methods to reach: from the up one and the left one. Here the $dp$ function can be duduced:

$$
dp_{i,j}=dp_{i-1,j} + dp_{i,j-1}
$$
