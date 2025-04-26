#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

void printPath(vector<int>& parent, int v) {
    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
}

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle.\n";
            return;
        }
    }

    for (int i = 0; i < V; i++) {
        if (i == src) continue;
        cout << "Path from " << i << " to Akshay's house (node " << src << "): ";
        if (dist[i] == INF) {
            cout << "No path exists.\n\n";
        } else {
            printPath(parent, i);
            cout << "\nMinimum Distance: " << dist[i] << "\n\n";
        }
    }
}

int main() {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        int V, E;
        cout << "Enter number of vertices: ";
        cin >> V;

        cout << "Enter number of edges: ";
        cin >> E;

        vector<Edge> edges;

        cout << "Enter edges (u v w): \n";
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w}); // undirected graph
        }

        int src;
        cout << "Enter Akshay's house location (source vertex): ";
        cin >> src;

        bellmanFord(V, edges.size(), edges, src);

        cout << "Do you want to test another case? (y/n): ";
        cin >> choice;
        cout << "\n";
    }

    return 0;
}
