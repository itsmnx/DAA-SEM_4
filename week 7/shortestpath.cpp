#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // We will use a large number for "no path"

// Function to find the shortest path with exactly k edges
int shortestPathWithKEdges(int V, vector<vector<pair<int, int>>>& adjList, int src, int dest, int k) {
    // dp[i][v] stores the shortest path from src to v with exactly i edges
    vector<vector<int>> dp(k + 1, vector<int>(V, INF));
    
    // The distance to the source with 0 edges is 0
    dp[0][src] = 0;

    // Iterate through all edge counts from 1 to k
    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < V; u++) {
            if (dp[e - 1][u] != INF) { // If there's a valid path to u with (e-1) edges
                for (const auto& edge : adjList[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    dp[e][v] = min(dp[e][v], dp[e - 1][u] + weight);
                }
            }
        }
    }

    // If dp[k][dest] is still INF, there is no path with exactly k edges
    return dp[k][dest] == INF ? -1 : dp[k][dest];
}

int main() {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        int V;
        cout << "Enter the number of vertices: ";
        cin >> V;

        // Create adjacency list where each vertex points to a list of (neighbor, weight) pairs
        vector<vector<pair<int, int>>> adjList(V);

        cout << "Enter the graph (edges with weights) in the form 'u v w' (where u->v with weight w):\n";
        cout << "Enter -1 -1 -1 to stop entering edges.\n";

        while (true) {
            int u, v, w;
            cin >> u >> v >> w;
            if (u == -1 && v == -1 && w == -1) break; // Stop when input is -1 -1 -1
            adjList[u].push_back({v, w});
        }

        int src, dest, k;
        cout << "Enter source and destination vertices: ";
        cin >> src >> dest;

        cout << "Enter number of edges (k): ";
        cin >> k;

        int result = shortestPathWithKEdges(V, adjList, src, dest, k);

        if (result == -1) {
            cout << "No path of length " << k << " is available.\n";
        } else {
            cout << "The weight of the shortest path from " << src << " to " << dest << " with exactly " << k << " edges is: " << result << "\n";
        }

        cout << "Do you want to test another case? (y/n): ";
        cin >> choice;
        cout << "\n";
    }

    return 0;
}
