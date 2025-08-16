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