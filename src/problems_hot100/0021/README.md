## 关于 LeetCode OJ 系统的内存判断误差

```cpp
while (p1 != nullptr && p2 != nullptr) {
    if (p1->val < p2->val) {
        pr->next = p1;
        p1 = p1->next;
        pr = pr->next; // <--
    } else {
        pr->next = p2;
        p2 = p2->next;
        pr = pr->next; // <--
    }
}
```        


本题发现 `pr = pr->next;` 这行代码放在 `if-else` 分支内外部对 LeetCode OJ 系统的内存判断有显著影响。具体来说：
 - 如果放在 `if-else` 分支内，内存评估会超过 `88%` 的选手；
 - 如果放在 `if-else` 分支外，内存评估仅超过 `10%` 的选手。

通过 WindowsAPI 获取当前进程的内存使用情况，在 Visual Studio 2022环境下进行编译后，发现二者的内存使用量是一致的，测试源码参考 [./main_vs.cpp](./main_vs.cpp)。
