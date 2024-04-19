# Minimum Path Sum

[Category: Dynamic Programming]

Given a $m \times n$ **grid** filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

- Moves can only be taken down or right ar any point in time.

**Example:**

```
Input: grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]];
Output: 7;
```

**Constraints:**

$1 \le m, n \le 200$

$0 \le grid_{i,j} \le 200$

### Solution

```cpp
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
```

**Explanation:**

Using a $dp$ array to indicate the current minimum path sum. And this sum can only be the sum of the up $dp$ point and current $grid$ point or the left $dp$ point and current $grid$ point. The $dp$ function is shown as:

$$
dp_{i,j}=min(dp_{i-1,j}+grid_{i,j}, dp_{i,j-1}+grid_{i,j})
$$
