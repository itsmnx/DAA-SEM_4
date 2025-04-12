#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle\n";
    } else {
        cout << "Graph does not contain a cycle\n";
    }

    return 0;
}
