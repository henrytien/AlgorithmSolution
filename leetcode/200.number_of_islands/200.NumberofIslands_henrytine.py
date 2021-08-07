# Source : https://leetcode.com/problems/number-of-islands/
# Author : henrytine
# Date   : 2020-07-29

##################################################################################################### 
#
# Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is 
# surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may 
# assume all four edges of the grid are all surrounded by water.
# 
# Example 1:
# 
# Input: grid = [
#   ["1","1","1","1","0"],
#   ["1","1","0","1","0"],
#   ["1","1","0","0","0"],
#   ["0","0","0","0","0"]
# ]
# Output: 1
# 
# Example 2:
# 
# Input: grid = [
#   ["1","1","0","0","0"],
#   ["1","1","0","0","0"],
#   ["0","0","1","0","0"],
#   ["0","0","0","1","1"]
# ]
# Output: 3
#####################################################################################################

# Tag Search, DFS
# Time complexity: O(mn)
# Space complexity: O(mn)
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        w = len(grid)
        if w == 0:
            return 0
        l = len(grid[0])
        ans = 0
        for y in range(w):
            for x in range(l):
                if grid[y][x] == '1':
                    ans += 1
                    self.dfs(grid, x, y, l, w)
        return ans

    def dfs(self, grid, x, y, l, w):
        if x < 0 or y < 0 or x >= l or y >= w or grid[y][x] == '0':
            return
        grid[y][x] = '0'
        self.dfs(grid, x-1, y, l, w)
        self.dfs(grid, x+1, y, l, w)
        self.dfs(grid, x, y-1, l, w)
        self.dfs(grid, x, y+1, l, w)