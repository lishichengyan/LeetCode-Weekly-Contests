// medium
// 我的解法是愚蠢的暴力
int numSubarraysWithSum(vector<int>& A, int S) {
    int tot = A.size();
    if(tot <= 0) return 0;

    int cnt = 0;
    for(int i = 0; i < tot; i++){
        int sum = A[i];
        if(sum == S) cnt++;
        for(int j = i + 1; j < tot; j++){
            sum += A[j];
            if(sum == S){
                cnt++;
                if(j + 1 < tot && A[j + 1] == 1) break;
            }
        }
    }

    return  cnt;
}

// 然而可以用哈希表
// 答案来自排名第二的pentester
int numSubarraysWithSum(vector<int> &A, int S) {
  std::unordered_map<int, int> c;
  int r = 0, t = 0;
  c[0]++;
  for (int x : A) {
    t += x;
    r += c[t-S];
    c[t]++;
  }
  return r;
}
