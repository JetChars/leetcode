// C/C++ File
// AUTHOR:   jetchars
// FILE: cpp/703_Kth_Largest_Element_in_a_Stream/kthLargestElementInAStream.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-12-23 00:01:56
// MODIFIED: 2018-12-23 02:35:58
/*
Design a class to find the kth largest element in a stream. Note that it is the
kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an
integer array nums, which contains initial elements from the stream. For each
call to the method KthLargest.add, return the element representing the kth
largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ≥ k-1 and k ≥ 1.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  int size;
  KthLargest(int k, vector<int> nums) {
    size = k;
    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
      if (pq.size() > k)
        pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > size)
      pq.pop();
    return pq.top();
  }
}; // namespace stdclassKthLargest

int main() {
  int k = 3;
  vector<int> arr{4, 5, 8, 2};
  KthLargest *kthLargest = new KthLargest(k, arr);
  int input[]{3, 5, 10, 9, 4};
  for (auto j : input) {
    cout << "input: " << j << endl;
    /* cout << "current heap: "; */
    /* for (auto i : kthLargest->heap) */
    /*   cout << i << ' '; */
    /* cout << endl; */
    cout << "evict: " << kthLargest->add(j) << endl; // returns 4
  }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
