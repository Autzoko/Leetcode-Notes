# Generate Parentheses

[Catagory: Dynamic Programming]

Given $n$ paris of parentheses, write a function to *generate all combinations of well-formed parentheses*.

**Example:**

```
Input: n = 3;
Output: ["((()))", "(()())", "(())()", "()(())", "()()()"];
```

**Constraints:**

$1 \le n \le 8$

### Solution

```cpp
class GenerateParentheses {
public:
    vector<string> res;
    vector<string> generateParentheses(int n) {
        if(n <= 0) return res;
        p("", n, n);
        return res;
    }

    void p(string str, int left, int right) {
        if(left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        if(left == right) {
            p(str + "(", left - 1, right);
        } else {
            if(left > 0) {
                p(str + "(", left - 1, right);
            }
            p(str + ")", left, right - 1);
        }
    }
};
```

**Explanation:**

The number of remained left parenthese must be less or equal to the number of remained right parenthese. If the number of remained left parenthese equals to the remained right one, the next can only be a left parenthese. If the number of remained left parenthese is less than the right one, the next one can be either a left parenthese or a right parenthese. Use **recursions** to complete.
