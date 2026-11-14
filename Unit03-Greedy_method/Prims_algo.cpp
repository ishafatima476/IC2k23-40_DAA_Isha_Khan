#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10];
    int visited[10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    visited[0] = 1;

    int edges = 0, totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = 9999;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < min) {

                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a == -1) {
            cout << "Graph is not connected";
            return 0;
        }

        cout << a << " - " << b
             << " : " << min << endl;

        visited[b] = 1;
        totalCost += min;
        edges++;
    }

    cout << "Minimum Cost: " << totalCost;

    return 0;
}
