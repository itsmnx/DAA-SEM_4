#include<iostream>
#include<vector>

using namespace std;

class Graph {
    int v;
    vector<int>* adj;

public:
    Graph(int vertices) {
        v = vertices;
        adj = new vector<int>[v];
    }

    void addedge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(int source, int dest, vector<bool>& visited) {
        if (source == dest) {
            return true;
        }
        visited[source] = true;
        for (int neighbour : adj[source]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, dest, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    void checkpath(int source, int dest) {
        vector<bool> visited(v, false);
        if (dfs(source, dest, visited)) {
            cout << "Yes!!" << endl;
        }
        else {
            cout << "NO!!" << endl;
        }
    }

    ~Graph() {
        delete[] adj;  // Proper memory deallocation
    }
};

int main() {
    int test;
    cout << "Enter number of test cases: ";
    cin >> test;
    while (test--) {

        int v, e;
        cout << "Enter number of vertices: ";
        cin >> v;
        cout << "Enter number of edges: ";
        cin >> e;

        Graph g(v);
        cout << "Enter edges: ";
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;  // Correct input syntax
            g.addedge(a, b);
        }

        int src, dest;
        cout << "Enter source and destination to check path: ";
        cin >> src >> dest;  // Correct input syntax
        g.checkpath(src, dest);
    }
    return 0;
}

