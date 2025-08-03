#include <iostream>
#include <queue>
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

/* Porting from binary tree level-order traveral */

// DFS solution
class SolutionDFS {
   private:
    vector<vector<int>> ans;

    void dfs(TreeNode *node, int level) {
        if (!node) return;
        if (level >= ans.size())
            ans.push_back({node->val});
        else
            ans[level].emplace_back(node->val);
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

   public:
    vector<int> rightSideView(TreeNode *root) {
        int level = 0;
        dfs(root, level);
        vector<int> rtn;
        for (const auto &vec : ans) rtn.emplace_back(vec.back());
        return rtn;
    }
};

// BFS solution
class SolutionBFS {
   public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> lnodes;
        while (!q.empty()) {
            int size = q.size();
            lnodes.push_back(vector<int>());
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                lnodes.back().emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        vector<int> rtn;
        for (const auto &vec : lnodes) rtn.emplace_back(vec.back());
        return rtn;
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
    SolutionBFS s;
    auto rtn = s.rightSideView(root);

    for (const auto &val : rtn) cout << val << ' ';
    return 0;
}