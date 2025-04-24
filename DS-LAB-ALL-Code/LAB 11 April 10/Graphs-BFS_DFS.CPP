#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void DFSUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) DFSUtil(v, adj, visited);
    }
}

void DFS(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V, false);
    cout << "DFS: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove for directed graph
    }

    int start = 0;
    BFS(adj, start, V);
    DFS(adj, start, V);

    return 0;
}
