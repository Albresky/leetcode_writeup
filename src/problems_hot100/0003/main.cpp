#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class SolutionSlidingWindow {
   public:
     int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;

        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

class SolutionIndexingArray{
public:
int lengthOfLongestSubstring(string s) {
        int index[128] = {0};  // 记录每个字符最后出现位置+1
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            left = max(left, index[ch]);  // 更新左边界
            maxLen = max(maxLen, right - left + 1);
            index[ch] = right + 1;
        }
        return maxLen;
    }

};

int main() {
    vector<string> tb{"", "a", "ab", "aab", "abcc", "abcde",  "abccddef", "aabcddefghijkk12345"};
    SolutionSlidingWindow s;
    for (auto& str : tb) cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}