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

// 自己写了一下
int minFallingPathSum(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();

    // init and fill the dp array
    vector<vector<int>> dp(m, vector<int>(n + 2, 0));
    for(int i = 0; i < m; i++){
        dp[i][0] = dp[i][n + 1] = INT_MAX;
    }
    for(int i = 1; i <= n; i++){
        dp[0][i] = A[0][i-1];
    }

    // do dp now!
    for(int i = 1; i < m; i++){
        for(int j = 1; j <= n; j++){
            int tmp = min(dp[i-1][j], dp[i-1][j-1]);
            tmp = min(tmp, dp[i-1][j+1]);
            dp[i][j] = A[i][j-1] + tmp;
        }
    }

    // find min in the last row
    int minSum = INT_MAX;
    for(int i = 1; i<= n; i++){
        minSum = min(minSum, dp[m-1][i]);
    }
    return minSum;
}
