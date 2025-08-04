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
    bool ok = false;

    void dfs(TreeNode *node, int sum, const int targetSum) {
        if (!node) return;
        sum += node->val;
        if (sum == targetSum && !node->left && !node->right) {
            ok = true;
        } else {
            dfs(node->left, sum, targetSum);
            dfs(node->right, sum, targetSum);
        }
    }

   public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        dfs(root, 0, targetSum);
        return root && ok;
    }
};