# Jump Game II

[Category: Dynamic Programming]

Given a **0-indexed** array of integers *nums* of length *n*. You are initially positioned at *nums[0].*

Each element *nums[i]* represents the maximum length of a forward jump from index $i$. In other word, if you are at *nums[i]*, you can jump to any *nums[i + j]* where:

- $0 \le j \le nums^{(i)}$
- $i + j \lt n$

Return the minimum number of jumps to reach *nums[n - 1]*. The test cases are generated such that you can reach *nums[n - 1]*.

**Example:**

```
Input: nums = [2, 3, 1, 1, 4];
Output: 2;
```

**Constraints:**

$1 \le n \le 10^4$

$0 \le nums^{(i)} \le 1000$

It's guaranteed that you can reach *nums[n - 1]*.

### Solution

```cpp
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
```

**Explanation:**

Use array $dp$ to show how many steps would be taken to reach position $i$. Use a loop to update the steps dynamically.
