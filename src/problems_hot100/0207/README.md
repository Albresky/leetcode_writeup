# [mid] #0207 课程表

思路：
 - 只需判断DAG图中是否有环即可
 - BFS算法中，多个非连通分量不必额外考虑（假如存在入度为0的孤立顶点，它自动会被加到queue中），那么假如不存在环，最终 `count`的值必然等于`V`
    ```c++
    queue<int> q;
    for (int i = 0; i < V; ++i)
        if (!indegree[i]) q.push(i);
    
    int count = 0;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            ++count;
            // ...
    ```
 - DFS算法，记录正在搜索的路径，一旦搜索到未结束的路径（标记为1），代表有环，直接flag false。