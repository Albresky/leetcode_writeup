# (easy) 0094 二叉树的中序遍历

### 着色法

```cpp
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
```

- 中序遍历(左中右)：
```cpp
s.push(node->right);
s.push(node);
s.push(node->left);
```

- 前序遍历(中左右)：
```cpp
s.push(node);
s.push(node->right);
s.push(node->left);
```

- 后序遍历(左右中)：
```cpp
s.push(node->left);
s.push(node->right);
s.push(node);
```