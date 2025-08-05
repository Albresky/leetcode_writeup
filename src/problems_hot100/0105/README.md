# [mid] #0105 从前序与中序遍历序列构造二叉树

## [LeetCode 官方题解](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/255811/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/?envType=study-plan-v2&envId=top-100-liked)

### 核心思想：像玩拼图一样分而治之

想象一下，我们手里有两份关于一棵树的“情报”：

1.  **前序遍历 (Preorder)**: `[根, [左子树], [右子树]]`
2.  **中序遍历 (Inorder)**: `[[左子树], 根, [右子树]]`

这两份情报的关键区别是什么？

**黄金法则：前序遍历的第一个元素，永远是当前这棵树（或子树）的根节点！**

这就是我们的突破口。每次我们想拼出一棵树，都遵循以下三步：

1.  **找老大 (Find the Root)**：从前序遍历的列表里，把第一个元素揪出来，它就是这棵树的老大（根节点）
2.  **分地盘 (Split the Subtrees)**：拿着这个“老大”的值，去中序遍历的列表里找到它。在中序遍历中，这个“老大”左边的所有元素都属于它的左子树；右边的所有元素都属于它的右子树
3.  **交给小弟 (Recurse)**：现在你有了左子树的“全体成员名单”（来自中序遍历）和右子树的“全体成员名单”。同时，因为你知道了左、右子树各有多少个节点，你也能从前序遍历的列表中，准确地切分出属于左子树和右子树的那部分。现在，你就得到了两个规模更小的、一模一样的问题。把这两个“子问题”递归地交给“小弟”（也就是下一次函数调用）去解决就行了

-----

### 跟着一个例子，手动走一遍

我们用题解中的例子，但把步骤拆解得更细。

  * `preorder = [3, 9, 20, 15, 7]`
  * `inorder = [9, 3, 15, 20, 7]`

#### 第 1 轮：构建整棵树

1.  **找老大**：看 `preorder`，第一个是 `3`。好，`3` 就是整棵树的根节点。我们先 `new TreeNode(3)`

2.  **分地盘**：去 `inorder` 里找 `3`

      * `inorder = [ [9], 3, [15, 20, 7] ]`
      * 我们发现，`3` 的左边是 `[9]`，右边是 `[15, 20, 7]`
      * 这意味着：
          * 根节点 `3` 的**左子树**只有一个节点：`9`
          * 根节点 `3` 的**右子树**有三个节点：`15`, `20`, `7`

3.  **交给小弟（准备递归）**：

      * 我们知道了左子树有 **1** 个节点，右子树有 **3** 个节点
      * 现在我们回头看 `preorder`，根据这个数量来切分它。`preorder` 的结构是 `[根, [左子树前序], [右子树前序]]`
      * `preorder = [3, [9], [20, 15, 7]]`
          * 根 `3` 占了 1 位
          * 紧接着的 **1** 个元素 `[9]`，就是左子树的前序遍历结果
          * 再后面的 **3** 个元素 `[20, 15, 7]`，就是右子树的前序遍历结果

    现在我们有了两个全新的、更小的问题：

      * **子问题A (构建左子树)**:
          * `preorder` 部分: `[9]`
          * `inorder` 部分: `[9]`
      * **子问题B (构建右子树)**:
          * `preorder` 部分: `[20, 15, 7]`
          * `inorder` 部分: `[15, 20, 7]`

    接下来，根节点 `3` 就等着这两个子问题完成，然后把返回的子树挂在自己的 `left` 和 `right` 上。

#### 第 2 轮：解决子问题 B (右子树)

现在我们只看子问题 B 的数据：

  * `preorder` 部分: `[20, 15, 7]`
  * `inorder` 部分: `[15, 20, 7]`

重复上面的三步：

1.  **找老大**：看这个 `preorder` 部分，第一个是 `20`。好，`20` 就是这个右子树的根节点。我们 `new TreeNode(20)`

2.  **分地盘**：去 `inorder` 部分里找 `20`

      * `inorder` 部分 = `[ [15], 20, [7] ]`
      * 我们发现，`20` 的左边是 `[15]`，右边是 `[7]`
      * 这意味着：
          * 节点 `20` 的**左子树**只有一个节点：`15`
          * 节点 `20` 的**右子树**只有一个节点：`7`

