#include <iostream>
using namespace std;

int n;
int cost[10][10];
int dp[1024][10];

int tsp(int mask, int pos) {

    // All cities visited
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    // If already calculated
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = 999999;

    // Visit unvisited cities
    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0) {

            int newCost = cost[pos][city] +
                tsp(mask | (1 << city), city);

            if (newCost < ans) {
                ans = newCost;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Initialize DP table
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0);

    cout << "Minimum travelling cost: " << result;

    return 0;
}
