#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
   private:
    int n;
    int count;
    vector<int> parent;
    vector<int> rank;

    int find(int idx) {
        if (parent[idx] != idx) parent[idx] = find(parent[idx]);
        return parent[idx];
    }

   public:
    UnionFind(int n) : n(n), count(n), parent(vector<int>(n)), rank(vector<int>(n, 0)) {
        iota(parent.begin(), parent.end(), 0);
    }

    void unite(int x, int y) {
        auto rootx = find(x);
        auto rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else if (rank[rooty] < rank[rootx]) {
                parent[rooty] = rootx;
            } else {
                parent[rootx] = rooty;
                ++rank[rooty];
            }
            --count;
        }
    }

    int province() { return count; }
};

class Solution {
   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int nr = isConnected.size();
        if (!nr) return 0;
        UnionFind u(nr);
        for (int r = 0; r < nr; ++r)
            for (int c = r + 1; c < nr; ++c) {
                if (isConnected[r][c]) {
                    u.unite(r, c);
                }
            }
        return u.province();
    }
};

class SolutionDFS {
   private:
    int cities = 0;
    vector<bool> visit;

    void dfs(const vector<vector<int>> &isConnected, int i) {
        for (int j = 0; j < cities; ++j) {
            if (isConnected[i][j] && !visit[j]) {
                visit[j] = true;
                dfs(isConnected, j);
            }
        }
    }

   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int cities = isConnected.size();
        if (!cities) return 0;
        visit.resize(cities);

        int provinces = 0;
        for (int i = 0; i < cities; ++i) {
            if (!visit[i]) {
                dfs(isConnected, i);
                ++provinces;
            }
        }
        return provinces;
    }
};

int main() {
    // vector<vector<int>> cities{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    // vector<vector<int>> cities{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> cities{{1, 0, 1, 0, 0}, {0, 1, 0, 0, 1}, {1, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 0, 1}};
    // Solution s;
    SolutionDFS s;
    cout << s.findCircleNum(cities) << endl;
    return 0;
}