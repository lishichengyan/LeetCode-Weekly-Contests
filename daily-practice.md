# since 03/23/2020    
## 730. Count Different Palindromic Subsequences   
去重很烦。  
思路是：
```
首尾字符相同会出现三种情况:   
1. 中间子串不包含相同的字符   
例子: f("bccb") = 2*f("cc") + 2   
2. 中间子串有相同字符，相同字符恰好在子串中间   
例子: f("bcbcb") = 2*f("cbc") + 1  
3. 首尾的邻居相同   
例子: f("bbcabb") = 2*f("bcab") - f("ca")   
用代码来表达就是:
if (s[0] == s[n-1]) {
  l, r = 1, n-2 
  while (l <= n-1 and s[0] != l) l++
  while (r <= n-1 and s[1] != r) r--
  if (l > r) {
    case1
  } elif (l == r) {
    case2
  } else {
    case3
  }
}
首尾字符不相同，f(s) = f(s[0:n-1]) + f(s[1:n]) - f(s[1:n-1])
```
## 516. Longest Palindromic Subsequence (重做)  
## 375. Guess Number Higher or Lower II (重做)   
## 312. Burst Balloons (重做)
## 1105. Filling Bookcase Shelves (重做)    
类似1043      
重点是书的顺序不能乱。     
## 1043. Partition Array for Maximum Sum (重做)   
```dp[i] = max(dp[i-k] + cur_max*k)```，没见过这种类型的dp。  
## 673. Number of Longest Increasing Subsequence   
LIS变形。难点不在于LIS，而在于dp计数，首先要理解dp和count的含义：```dp[i]表示以nums[i]结尾的子数组的LIS的长度，count[i]表示以nums[i]结尾的长度为dp[i]的子序列的个数```，不难想到dp数组一定是一个不会递减的序列，```dp[i]```的取值只有两种可能，一个是```dp[j]```，另一个是```dp[j]+1```，现在如果```nums[i] > nums[j]```，当我们发现```dp[i] == dp[j]```说明需要更新```dp[i]```，即```dp[i] = dp[j]+1```，同时有```count[i] = count[j]```（即，将```nums[i]```添加到```nums[j]```后面可以得到```count[j]```个长度为```dp[i]```的更长的子序列）；如果我们发现```dp[i] == dp[j]+1```，说明```dp[i]```已经被更新过了，进一步说明```nums[0..j-1]```里有某个数比```nums[i]```还小（在这种情况下，我们有```count[i]==count[某个数]```种得到更长子序列的方法数，同时也可以将```nums[i]```添加到```nums[j]```后面，有```count[j]```种方法数，所以总的方法数是```count[i] + count[j]```种）。
## 300. Longest Increasing Subsequence    
**母题**       
nlogn的做法不仅维护了LIS，而且维护的是末尾最小的LIS（便于下一次增长），很妙！      
相关的解答：https://blog.csdn.net/u013178472/article/details/54926531
## 368. Largest Divisible Subset (重做)
需要重做！
## 410. Split Array Largest Sum 
现在对这种分组求最优化的dp还是挺得心应手的，毕竟打完表硬找也能找到规律。    
```
dp[i][j] is the mimimum maximum sum after dividing nums[0..i] into m groups 

dp[i][j] = min(max(dp[k][j-1], cost(k+1, i))) for 0 <= k < i

corner cases:
dp[0][j] is invalid for all valid j
dp[i][0] is invalid for all valid i
dp[i][1] is sum(nums[1:i+1]) for all valid i
```   
sum可以用前缀和优化一下。但这题最妙的做法是二分...
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
## 115	Distinct Subsequences (重做)   
dp计数  
## 72	Edit Distance    
**母题**   
