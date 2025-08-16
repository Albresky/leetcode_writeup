# [mid] #0078 子集

思路：

 - 首先，长度为 len 的集合 `nums[]`，其子集数量为 $2^{len}$（即 `1 << len` 种）
 - 可以用二值化的掩码 0/1 来抽象 `num[i]` 是否在子集中
 - 当掩码 `mask[i]` 为 `1` 即 `(mask & (1 << i)) == 1` 时，，表示在集合中

```c++
vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> rtn;
    vector<int> set;

    int len = nums.size();
    for (int mask = 0; mask < (1 << len); ++mask) {
        set.clear();
        for (int i = 0; i < len; ++i) {
            if (mask & (1 << i)) {
                set.push_back(nums[i]);
            }
        }
        rtn.emplace_back(set);
    }
    return rtn;
}
```

**DFS 递归回溯算法**

思路一致：可以用二值化的掩码 0/1 来抽象 `num[i]` 是否在子集中。

其中 **回溯** 思想的关键在于：当返回到上一次 i 时，需要将已入子集的元素移除，来模拟二值化掩码为0时，元素不加入子集的情形。


```c++
class SolutionDFS {
   private:
    int len;
    vector<vector<int>> rtn;
    vector<int> set;

    void dfs(int i, vector<int> &nums) {
        if (i == len) {
            rtn.emplace_back(set);
            return;
        }
        // 掩码为 1，将元素纳入子集
        set.emplace_back(nums[i]);
        dfs(i + 1, nums);

        // 掩码为 0，不纳入元素
        set.pop_back(); // 由于这里是回溯回来的，需要将前一步已纳入的元素移除。
        dfs(i + 1, nums);
    }

   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        len = nums.size();
        dfs(0, nums);
        return rtn;
    }
};
```