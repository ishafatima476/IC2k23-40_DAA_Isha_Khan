#include <iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

int parent[10];

int find(int x) {
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}

int main() {
    Edge edges[100];
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initially, each vertex is its own parent
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        // Check whether adding edge forms a cycle
        if (a != b) {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].weight << endl;

            parent[a] = b;

            totalCost += edges[i].weight;
            count++;
        }

        if (count == n - 1)
            break;
    }

    if (count != n - 1) {
        cout << "Graph is not connected";
    }
    else {
        cout << "Minimum Cost: " << totalCost;
    }

    return 0;
}
