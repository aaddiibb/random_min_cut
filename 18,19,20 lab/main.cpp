#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int findParent(int node, vector<int>& parent) {
    while (parent[node] != node) node = parent[node];
    return node;
}

int minCut(int V, vector<Edge> edges) {
    vector<int> parent(V + 1);
    for (int i = 1; i <= V; i++) parent[i] = i;

    int remaining = V;

    while (remaining > 2) {
        if (edges.empty()) return 0;

        int idx = 0;

        int u = findParent(edges[idx].u, parent);
        int v = findParent(edges[idx].v, parent);

        if (u == v) {
            edges.erase(edges.begin());
            continue;
        }

        parent[v] = u;
        remaining--;

        vector<Edge> newEdges;
        for (auto &e : edges) {
            int a = findParent(e.u, parent);
            int b = findParent(e.v, parent);
            if (a != b) newEdges.push_back({a, b});
        }

        edges.swap(newEdges);
    }

    return edges.size();
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    edges.reserve(E);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cout << minCut(V, edges) << endl;
    return 0;
}
