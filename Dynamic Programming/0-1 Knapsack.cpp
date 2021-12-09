// wt and val are 1 based indexed vectors
int knapSack(int W, vector<int> wt, vector<int> val, int n) {
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
