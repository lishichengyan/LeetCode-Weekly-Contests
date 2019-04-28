class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        
        # dfs找grid[r0][c0]的connected component，如果这个位置是border，染色
        
        def is_border(grid, i, j):
            if i == 0 or i == nr - 1 or j == 0 or j == nc - 1:
                return True
            target = grid[i][j]
            left = grid[i][j-1]
            right = grid[i][j+1]
            top = grid[i-1][j]
            down = grid[i+1][j]
            if left != target or right != target or top != target or down != target:
                return True
            return False
            
        def dfs(grid, i, j, target, visited, color):
            if i < 0  or i >= nr or j < 0 or j >= nc:
                return
            if visited[i][j]:
                return
            if target != grid[i][j]:
                return
            visited[i][j] = 1
            
            if is_border(grid, i, j):
                # grid[i][j] = color  # dont do that!
                should_color[i][j] = 1
            dfs(grid, i, j+1, target, visited, color)
            dfs(grid, i, j-1, target, visited, color)
            dfs(grid, i-1, j, target, visited, color)
            dfs(grid, i+1, j, target, visited, color)
        
        nr = len(grid)
        nc = len(grid[0])
        visited = [[0]*nc for _ in range(nr)]
        should_color = [[0]*nc for _ in range(nr)]
        
        dfs(grid, r0, c0, grid[r0][c0], visited, color)
        
        for i in range(nr):
            for j in range(nc):
                if should_color[i][j]:
                    grid[i][j] = color
        
        return grid
