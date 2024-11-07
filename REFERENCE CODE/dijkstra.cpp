#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void dijkstra(int source, const std::vector<std::vector<std::pair<int, int>>>& graph) {
    int n = graph.size();
    std::vector<int> distance(n, INF);
    std::vector<bool> visited(n, false);
    distance[source] = 0;

    using PII = std::pair<int, int>; // First element is the cost, second is the node
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if already visited
        if (visited[u]) continue;

        // Mark node as visited
        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Output distances
    std::cout << "Vertex Distance from Source\n";
    for (int i = 0; i < n; ++i) {
        std::cout << i << " \t\t " << distance[i] << "\n";
    }
}

int main() {
    int n = 5; // Number of vertices
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    // Example graph
    graph[0].emplace_back(1, 2);
    graph[0].emplace_back(4, 1);
    graph[1].emplace_back(2, 3);
    graph[2].emplace_back(3, 6);
    graph[4].emplace_back(1, 2);
    graph[4].emplace_back(2, 4);

    dijkstra(0, graph); // Run Dijkstra's algorithm from vertex 0

    return 0;
}
