#include <iostream>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        /**
         * 状态定义：f(i) 表示到达第 i 阶的不同方法数。
         * ST: f(i) = f(i-1) + f(i-2)。第 i 阶可以从 i-1 阶或 i-2 阶到达。
         * e.g. f(0) = 1
         *      f(1) = 1
         *      f(2) = f(0) + f(1) = 1 + 1 = 2
         *      f(3) = f(1) + f(2) = 1 + 2 = 3
         *      f(4) = f(2) + f(3) = 2 + 3 = 5
         */
        int /* f(i-2) */ f_2 = 0, /* f(i-1) */ f_1 = 0, f = 1;
        for (int i = 1; i <= n; ++i) {
            f_2 = f_1;
            f_1 = f;
            f = f_2 + f_1;
        }
        return f;
    }
};

int main() {
    Solution s;
    s.climbStairs(5);
    return 0;
}