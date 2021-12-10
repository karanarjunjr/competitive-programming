// wt and val are 1 based indexed vectors
int knapsack_recursive(int W, vector<int> wt, vector<int> val, int n) {
    if (!W or !n)
        return 0;

    if (wt[n] <= W) {
        return max(val[n] + knapsack_recursive(W - wt[n], wt, val, n - 1),
                   knapsack_recursive(W, wt, val, n - 1));
    } else {
        return knapsack_recursive(W, wt, val, n - 1);
    }
}

int knapsack_dp(int W, vector<int> wt, vector<int> val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], val[i] + dp[i - 1][j - wt[i]]);
            } else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}
