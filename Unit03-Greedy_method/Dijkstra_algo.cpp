#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10];
    int distance[10];
    bool visited[10] = {false};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    // Initialize distances
    for (int i = 0; i < n; i++) {
        distance[i] = 9999;
    }

    distance[source] = 0;

    // Find shortest distances
    for (int count = 0; count < n; count++) {

        int min = 9999;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] > 0 &&
                distance[u] + cost[u][v] < distance[v]) {

                distance[v] = distance[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : ";

        if (distance[i] == 9999)
            cout << "Not reachable";
        else
            cout << distance[i];

        cout << endl;
    }

    return 0;
}
