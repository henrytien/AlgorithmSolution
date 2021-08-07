# [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

## Question

In a given grid, each cell can have one of three values:

- the value `0` representing an empty cell;
- the value `1` representing a fresh orange;
- the value `2` representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1` instead.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)**

```
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Example 2:**

```
Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

**Example 3:**

```
Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
```

 

**Note:**

1. `1 <= grid.length <= 10`
2. `1 <= grid[0].length <= 10`
3. `grid[i][j]` is only `0`, `1`, or `2`.

## Ideas

Intuition: use a BFS to traverse the neighbors of a rotted orange and count the step. Use a queue to track the rotted orange and loop the queue. 

## Highlights

**Use a queue!**

**How to count the level?**

* Use the size of the queue to add a loop. Plus level by 1 at each loop.
* Use a delimiter, an invalid pair to mark each round. Ex. Pair(-1, -1).
* Add a parameter level to the queue.

## Code

```java
// Source : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Author: Eve
// Date: 2020-08-07

// Method: BFS 
class Triple {
    int row;
    int col;
    int level;
    
    public Triple(int row, int col, int level) {
        this.row = row;
        this.col = col;
        this.level = level;
    }
}

class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        // Initialize the level to -1, since we only count the process as 1.
        int level = -1;
        // Count the fresh in total and check whether the fresh is 0 in the end.
        int fresh = 0;
        boolean[][] visited = new boolean[m][n];
        Queue<Triple> queue = new LinkedList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.offer(new Triple(i, j, level));
                    visited[i][j] = true;  
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // Edge cases.
        // When there's no fresh, return 0.
        if (fresh == 0) {
            return 0;
        }
        int[] directionX = {0, 0, 1, -1};
        int[] directionY = {1, -1, 0, 0};
        while (!queue.isEmpty()) {
            Triple t = queue.poll();
            int row = t.row;
            int col = t.col;
            level = t.level;
            level++;
            for (int k = 0; k < 4; k++) {
                int currRow = row + directionX[k];
                int currCol = col + directionY[k];
                if (currRow >= 0 && currRow < m && currCol >= 0 && currCol < n && grid[currRow][currCol] == 1 && visited[currRow][currCol] == false) {
                    grid[currRow][currCol] = 2;
                    fresh--;
                    visited[currRow][currCol] = true;
                    queue.offer(new Triple(currRow, currCol, level));
                }
            }
        }
        if (fresh == 0) {
            return level;
        }
        return -1;
    }
}
// Time Complexity: O(n)
// Space Complexity: O(n)
```

