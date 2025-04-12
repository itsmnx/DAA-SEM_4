#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1); 

    for (int start = 0; start < V; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; 
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V = 4; 
    vector<vector<int>> adj(V);

    // Example;
    // 0 -- 1
    // |    |
    // 3 -- 2
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    if (isBipartite(V, adj)) {
        cout << "Graph is Bipartite\n";
    } else {
        cout << "Graph is NOT Bipartite\n";
    }

    return 0;
}
