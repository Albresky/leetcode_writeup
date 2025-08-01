#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = -1;
        int sum = 0, minlen = 999999;
        int len = nums.size();
        int flag = false;
        for (; l < len; ++l) {
            if (l > 0) sum -= nums[l - 1];
            while (r + 1 < len && sum < target) {
                sum += nums[r + 1];
                r++;
            }
            if (sum >= target) {
                flag = true;
                minlen = min(minlen, r - l + 1);
            }
        }
        return flag ? minlen : 0;
    }
};

int main() {
    Solution s;
    int target = 7;
    vector<int> v{2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(target, v) << endl;
    return 0;
}