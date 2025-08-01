#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> brk{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        unordered_set<char> lhs{'(', '[', '{'};
        unordered_set<char> rhs{')', ']', '}'};
        stack<char> st;
        for (char ch : s)
        {
            if (st.empty() || lhs.find(ch)!=lhs.end())
                st.push(ch);
            else
            {
                auto c = st.top();
                if (brk[c] == ch)
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};

int main()
{

    string s = "()[]{}";
    Solution solution;
    cout << solution.isValid(s) << endl;
    return 0;
}