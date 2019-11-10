## 1252. Cells with Odd Values in a Matrix  
https://leetcode.com/contest/weekly-contest-162/problems/cells-with-odd-values-in-a-matrix/   
直接暴力，easy
## 1253. Reconstruct a 2-Row Binary Matrix   
https://leetcode.com/contest/weekly-contest-162/problems/reconstruct-a-2-row-binary-matrix/   
先填充，然后调整和为1的列：  
```
class Solution(object):
    def reconstructMatrix(self, upper, lower, colsum):
        """
        :type upper: int
        :type lower: int
        :type colsum: List[int]
        :rtype: List[List[int]]
        """
        col = len(colsum)
        mat = [[0] * col for _ in range(2)]
        for j in range(col):
            if colsum[j] == 2:
                mat[0][j] = 1
                mat[1][j] = 1
            elif colsum[j] == 1:
                mat[0][j] = 1
                mat[1][j] = 0
            else:
                pass
        # print(mat)
        us = sum(mat[0])
        ls = sum(mat[1])
        if us == upper and ls == lower:
            return mat
        
        diff = 0
        if us > upper:
            diff = us - upper
        for j in range(col):
            if colsum[j] == 1:
                mat[0][j], mat[1][j] = mat[1][j], mat[0][j]
                diff -= 1
            if diff == 0:
                break
        if sum(mat[0]) != upper or sum(mat[1]) != lower:
            return []
        return mat
```
## 1254. Number of Closed Islands   
https://leetcode.com/contest/weekly-contest-162/problems/number-of-closed-islands/   
dfs染色，然后去掉边界：  
```
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m <= 0:
            return 0
        n = len(grid[0])
        
        seen = [[0]*n for _ in range(m)]
        
        def dfs(i, j, color):
            dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
            grid[i][j] = color
            seen[i][j] = 1
            for d in dirs:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n:
                    continue
                if grid[x][y] == 0 and not seen[x][y]:
                    dfs(x, y, color)
        
        color = 0
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and i != 0 and j != 0 and i != m-1 and j != n-1 and not seen[i][j]:
                    color -= 1
                    dfs(i, j, color)
        # print(grid)
        # print(color)
        s = set()
        for i in range(m):
            if grid[i][0] != 0 and grid[i][0] != 1:
                s.add(grid[i][0])
            if grid[i][n-1] != 0 and grid[i][n-1] != 1:
                s.add(grid[i][n-1])
        for j in range(n):
            if grid[0][j] != 0 and grid[0][j] != 1:
                s.add(grid[0][j])
            if grid[m-1][j] != 0 and grid[m-1][j] != 1:
                s.add(grid[m-1][j])
        # print(s)
        return -color - len(s)
```
## 1255. Maximum Score Words Formed by Letters   
https://leetcode.com/problems/maximum-score-words-formed-by-letters/     
没看  
