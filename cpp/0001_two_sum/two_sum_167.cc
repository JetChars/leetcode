// C/C++ File
// AUTHOR:   jetchars
// FILE:     0001_two_sum/two_sum_167.cc
// ROLE:     TODO (some explanation)
// CREATED:  2017-07-25 00:04:33
// MODIFIED: 2017-07-25 00:07:20

/* Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number. */

/* The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based. */

/* You may assume that each input would have exactly one solution and you may not use the same element twice. */

/* Input: numbers={2, 7, 11, 15}, target=9 */
/* Output: index1=1, index2=2 */

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
                r.push_back(m[nums[i]]+1);
                r.push_back(i+1);
                break;
            }
        }
        return r;
    }
};

