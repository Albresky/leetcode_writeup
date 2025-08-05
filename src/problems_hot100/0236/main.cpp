#include <iostream>
#include <vector>

#include "../../Helper/TreeNode.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   private:
    TreeNode* ancestor = nullptr;
    bool traverse(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return false;
        auto inleft = traverse(node->left, p, q);
        auto inright = traverse(node->right, p, q);
        if ((node == p || node == q) && (inleft || inright) || inleft && inright) ancestor = node;
        if (node == p || node == q || inleft || inright)
            return true;
        else
            return false;
    }

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return ancestor;
    }
};

int main() {
    vector<string> root = {"3", "5", "1", "6", "2", "0", "8", "null", "null", "null", "7", "4"};
    TreeNode* tree = vec2tree<TreeNode, string, int>(root);
    auto p = tree->left;
    auto q = tree->right->right;
    Solution s;

    auto ancestor = s.lowestCommonAncestor(tree, p, q);
    cout << ancestor->val << endl;
    return 0;
}