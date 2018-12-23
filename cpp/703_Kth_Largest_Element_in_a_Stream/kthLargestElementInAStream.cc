// C/C++ File
// AUTHOR:   jetchars
// FILE: cpp/703_Kth_Largest_Element_in_a_Stream/kthLargestElementInAStream.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-12-23 00:01:56
// MODIFIED: 2018-12-23 02:32:15
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
#include <vector>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

class KthLargest {
public:
  vector<int> heap;
  int size;

  KthLargest(int k, vector<int> nums) {
    size = k;
    heap.reserve(k * 2);
    for (int i : nums) {
      add(i);
    }
  }

  int add(int val) {
    if (heap.size() < size) {
      heap.push_back(val);
      push_heap(heap.begin(), heap.end(), cmp);
    } else {
      int smallest = heap.front();
      if (smallest < val) {
        pop_heap(heap.begin(), heap.end(), cmp);
        heap[size - 1] = val;
        push_heap(heap.begin(), heap.end(), cmp);
      }
    }
    return heap[0];
  }
}; // namespace stdclassKthLargest

int main() {
  int k = 3;
  vector<int> arr{4, 5, 8, 2};
  KthLargest *kthLargest = new KthLargest(k, arr);
  int input[]{3, 5, 10, 9, 4};
  for (auto j : input) {
    cout << "input: " << j << endl;
    cout << "current heap: ";
    for (auto i : kthLargest->heap)
      cout << i << ' ';
    cout << endl;
    cout << "evict: " << kthLargest->add(j) << endl; // returns 4
  }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
