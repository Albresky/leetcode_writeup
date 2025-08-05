#include <iostream>
#include <unordered_map>
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
    unordered_map<int, int> index;
    TreeNode *buildNode(vector<int> &preorder, vector<int> &inorder, int ipl, int ipr, int iil, int iir) {
        if (ipl > ipr) return nullptr;
        auto rootVal = preorder[ipl];
        auto node = new TreeNode(rootVal);
        auto idxRootInorder = index[rootVal];
        auto cnt_l = idxRootInorder - iil;
        // auto cnt_r = iir - index[idxRootInorder];
        node->left = buildNode(preorder, inorder,
                               /* begin index of left tree for preorder */ ipl + 1,
                               /* end index of left tree for preorder */ ipl + cnt_l,
                               /* begin idx of left tree for inorder */ iil,
                               /* end idx of left tree for inorder */ idxRootInorder - 1);
        node->right = buildNode(preorder, inorder,
                                /* begin index of right tree for preorder */ ipl + 1 + cnt_l,
                                /* end index of right tree for preorder */ ipr,
                                /* begin idx of right tree for inorder */ idxRootInorder + 1,
                                /* end idx of right tree for inorder */ ipr);
        return node;
    }

   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) index[inorder[i]] = i;
        return buildNode(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    auto root = s.buildTree(preorder, inorder);
    cout << root->val << endl;
    return 0;
}