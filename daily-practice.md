# since 03/23/2020  
## 813 Largest Sum of Averages  
类似1335，1278，```dp(now) = MAX/MIN{dp(previous) + cost(previous, now)}```     
我的解析：https://leetcode.com/problems/largest-sum-of-averages/discuss/561368/Python3-dp(now)-MAXMINdp(previous)-%2B-cost(previous-to-now)
## 1335 Minimum Difficulty of a Job Schedule  
类似1278，dp都是之前的各个状态加一个代价函数取极值。   
我的解析：https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/559774/Python-Detailed-explanation-with-examples     
```
dp[i][j]: min difficulty to do 0,1,...,i jobs in j days

dp[i][j] = min { dp[m][j-1] + maxcost(m+1, i)}, where m < i
```
## 1278 Palindrome Partitioning III  
需要考虑之前所有可能的dp  
`dp[i][k] = dp[j][k-1] + cost(j, i-1), 0<= j < i`   
cost的计算可以用dp优化  
和813类似  
## 727 Minimum Window Subsequence (附加题)
还没做 
## 1143 Longest Common Subsequence  
**母题**  
## 1312 Minimum Insertion Steps to Make a String Palindrome  
lcs变种  
## 1092 Shortest Common Supersequence    
lcs变种  
## 1035 Uncrossed Lines       
lcs变种，dp式和lcs一模一样  
## 712	Minimum ASCII Delete Sum for Two Strings           
edit distance变种  
## 583	Delete Operation for Two Strings       
edit distance变种  
## 115	Distinct Subsequences    
dp计数  
## 72	Edit Distance    
**母题**   
