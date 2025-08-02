#include <math.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> rtn;
        if (root == nullptr) return rtn;
        q.push(root);
        while (!q.empty()) {
            int l = q.size();
            rtn.push_back(vector<int>());
            for (int i = 0; i < l; ++i) {
                auto node = q.front();
                q.pop();
                rtn.back().emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return rtn;
    }
};

class SolutionDFS {
   private:
    vector<vector<int>> ans;

   public:
    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth >= ans.size())
            ans.push_back({root->val});
        else
            ans[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};

int main() {
    auto root = new TreeNode(3);
    auto n1 = new TreeNode(9);
    auto n2 = new TreeNode(20);
    auto n3 = new TreeNode(15);
    auto n4 = new TreeNode(7);
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;
    Solution s;
    auto rtn = s.levelOrder(root);
    for (auto &vec : rtn) {
        if (vec.empty()) cout << "empty" << endl;
        for (auto &v : vec) cout << v << ' ';
        cout << endl;
    }
    return 0;
}