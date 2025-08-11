#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int numIsland = 0;

        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++numIsland;
                    dfs(grid, r, c);
                }
            }
        }
        return numIsland;
    }
};

class SolutionBFS {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int numIsland = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++numIsland;
                    grid[r][c] = '0';

                    queue<pair<int, int>> q;  // record surrounding land
                    q.push({r, c});
                    while (!q.empty()) {
                        auto cord = q.front();
                        q.pop();
                        auto rr = cord.first;
                        auto cc = cord.second;
                        if (rr - 1 >= 0 && grid[rr - 1][cc] == '1') {
                            grid[rr - 1][cc] = '0';
                            q.push({rr - 1, cc});
                        }
                        if (rr + 1 < nr && grid[rr + 1][cc] == '1') {
                            grid[rr + 1][cc] = '0';
                            q.push({rr + 1, cc});
                        }
                        if (cc - 1 >= 0 && grid[rr][cc - 1] == '1') {
                            grid[rr][cc - 1] = '0';
                            q.push({rr, cc - 1});
                        }
                        if (cc + 1 < nc && grid[rr][cc + 1] == '1') {
                            grid[rr][cc + 1] = '0';
                            q.push({rr, cc + 1});
                        }
                    }
                }
            }
        }
        return numIsland;
    }
};

class UnionFind {
   private:
    vector<int> parent;
    vector<int> rank;

    int find(int idx) {
        // find root of idx
        // parent[idx] == idx    ==>   idx is root
        if (parent[idx] != idx) {
            parent[idx] = find(parent[idx]);
        }

        // return root
        return parent[idx];
    }

   public:
    int count;

    UnionFind(const vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        count = 0;
        for (int r = 0; r < nr; ++r)
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    parent.emplace_back(r * nc + c);
                    ++count;
                } else
                    parent.emplace_back(-1);
                rank.emplace_back(0);
            }
    }

    void unite(int idx, int idy) {
        auto rootx = find(idx);
        auto rooty = find(idy);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else {
                parent[rootx] = rooty;
                ++rank[rooty];
            }
            --count;
        }
    }
};

class SolutionUnionFind {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * nc + c, (r - 1) * nc + c);
                    if (r + 1 < nr && grid[r + 1][c] == '1') uf.unite(r * nc + c, (r + 1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c + 1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }
        return uf.count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    SolutionBFS s;
    cout << s.numIslands(grid) << endl;
    return 0;
}