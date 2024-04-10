#include <vector>
#include <string>
using namespace std;

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