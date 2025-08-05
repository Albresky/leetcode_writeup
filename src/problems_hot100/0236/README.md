# [mid] #0236 二叉树的最近公共祖先

### 解法一：递归

```cpp
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
```

- 思路：
  - 使用递归遍历二叉树，`p` 和 `q` 的最近公共祖先只存在 2 种情况：
    - 1. `p` 和 `q` 分别在当前节点的左右子树中
    - 2. 当前节点是 `p` 或 `q`，且另一个节点（`q` 或 `p`）在当前节点的子树中
  - 如果当前节点满足上述任一条件，则将其设置为最近公共祖先
- 时间复杂度：O(n)，其中 n 是二叉树的节点数
- 空间复杂度：O(h)，其中 h 是二叉树的高度（递归栈的深度）

