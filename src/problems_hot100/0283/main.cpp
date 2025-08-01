#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        int len = nums.size();
        while (r != len) {
            if (nums[r]) swap(nums[l++], nums[r]);
            r++;
        }
        return;
    }
};

// move non-zeroes to the frontend, set the rest with `0`
class Solution2 {
   public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0, p = 0;
        int len = nums.size();
        while (p != len) {
            if (nums[p]) nums[cur++] = nums[p];
            p++;
        }
        while (cur != len) {
            nums[cur++] = 0;
        }
    }
};

int main() {
    vector<int> tb{0, 3, 2, 1};
    Solution2 s;
    s.moveZeroes(tb);
    for (auto& n : tb) cout << n << " ";
    return 0;
}