#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution { // A* algorithm is much faster than simple BFS, see leetcode submission
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;

        auto heuristic = [&target](const string& s) { //lambda function
            int h = 0;
            for (int i = 0; i < 4; ++i) {
                int diff = abs(s[i] - target[i]);
                h += min(diff, 10 - diff);
            }
            return h;
        };

        priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, greater<>> pq;
        pq.push({0 + heuristic("0000"), {0, "0000"}});
        unordered_set<string> visited;
        visited.insert("0000");

        while (!pq.empty()) {
            auto [f, gs] = pq.top();
            int g = gs.first;
            string s = gs.second;
            pq.pop();

            if (s == target) return g;
            if (dead.count(s)) continue;

            for (int i = 0; i < 4; ++i) {
                string next1 = s;
                string next2 = s;

                next1[i] = (s[i] - '0' + 1) % 10 + '0';
                next2[i] = (s[i] - '0' - 1 + 10) % 10 + '0';

                if (!visited.count(next1) && !dead.count(next1)) {
                    pq.push({g + 1 + heuristic(next1), {g + 1, next1}});
                    visited.insert(next1);
                }

                if (!visited.count(next2) && !dead.count(next2)) {
                    pq.push({g + 1 + heuristic(next2), {g + 1, next2}});
                    visited.insert(next2);
                }
            }
        }

        return -1;
    }
};
