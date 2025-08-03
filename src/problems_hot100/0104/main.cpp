#include <iostream>
#include <vector>

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
    int level = 0;

    void dfs(const TreeNode *node, int depth) {
        if (!node) return;
        if (depth >= level) ++level;
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

   public:
    int maxDepth(TreeNode *root) {
        dfs(root, 0);
        return level;
    }
};

int main() {
    // [1,2,3,null,5,null,4]
    auto root = new TreeNode(1);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(5);
    auto n4 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    root->left->right = n3;
    root->right->right = n4;
    // SolutionDFS s;
    Solution s;
    auto rtn = s.maxDepth(root);
    cout << rtn << endl;
    return 0;
}