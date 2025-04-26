#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

void dijkstra(int V, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, minDist = INF;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\tUnreachable\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    char choice;

    do {
        int V;
        cout << "\nEnter number of vertices: ";
        cin >> V;

        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < V; i++) {
            int n;
            cout << "Enter number of neighbors for vertex " << i << ": ";
            cin >> n;
            for (int j = 0; j < n; j++) {
                int v, w;
                cout << "  Enter neighbor " << j + 1 << " and weight (format: vertex weight): ";
                cin >> v >> w;
                adj[i].push_back({v, w});
            }
        }

        int src;
        cout << "Enter source vertex (0 to " << V - 1 << "): ";
        cin >> src;

        dijkstra(V, adj, src);

        cout << "\nDo you want to run another test case? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended.\n";
    return 0;
}
