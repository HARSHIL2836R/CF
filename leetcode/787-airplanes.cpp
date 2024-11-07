#include <bits/stdc++.h>
using namespace std;
// Incorrect Solution
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using PII = pair<int,int>;
        vector<vector<PII>> adj(n+1);
        for (auto& tup: flights){
            adj[tup[0]].push_back({tup[1],tup[2]});
        }
        vector<int> sp(n+1,INT_MAX);
        vector<int> level(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        set<PII,greater<PII>> rbt;
        rbt.insert({0,src});
        sp[src] = 0;
        int lvl = 0;
        while (!rbt.empty()){
            int v = rbt.begin()->second;
            rbt.erase(rbt.begin());
            for (auto [w,k]: adj[v]){
                if (visited[w]) continue;
                level[w] = lvl;
                rbt.erase({sp[w],w});
                sp[w] = sp[v] + k;
                rbt.insert({sp[w],w});
            }
            visited[v] = true;
            lvl++;
        }
        if (sp[dst] == INT_MAX || level[dst] > k) return -1;
        return sp[dst];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> flights{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n=4, src = 0, dst = 3, k = 1;
    cout << sol.findCheapestPrice(n,flights,src,dst,k);
}

// Actual Solution
// typedef tuple<int,int,int> ti;
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         vector<vector<pair<int,int>>>vp(n);
//         for(const auto&f:flights)   vp[f[0]].emplace_back(f[1],f[2]);
//         priority_queue<ti,vector<ti>,greater<ti>>pq;
//         pq.emplace(0,src,K+1);
//         while(!pq.empty()){
//             auto [cost,u,stops] = pq.top();
//             pq.pop();
//             if(u==dst)  return cost; Reached in required number of stops
//             if(!stops)  continue; If no more stops are allowed (stops == 0), continue to the next iteration.
//             for(auto to:vp[u]){
//                 auto [v,w] = to;
//                 pq.emplace(cost+w,v,stops-1);
//             }
//         }
//         return -1;
//     }
// };