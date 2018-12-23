// C/C++ File
// AUTHOR:   jetchars
// FILE:     cpp/743_network_delay_time/networkDelayTime.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-12-23 14:45:28
// MODIFIED: 2018-12-23 18:10:59

/*
   There are N network nodes, labelled 1 to N.

   Given times, a list of travel times as directed edges times[i] = (u, v, w),
where u is the source node, v is the target node, and w is the time it takes for
a signal to travel from source to target.

   Now, we send a signal from a certain node K. How long will it take for all
nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
 */

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

auto cmp = [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; };

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
    map<int, vector<vector<int>>> graph;
    for (auto d : times) {
      graph[d[0]].push_back(vector<int>{d[1], d[2]});
    }
    map<int, int> dist;
    q.push(vector<int>{K, 0});
    while (!q.empty()) {
      const auto &p = q.top();
      int n = p[0];
      int t = p[1];
      q.pop();
      if (dist.find(n) != dist.end()) {
        continue;
      }
      dist[n] = t;
      for (auto d : graph[n]) {
        cout << d[0] << " " << d[1] << endl;
        if (dist.find(d[0]) == dist.end()) {
          q.push(vector<int>{d[0], d[1] + t});
        }
      }
    }
    if (dist.size() != N) {
      return -1;
    }
    auto x =
        max_element(dist.begin(), dist.end(),
                    [](const pair<int, int> &p1, const pair<int, int> &p2) {
                      return p1.second < p2.second;
                    });
    return x->second;
  }
};

int main() {
  Solution s{};
  vector<int> v1{2, 1, 1};
  vector<int> v2{2, 3, 1};
  vector<int> v3{3, 4, 1};
  vector<vector<int>> times = {v1, v2, v3};
  cout << s.networkDelayTime(times, 4, 2) << endl;
  return 0;
}
