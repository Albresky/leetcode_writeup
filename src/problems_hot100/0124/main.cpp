#include <math.h>

#include <iostream>
#include <limits>

#include "../../Helper/TreeNode.h"
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
    int sumMax = INT_MIN;

    int maxSum(TreeNode *node) {
        if (!node) return 0;
        auto maxLeft = max(maxSum(node->left), 0);
        auto maxRight = max(maxSum(node->right), 0);

        auto sumTmp = max(sumMax, node->val + maxLeft + maxRight);
        sumMax = max(sumTmp, sumMax);               // Update sumMax
        return node->val + max(maxLeft, maxRight);  // Max path from `self`
    }

   public:
    int maxPathSum(TreeNode *root) {
        auto v = maxSum(root);
        return sumMax;
    }
};

int main() {
    vector<string> val{"-10", "9", "20", "null", "null", "15", "7"};
    auto tree = vec2tree<TreeNode, string, int>(val);
    Solution s;
    cout << s.maxPathSum(tree) << endl;
    return 0;
}
