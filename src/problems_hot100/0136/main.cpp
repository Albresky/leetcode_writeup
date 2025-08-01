#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto& num : nums) ans ^= num;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single number is: " << s.singleNumber(nums) << endl;
    return 0;
}