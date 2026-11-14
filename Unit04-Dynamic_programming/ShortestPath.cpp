#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (i != j && cost[i][j] == 0) {
                cost[i][j] = 9999;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == 9999)
                cout << "INF ";
            else
                cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
