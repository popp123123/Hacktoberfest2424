#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int knapsack01(int W, int N, int v[], int w[]) {
    int DP[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    // Initialize DP table
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            DP[i][j] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i <= N; i++) {
        for (int j = W; j >= w[i - 1]; j--) {
            DP[i][j] = max(DP[i - 1][j], v[i - 1] + DP[i - 1][j - w[i - 1]]);
        }
    }

    // Return maximum value for W capacity and N items
    return DP[N][W];
}

int main() {
    int N = 3; // Number of items
    int W = 10; // Knapsack capacity
    int v[] = {300, 200, 400}; // Item values
    int w[] = {2, 1, 5}; // Item weights

    printf("Maximum value in Knapsack: %d\n", knapsack01(W, N, v, w));

    return 0;
}
