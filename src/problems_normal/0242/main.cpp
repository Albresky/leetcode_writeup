#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<string, int> mcount;
        for(int i=0; i<s.length(); ++i){
            auto strkey = string{s[i]};
            if(mcount.find(strkey) != mcount.end())
                mcount[strkey] += 1;
            else
                mcount[strkey] = 1;
        }
        for(int j=0; j<t.length(); ++j){
            auto strkey = string{t[j]};
            if(!mcount.count(strkey)) return false;
            else --mcount[strkey];
            if(mcount[strkey] < 0) return false;
        }
        int sum = 0;
        for(auto& p: mcount) sum += p.second;
        if(!sum) return true;
        return false;
    }
};


// Fastest solution
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> count;
        for(char c : s) count[c]++;
        for(char c : t) {
            if(count[c] == 0) return false;
            count[c]--;
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool result = solution.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}