# contest 155
## 1200. Minimum Absolute Difference
```
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
```
easy, 排序+哈希表
```
class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        tot = len(arr)
        if tot < 2:
            return []
        arr.sort()
        
        diff = abs(arr[1] - arr[0])
        res = []
        
        for i in range(tot):
            if i+1 < tot:
                diff = min(diff, abs(arr[i+1] - arr[i]))
        
        d = collections.defaultdict(int)
        for num in arr:
            d[num] = 1
        
        for i in range(tot):
            if (arr[i] + diff) in d:
                res.append([arr[i], arr[i]+diff])
        return res
        
```
## 1201. Ugly Number III
https://leetcode.com/contest/weekly-contest-155/problems/ugly-number-iii/  
```
Write a program to find the n-th ugly number.

Ugly numbers are positive integers which are divisible by a or b or c.

 

Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
Example 4:

Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984
 

Constraints:

1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
It's guaranteed that the result will be in range [1, 2 * 10^9]
```
没做出来。看答案是二分。
## 1202. Smallest String With Swaps 
```
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
```
做出来了还是很开心！并查集。
```
class DSU(object):
    def __init__(self):
        self.par = list(range(100001))  # modify to list(range(1001)) for python 3.0 and above!!!
        self.rnk = [0] * 100001

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        elif self.rnk[xr] < self.rnk[yr]:
            self.par[xr] = yr
        elif self.rnk[xr] > self.rnk[yr]:
            self.par[yr] = xr
        else:
            self.par[yr] = xr
            self.rnk[xr] += 1
        return True

    
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        uf = DSU()
        for p in pairs:
            uf.union(p[0], p[1])
        
        d = collections.defaultdict(list)
        tot = len(s)
        for i in range(tot):
            p = uf.find(i)
            if p != i:
                d[p].append(i)
        
        l = list(s)
        ans = s
        for k in d:
            tmp = [k]
            chs = [s[k]]
            for j in d[k]:
                tmp.append(j)
                chs.append(s[j])
    
            tmp.sort()
            chs.sort()
            idx = 0
            for p in tmp:
                l[p] = chs[idx]
                idx += 1
            ans = min(ans, "".join(l))
            
        return ans
```
## 1203. Sort Items by Groups Respecting Dependencies  
https://leetcode.com/contest/weekly-contest-155/problems/sort-items-by-groups-respecting-dependencies/    
直接没看
