#include <limits.h>

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   private:
    bool dfs(TreeNode *root, long long min, long long max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }

   public:
    bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }
};

int main() {
    auto root = new TreeNode(2);
    auto n1 = new TreeNode(1);
    auto n2 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    Solution s;
    auto res = s.isValidBST(root);
    cout << res;
    return 0;
}