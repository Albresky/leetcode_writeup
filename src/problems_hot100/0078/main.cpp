#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> rtn;
        vector<int> set;

        int len = nums.size();
        for (int mask = 0; mask < (1 << len); ++mask) {
            set.clear();
            for (int i = 0; i < len; ++i) {
                if (mask & (1 << i)) {
                    set.push_back(nums[i]);
                }
            }
            rtn.emplace_back(set);
        }
        return rtn;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    auto rtn = s.subsets(nums);
    for (auto &v : rtn) {
        for (auto &n : v) cout << n << " ";
        cout << endl;
    }
    return 0;
}