#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
   private:
    int V;
    list<int> *adj;
    vector<int> indegree;
    vector<int> seq;

   public:
    Graph(int V) : V(V), adj(new list<int>[V]), indegree(V, 0) {}

    ~Graph() { delete[] adj; }

    void addEdge(int src, int tar) {
        adj[src].push_back(tar);
        ++indegree[tar];
    }

    vector<int> topo() {
        queue<int> q;
        for (int i = 0; i < V; ++i)
            if (!indegree[i]) q.push(i);

        int count = 0;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            ++count;
            seq.push_back(v);
            for (auto nadj : adj[v]) {
                if (!(--indegree[nadj])) {
                    q.push(nadj);
                }
            }
        }
        return count == V ? seq : vector<int>();
    }
};

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        Graph g(numCourses);
        for (auto &v : prerequisites) g.addEdge(v[1], v[0]);

        return g.topo();
    }
};

class GraphDFS {
   private:
    int V;
    bool ring;
    list<int> *adj;
    vector<int> visit;
    vector<int> seq;

   public:
    GraphDFS(int V) : V(V), ring(false), adj(new list<int>[V]), visit(V, 0) {}

    ~GraphDFS() { delete[] adj; }

    void addEdge(int src, int tar) { adj[src].push_back(tar); }

    void dfs(int v) {
        visit[v] = 1;
        for (auto u : adj[v]) {
            switch (visit[u]) {
                case 0:
                    dfs(u);
                    if (ring) return;
                    break;
                case 1:
                    ring = true;
                    return;
                default:
                    break;
            }
        }
        visit[v] = 2;
        seq.push_back(v);
    }

    vector<int> topo() {
        int i = 0;
        while (i < V && !ring) {
            if (!visit[i]) dfs(i);
            ++i;
        }

        if (!ring) {
            reverse(seq.begin(), seq.end());
            return seq;
        }

        return vector<int>();
    }
};

class SolutionDFS {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        GraphDFS g(numCourses);
        for (auto &v : prerequisites) g.addEdge(v[1], v[0]);

        return g.topo();
    }
};

int main() {
    const int num = 5;
    vector<vector<int>> courses = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    SolutionDFS s;
    auto rtn = s.findOrder(num, courses);
    for (auto c : rtn) cout << c << " ";
    return 0;
}