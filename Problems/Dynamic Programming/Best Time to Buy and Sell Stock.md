# Best Time to Buy and Sell Stock

[Category: Dynamic Programming]

Given an array **prices** where **prices[i]** is the price of a given stock on the $i^{th}$ day. The profit should be maximized by choosing a single day to buy one stock ans choosing a different day in the future to sell the stock.

Return the maximum profit it can achieve from this transaction. If no profit, return $0$.

**Example:**

```
Input: prices = [7, 1, 5, 3, 6, 4];
Output: 5;
```

**Constraints:**

$1 \le l_{prices} \le 10^5$

$0 \le prices_i \le 10^4$

### Solution

```cpp
class BestTimeToBuyAndSellStock {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for(int price : prices) {
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;
    }
};
```

**Explanation:**

To achieve the maximized profit, the day of the minimum price should be selected. Use a pointer to record the minimum price that ahead of the sells day. And use another pointer to find the maximum price after the buys day.
