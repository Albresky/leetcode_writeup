#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int /*f(i-1)*/ pre = 0, maxAns = nums[0];
        for (auto& num : nums) {
            pre = max(/* f(i-1)+num */ pre + num, /* num */ num);
            // Update the `maxAns` with f(i-1)
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main() {
    vector<int> tb{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    auto ans = s.maxSubArray(tb);
    cout << ans << endl;
    return 0;
}
