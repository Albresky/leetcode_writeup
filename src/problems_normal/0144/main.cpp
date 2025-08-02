#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define TB1

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
    void dfs(vector<int> &rtn, TreeNode *node) {
        if (node == nullptr) return;
        rtn.emplace_back(node->val);
        dfs(rtn, node->left);
        dfs(rtn, node->right);
    }

   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> rtn;
        dfs(rtn, root);
        return rtn;
    }
};

class SolutionIter {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> rtn;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node == nullptr) continue;
            rtn.emplace_back(node->val);
            s.push(node->right);
            s.push(node->left);
        }
        return rtn;
    }
};

int main() {
    auto root = new TreeNode;
    auto p = root;

#ifdef TB1
    // [1, nullptr, 2, 3]
    p->val = 1;
    p->right = new TreeNode(2);
    p = p->right;
    p->left = new TreeNode(3);
#elif defined(TB2)
    // [1,2,3,4,5,null,8,null,null,6,7,9]
    p->val = 1;
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    auto r = p->right;
    p = p->left;
    p->left = new TreeNode(4);
    p->right = new TreeNode(5);
    p = p->right;
    p->left = new TreeNode(6);
    p->right = new TreeNode(7);
    p = r;
    p->right = new TreeNode(8);
    p = p->right;
    p->left = new TreeNode(9);
#elif defined(TB3)
    // []
    root = nullptr;
#else
    cerr << "Err: No valid test case defined!" << endl;
    exit(1);
#endif
    // Solution s;
    SolutionIter s;
    auto rtn = s.preorderTraversal(root);
    for (auto v : rtn) {
        cout << v << ' ';
    }
    return 0;
}
