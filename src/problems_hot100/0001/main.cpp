#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rtn = {0, 1};
        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i+1; j <= nums.size() - 1; j++)
            {
                if(target == (nums[i] + nums[j])){
                    rtn[0]=i; 
                    rtn[1]=j;
                    return rtn;
                }
            }
        }
        return rtn;
    }
};

// Fastest solution
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};

class mySolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> nmap;
       for(int i = 0; i < nums.size(); ++i){
        int part = target - nums[i];
        if(nmap.find(part) != nmap.end())
            return {nmap[part], i};
        nmap[nums[i]] = i; // flag current value
       }
       return {};
    }
};

int main() {
    mySolution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << ": "
         << result[0] << ", " << result[1] << endl;
    return 0;
}