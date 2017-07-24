// C/C++ File
// AUTHOR:   jetchars
// FILE:     two_sum.cc
// ROLE:     TODO (some explanation)
// CREATED:  2017-07-24 23:03:42
// MODIFIED: 2017-07-24 23:55:27

/* Given an array of integers, return indices of the two numbers such that they add up to a specific target. */

/* You may assume that each input would have exactly one solution, and you may not use the same element twice. */

/* Example: */
/* Given nums = [2, 7, 11, 15], target = 9, */

/* Because nums[0] + nums[1] = 2 + 7 = 9, */
/* return [0, 1]. */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> r;
        for(int i=0; i<nums.size(); ++i ){
            if(m.find(nums[i])==m.end() ){
                m[target-nums[i]]=i;
            }else{
                r.push_back(m[nums[i]]);
                r.push_back(i);
                break;
            }
        }
        return r;
    }
};
