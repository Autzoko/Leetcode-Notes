# Triangle

[Category: Dynamic Programming]

Given a **triangle** array, return the minimum path sum from the top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index $i$ on the current row, you may move to either index $i$ or index $i+1$ on the next row.

**Example:**

```
Input: triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]];
Output: 11;
```

**Constraints:**

$1 \le l_{triangle} \le 200$

$-10^4 \le triangle_{i,j} \le 10^4$

### Solution

```cpp
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
```

**Explanation:**
