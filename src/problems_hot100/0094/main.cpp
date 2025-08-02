#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

#define TB2

struct TreeNode {
    int val;
    bool visit;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), visit(false), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), visit(false), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), visit(false), left(left), right(right) {}
};

class Solution {
   private:
    void dfs(vector<int> &rtn, TreeNode *node) {
        if (node == nullptr) return;
        dfs(rtn, node->left);
        rtn.emplace_back(node->val);
        dfs(rtn, node->right);
    }

   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> rtn;
        dfs(rtn, root);
        return rtn;
    }
};

class SolutionIter {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> rtn;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node == nullptr) continue;
            if (!node->visit) {
                node->visit = true;
                s.push(node->right);
                s.push(node);
                s.push(node->left);
            } else {
                rtn.emplace_back(node->val);
            }
        }
        return rtn;
    }
};

/**
 * The ListNode Stucture is predefined in LeetCode OJ and we 
 * cannot change it. So we have to mantain the visit status
 * with a new data structure.
*/
class SolutionIterHashTable {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> rtn;
        stack<TreeNode *> s;
        unordered_map<TreeNode *, bool> visit;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node == nullptr) continue;
            if (!visit[node]) {
                visit[node] = true;
                s.push(node->right);
                s.push(node);
                s.push(node->left);
            } else {
                rtn.emplace_back(node->val);
            }
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
    auto rtn = s.inorderTraversal(root);
    for (auto v : rtn) {
        cout << v << ' ';
    }
    return 0;
}
