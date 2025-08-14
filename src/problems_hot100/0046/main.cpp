#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    int n;
    vector<vector<int>> rtn;

    void dfs(vector<int> &nums, vector<int> &path, vector<bool> &used) {
        if (path.size() == n) {
            // com.push_back(nums[begin]);
            rtn.emplace_back(path);
        }
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path, used);
            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        if (!n) return {};

        vector<int> path;
        vector<bool> used(nums.size(), false);
        dfs(nums, path, used);

        return rtn;
    }
};

class SolutionSwap {
   private:
    int n;
    vector<vector<int>> rtn;

    void dfs(int index, vector<int> &nums) {
        if (index == n) {
            rtn.emplace_back(nums);
            return;
        }
        for (int i = index; i < n; ++i) {
            swap(nums[index], nums[i]);
            dfs(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }

   public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        if (!n) return {};

        dfs(0, nums);

        return rtn;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4};
    SolutionSwap s;
    auto rtn = s.permute(nums);
    for (auto &v : rtn) {
        for (auto &n : v) cout << n << " ";
        cout << endl;
    }
    return 0;
}