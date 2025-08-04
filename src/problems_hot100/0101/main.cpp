#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
class SolutionRecur {
   private:
    bool dfs(const TreeNode *l, const TreeNode *r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        return l->val == r->val && dfs(l->left, r->right) && dfs(l->right, r->left);
    }

   public:
    bool isSymmetric(TreeNode *root) { return dfs(root, root); }
};

// Iterative
class SolutionIter {
   private:
    bool travel(TreeNode *l, TreeNode *r) {
        queue<TreeNode *> q;
        if (!l || !r) return true;
        q.push(l);
        q.push(r);
        while (!q.empty()) {
            auto ln = q.front();
            q.pop();
            auto rn = q.front();
            q.pop();
            if (!ln && !rn) continue;
            if (!ln || !rn || ln->val != rn->val) return false;

            q.push(ln->left);
            q.push(rn->right);
            q.push(ln->right);
            q.push(rn->left);
        }
        return true;
    }

   public:
    bool isSymmetric(TreeNode *root) { return travel(root, root); }
};

int main() {
    auto root = new TreeNode(2);
    auto n1 = new TreeNode(3);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(4);
    auto n4 = new TreeNode(5);
    auto n5 = new TreeNode(5);
    auto n6 = new TreeNode(4);
    auto n7 = new TreeNode(6);
    auto n8 = new TreeNode(6);
    root->left = n1;
    root->right = n2;
    root->left->left = n3;
    root->left->right = n4;
    root->right->left = n5;
    root->right->right = n6;
    root->left->right->right = n7;
    root->right->left->left = n8;

    // SolutionRecur s;
    SolutionIter s;
    auto rtn = s.isSymmetric(root);
    cout << rtn << endl;
    return 0;
}