# [mid] #0210 课程表 Ⅱ

思路：
 - 参考[problems_hot100/0207](../../problems_hot100/0207/README.md)
 - DFS 方法的路径记录顺序为压栈操作，出栈时即为拓扑排序结果，返回 `vector` 时需要反转栈。