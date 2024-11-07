#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        using PII=pair<int,int>;
        vector<vector<PII>> adj(n+1);
        for (auto& tup: times){
            adj[tup[0]].push_back({tup[1],tup[2]}); // {neighbour, time}
        }
        priority_queue<PII,vector<PII>,greater<PII>> pq; // {score, vertex}
        pq.push({0,k});
        dist[k] = 0;
        while (!pq.empty()){
            int v = pq.top().second;
            pq.pop();
            for (auto& tup: adj[v]){
                if (! visited[tup.first]){
                    pq.push({tup.second+dist[v],tup.first});
                    dist[tup.first] = min(dist[tup.first],tup.second+dist[v]);
                }
            }
            visited[v] = true;
        }
        int max = dist[1];
        for (int i = 1; i< dist.size(); i++){
            if (i == k){
                if (k==dist.size()-1) continue;
                else i++;
            }
            cout<< dist[i]<< " ";
            if (dist[i] == INT_MAX) return -1;
            else max = dist[i]<max ? max : dist[i];
        }
        return max;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec{{1,2,1},{2,1,3}};
    cout<< sol.networkDelayTime(vec,2,2);
}

// Optimal:
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         // cout << "n: " << n << " k: " << k << endl;
//         vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MIN));
//         for (auto &time : times) {
//             int from_node = time[0];
//             int to_node = time[1];
//             int weight = time[2];
//             adjMatrix[from_node - 1][to_node - 1] = weight;
//         }

//         vector<int> dist(n, INT_MAX);
//         vector<int> prev(n, -1);

//         set<pair<int, int>> s;

//         s.insert({0, k - 1});
//         dist[k - 1] = 0;

//         while (!s.empty()) {
//             auto [weight, node] = *s.begin();
//             s.erase(s.begin());

//             for (int child = 0; child < n; child++) {
//                 if (adjMatrix[node][child] == INT_MIN) continue;

//                 if (dist[child] > weight + adjMatrix[node][child]) {
//                     s.erase({dist[child], child});
//                     dist[child] = weight + adjMatrix[node][child];
//                     prev[child] = node;
//                     s.insert({dist[child], child});
//                 }
//             }
//         }

//         int max_time;
//         for (int i = 0; i < n; i++) {
//             if (dist[i] == INT_MAX) return -1;
//             max_time = max(max_time, dist[i]);
//         }

//         return max_time;
//     }
// };
