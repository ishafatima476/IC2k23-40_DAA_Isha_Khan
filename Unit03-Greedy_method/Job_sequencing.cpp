#include <iostream>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    Job jobs[100];
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline and profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort jobs according to profit
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    bool slot[100] = {false};
    char result[100];

    int totalProfit = 0;

    // Select jobs before their deadlines
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {

            if (j <= n && !slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nSelected jobs: ";

    for (int i = 1; i <= n; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }

    cout << "\nMaximum Profit: " << totalProfit;

    return 0;
}
