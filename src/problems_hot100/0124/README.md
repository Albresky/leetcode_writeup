# [hard] 0124 二叉树中的最大路径和

## 思路

递归遍历树中的节点 `node`，假如它在最大路径和的路径 `path` 中，那么该过程 `node` 可能会充当两种角色之一：

 - *"父节点 - `node`"* 在 `path`中：用于获得以 `node` 为根的最大路径和（单边）
 - *"左子节点最大和 - `node` - 右子节点最大和"* **构成** `path`：用于计算以 `node` 为汇的最大路径和（双边）

对应地，我们需要在递归过程中考虑这两种情况：

```cpp
int maxSum(TreeNode *node) {
    if (!node) return 0;
    
    auto maxLeft = max(maxSum(node->left), 0);
    auto maxRight = max(maxSum(node->right), 0);

    auto sumTmp = max(sumMax, node->val + maxLeft + maxRight);
    sumMax = max(sumTmp, sumMax);               // Update sumMax

    return node->val + max(maxLeft, maxRight);  // Max path from `self`
}

```