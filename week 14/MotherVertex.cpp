/*Given a directed graph, write an algorithm and a program to find mother
vertex in a graph. A mother vertex is a vertex v such that there exists a path
from v to all other vertices of the graph.*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int v) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            DFS(graph, visited, neighbor);
        }
    }
}

int findMotherVertex(int V, vector<vector<int>>& graph) {
    vector<bool> visited(V, false);
    int lastFinishedVertex = 0;

    // Step 1: Find a candidate mother vertex
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFS(graph, visited, i);
            lastFinishedVertex = i;
        }
    }

    // Step 2: Verify the candidate
    fill(visited.begin(), visited.end(), false);
    DFS(graph, visited, lastFinishedVertex);

    for (bool v : visited) {
        if (!v)
            return -1; // Not a mother vertex
    }

    return lastFinishedVertex;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);
    cout << "Enter edges (from to):\n";
    for (int i = 0; i < E; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int motherVertex = findMotherVertex(V, graph);
    if (motherVertex == -1)
        cout << "No Mother Vertex Found" << endl;
    else
        cout << "Mother Vertex is: " << motherVertex << endl;

    return 0;
}
