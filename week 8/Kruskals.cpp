#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Union-Find (Disjoint Set Union) functions
int findParent(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]); // Path compression
    return parent[i];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; ++i)
        parent[i] = i;

    int totalCost = 0;
    int edgesUsed = 0;

    for (Edge e : edges) {
        if (edgesUsed == V - 1)
            break;

        int setU = findParent(parent, e.u);
        int setV = findParent(parent, e.v);

        if (setU != setV) {
            totalCost += e.weight;
            unionSets(parent, rank, setU, setV);
            edgesUsed++;
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

    vector<Edge> edges(E);
    cout << "Enter each road as: city1 city2 cost" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int minCost = kruskalMST(V, edges);
    cout << "Minimum cost to connect all cities: " << minCost << endl;

    return 0;
}
