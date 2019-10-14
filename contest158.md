# contest158
## Q1
https://leetcode.com/contest/weekly-contest-158/problems/split-a-string-in-balanced-strings/   
计数，easy
## Q2 
https://leetcode.com/problems/queens-that-can-attack-the-king/  
写了八个循环。很憨。   
```
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        r, c = king
        res = []
        grid = [[0]*8 for _ in range(8)]
        for q in queens:
            grid[q[0]][q[1]] = 1
            
        for i in range(c+1, 8):
            if grid[r][i] == 1:
                res.append([r, i])
                break
        
        for i in range(c-1, -1, -1):
            if grid[r][i] == 1:
                res.append([r, i])
                break
        
        for i in range(r+1, 8):
            if grid[i][c] == 1:
                res.append([i, c])
                break
        
        for i in range(r-1, -1, -1):
            if grid[i][c] == 1:
                res.append([i, c])
                break
        
        i = r-1
        j = c+1
        while i >= 0 and j < 8:
            if grid[i][j] == 1:
                res.append([i, j])
                break
            i -= 1
            j += 1
        
        i = r-1
        j = c-1
        while i >= 0  and j >= 0:
            if grid[i][j] == 1:
                res.append([i, j])
                break
            i -= 1
            j -= 1
            
        i = r+1
        j = c+1
        while i < 8 and j < 8:
            if grid[i][j] == 1:
                res.append([i, j])
                break
            i += 1
            j += 1
            
        i = r+1
        j = c-1
        while i < 8 and j >= 0:
            if grid[i][j] == 1:
                res.append([i, j])
                break
            i += 1
            j -= 1
        return res
            
        
```
更好的解法：  
https://leetcode.com/problems/queens-that-can-attack-the-king/discuss/403687/Java-short-and-concise-beat-100   
## Q3 
```
A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.
Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
```  
原来是dp，太难了
https://leetcode.com/problems/dice-roll-simulation/discuss/403736/ChineseC%2B%2B-1223.   
三维dp，初始化，边界条件，值得学习的太多了。
## Q4
https://leetcode.com/problems/maximum-equal-frequency/   
https://leetcode.com/problems/maximum-equal-frequency/discuss/403628/Easy-Python-Solution-Concise-10-lines-Explained-O(N)   

