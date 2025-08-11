#include <iostream>
#include <vector>

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
    void dfs(TreeNode *node, TreeNode *list) {
        if (!node) return;
        auto lnode = node->left;
        auto rnode = node->right;
        list = node;
        list = list->right;
        dfs(lnode, list);
        dfs(rnode, list);
    }

   public:
    void flatten(TreeNode *root) {
        TreeNode *nodelist = nullptr;
        dfs(root, nodelist);
    }
};

int main() {
    vector<string> val{"1", "2", "5", "3", "4", "null", "6"};
    auto tree = vec2tree<TreeNode, string, int>(val);
    Solution s;
    s.flatten(tree);
    auto p = tree;
    while (p) {
        cout << p->val << " ";
        p = p->right;
    }
    return 0;
}