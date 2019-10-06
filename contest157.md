# contest157 
第一次全做完，虽然参考了朋友的。。。
## 5213. Play with Chips 
```
There are some chips, and the i-th chip is at position chips[i].

You can perform any of the two following types of moves any number of times (possibly zero) on any chip:

Move the i-th chip by 2 units to the left or to the right with a cost of 0.
Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
There can be two or more chips at the same position initially.

Return the minimum cost needed to move all the chips to the same position (any position).

 

Example 1:

Input: chips = [1,2,3]
Output: 1
Explanation: Second chip will be moved to positon 3 with cost 1. First chip will be moved to position 3 with cost 0. Total cost is 1.
Example 2:

Input: chips = [2,2,2,3,3]
Output: 2
Explanation: Both fourth and fifth chip will be moved to position two with cost 1. Total minimum cost will be 2.
 

Constraints:

1 <= chips.length <= 100
1 <= chips[i] <= 10^9
```
```
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even, odd = 0, 0
        for c in chips:
            if c%2 == 0:
                even += 1
            else:
                odd += 1
        return min(even, odd)
```

## 1218. Longest Arithmetic Subsequence of Given Difference 
```
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

 

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
Example 3:

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 

Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
```
```
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        d = collections.defaultdict(int)
        n = len(arr)
        
        dp = [1]*n
        
        for i in range(0, n):
            if arr[i] - difference in d:
                dp[i] = max(dp[i], dp[d[arr[i] - difference]] + 1)
            d[arr[i]] = i
        
        return max(dp)
```


## 1219. Path with Maximum Gold 
```
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.
```
```
class Solution {
public:
    int ans = 0;
    vector<vector<int>> seen;
    vector<vector<int>> sums;
    
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || seen[i][j])
            return 0;
        seen[i][j] = 1;
        int ans = max(max(dfs(grid, m, n, i + 1, j), dfs(grid, m, n, i, j + 1)), max(dfs(grid, m, n, i - 1, j), dfs(grid, m, n, i, j - 1)));
        seen[i][j] = 0;
        return grid[i][j] + ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m <= 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        seen = tmp;
        sums = tmp;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    sums[i][j] = dfs(grid, m, n, i, j);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, sums[i][j]);
            }
        }
        
        return ans;
    }
};
```


## 1220. Count Vowels Permutation 
```
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4
```
```
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        count = 0
        ca_prev = 1
        ce_prev = 1
        ci_prev = 1
        co_prev = 1
        cu_prev = 1
        
        ca = 0
        ce = 0
        ci = 0
        co = 0
        cu = 0
        
        for i in range(n-1):
            ca = cu_prev + ce_prev + ci_prev
            ce = ca_prev + ci_prev
            ci = co_prev + ce_prev
            co = ci_prev
            cu = ci_prev + co_prev
            
            ca_prev = ca
            ce_prev = ce
            ci_prev = ci
            co_prev = co
            cu_prev = cu
        return (ca_prev + ce_prev + ci_prev + co_prev + cu_prev) % (10**9 + 7)
            
        
```
