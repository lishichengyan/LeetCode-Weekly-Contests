// medium
// dp
// 来自第5名x____x 
int minFallingPathSum(vector<vector<int>>& a) {
    int inf = 100100100;
    int n = a.size();
    vector<vector<int>> dp(n + 10, vector<int>(n + 10, inf));
    for (int i = 0; i <= n; ++i) dp[0][i] = a[0][i];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            if (j + 1 < n) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
        }
    }
    int ret = inf;
    for (int x : dp[n - 1]) ret = min(ret, x);
    return ret;
}