3.  **交给小弟（准备再次递归）**：

      * 我们知道了左子树有 **1** 个节点，右子树有 **1** 个节点
      * 回头看 `preorder` 部分，根据数量切分：`[20, [15], [7]]`
          * 根 `20` 占了 1 位
          * 紧接着的 **1** 个元素 `[15]`，是 `20` 的左子树的前序遍历
          * 再后面的 **1** 个元素 `[7]`，是 `20` 的右子树的前序遍历

    又产生了两个终极简单的子问题：

      * 构建 `20` 的左子树：`preorder=[15]`, `inorder=[15]` -\> 返回一个 `TreeNode(15)`
      * 构建 `20` 的右子树：`preorder=[7]`, `inorder=[7]` -\> 返回一个 `TreeNode(7)`

当这两个问题解决后，`TreeNode(15)` 会被挂在 `20` 的 `left`，`TreeNode(7)` 会被挂在 `20` 的 `right`。然后，这个以 `20` 为根的子树就构建完成了。

最终，这个完成的子树（根是`20`）会被返回给第 1 轮的调用，挂在根节点 `3` 的 `right` 上。左子树 `9` 也是同理。于是整棵树就拼好了。

-----

### 代码是如何实现这个过程的？

代码其实就是上面思路的直接翻译。

```cpp
class Solution {
private:
    // 哈希表，用来瞬间（O(1)时间）查到任何一个值在中序遍历里的位置
    // key是节点值, value是它在inorder数组中的下标
    unordered_map<int, int> index; 

public:
    // 这才是核心的递归函数
    // preorder_left, preorder_right:  当前处理的前序遍历子数组的左右边界（下标）
    // inorder_left, inorder_right:   当前处理的中序遍历子数组的左右边界（下标）
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
                          int preorder_left, int preorder_right, 
                          int inorder_left, int inorder_right) {
        
        // 递归的终止条件：如果左边界大于右边界，说明这是个空数组，没有节点了，返回空指针
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 1. 找老大：前序遍历子数组的第一个元素就是根
        int preorder_root_val = preorder[preorder_left];
        // 创建根节点
        TreeNode* root = new TreeNode(preorder_root_val);
        
        // 2. 分地盘：用哈希表快速找到根在中序遍历子数组中的位置
        int inorder_root_idx = index[preorder_root_val];
        
        // 3. 计算左子树的节点数量。这是最关键的一步！
        // 在中序遍历中，从左边界到根节点位置的前一个，都是左子树的成员。
        int size_left_subtree = inorder_root_idx - inorder_left;
        
        // 4. 交给小弟（递归调用）
        
        // 构建左子树
        // - 新的前序范围：从老的前序范围的左边界+1 开始，数 size_left_subtree 个。
        //   所以右边界是 preorder_left + size_left_subtree
        // - 新的中序范围：从老的中序范围的左边界 开始，到 根的前一个位置 结束。
        root->left = myBuildTree(preorder, inorder, 
                                 preorder_left + 1, preorder_left + size_left_subtree, 
                                 inorder_left, inorder_root_idx - 1);
        
        // 构建右子树
        // - 新的前序范围：紧跟在左子树的后面。左边界是 preorder_left + size_left_subtree + 1
        // - 新的中序范围：从 根的后一个位置 开始，到 老的中序范围的右边界 结束。
        root->right = myBuildTree(preorder, inorder, 
                                  preorder_left + size_left_subtree + 1, preorder_right,
                                  inorder_root_idx + 1, inorder_right);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 预处理，把inorder数组的值和下标存入哈希表，方便快速查找
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        // 第一次调用，处理的是完整的两个数组
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
```

**对代码的解读：**

  * **哈希表 `index`**： 它的作用就是加速“分地盘”这一步。如果没有它，每次我们找到根节点 `val`后，都得去 `inorder` 数组里遍历一遍来找它的位置，效率很低。有了哈希表，`index[val]` 一下就能拿到位置，非常快
  * **边界参数**：`preorder_left`, `preorder_right` 这些参数，就是用来在原始数组上“虚拟地”切出子数组，避免了每次递归都真的创建新的小数组，节省了空间和时间
  * **`size_left_subtree` 的计算**：`inorder_root_idx - inorder_left` 这个公式就是计算中序遍历里，根左边有多少个元素。这个数量 `size` 是连接前序和中序的关键桥梁，因为一个子树的节点数是固定的，所以它在前序和中序里的长度也是一样的

### 总结

1.  **核心原理**：`前序找根，中序分左右`
2.  **关键步骤**：通过中序遍历确定左右子树的**大小（size）**
3.  **递归实现**：用这个 size 回到前序遍历数组中，准确地切出对应左右子树的部分，然后把这两部分作为新的、更小的问题递归处理
4.  **代码优化**：用哈希表存中序遍历的索引来提速；用边界参数来模拟数组切分以省空间

