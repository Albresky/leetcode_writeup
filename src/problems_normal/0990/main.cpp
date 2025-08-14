#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
   private:
    int n;
    vector<int> parent;
    vector<int> rank;

    int find(int idx) {
        if (parent[idx] != idx) parent[idx] = find(parent[idx]);
        return parent[idx];
    }

   public:
    UnionFind(int n) : n(n), parent(vector<int>(n)), rank(vector<int>(n, 0)) { iota(parent.begin(), parent.end(), 0); }

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
        }
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
   public:
    bool equationsPossible(vector<string> &equations) {
        UnionFind u(26);
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                u.unite(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (auto &neq : equations) {
            if (neq[1] == '!' && u.connected(neq[0] - 'a', neq[3] - 'a')) return false;
        }
        return true;
    }
};

int main() {
    // vector<string> equations{"a==b", "b==c", "a!=c"};
    vector<string> equations{"a==b", "e==c", "b==c", "a!=e"};
    Solution s;
    cout << s.equationsPossible(equations) << endl;
    return 0;
}