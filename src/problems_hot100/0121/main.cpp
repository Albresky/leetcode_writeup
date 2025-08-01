#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        /**
         * ST: f(i) = max(0, prices[i] - min(f(0..i-2)))
         */
        int min_p = 10000;
        int max_p = 0;
        int len = prices.size();
        for (int i = 0; i < len; ++i) {
            if (prices[i] < min_p) min_p = prices[i];
            auto price = max(0, prices[i] - min_p);
            max_p = max(max_p, price);
        }
        return max_p;
    }
};

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    // vector<int> prices{7, 6, 4, 3, 1};
    Solution s;
    auto mprofit = s.maxProfit(prices);
    cout << mprofit << endl;
    return 0;
}