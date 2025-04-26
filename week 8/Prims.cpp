#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int primMST(int V, vector<vector<pair<int, int>>> &adj) {
    vector<int> key(V, INT_MAX);      // Minimum weights to add vertices
    vector<bool> inMST(V, false);     // Track vertices included in MST
    key[0] = 0;                        // Start from vertex 0
    int totalCost = 0;

    for (int count = 0; count < V; ++count) {
        int u = -1;

        // Find the vertex with the smallest key value not yet included in MST
        for (int i = 0; i < V; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;
        totalCost += key[u];

        // Update key values of adjacent vertices
        for (auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
            }
        }
    }

    return totalCost;
}

int main() {
    int V, E;
    cout << "Enter number of cities (vertices): ";
    cin >> V;
    cout << "Enter number of roads (edges): ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter each road as: city1 city2 cost" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected graph
    }

    int minCost = primMST(V, adj);
    cout << "Minimum cost to connect all cities: " << minCost << endl;

    return 0;
}
