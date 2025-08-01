#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (auto& str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        for (auto it = map.begin(); it != map.end(); ++it) {
            res.emplace_back(it->second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> tb{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = s.groupAnagrams(tb);
    for (auto& vec : ans) {
        for (auto& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}