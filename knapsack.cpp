#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveKnapsack(int capacity, const vector<int>& weights, const
vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i
- 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n);
    vector<int> weights(n);

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Value of item " << i + 1 << ": ";
        cin >> values[i];
    }

    cout << "\nEnter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> weights[i];
    }

    cout << "\nEnter the maximum capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = solveKnapsack(capacity, weights, values, n);
    cout << "Maximum value achievable in knapsack = " << maxValue << endl;

    return 0;
}

