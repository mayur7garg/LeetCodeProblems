# https://leetcode.com/problems/magic-squares-in-grid

class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col, result = len(grid), len(grid[0]), 0
        if (row < 3) or (col < 3):
            return result
        
        valid_set = set(range(1, 10))

        for i in range(row - 2):
            for j in range(col - 2):
                a = grid[i][j]
                b = grid[i][j + 1]
                c = grid[i][j + 2]
                d = grid[i + 1][j]
                e = grid[i + 1][j + 1]
                f = grid[i + 1][j + 2]
                g = grid[i + 2][j]
                h = grid[i + 2][j + 1]
                k = grid[i + 2][j + 2]

                if e != 5:
                    continue
                if set([a, b, c, d, e, f, g, h, k]) != valid_set:
                    continue
                if (a + k) != 10:
                    continue
                if (b + h) != 10:
                    continue
                if (c + g) != 10:
                    continue
                if (d + f) != 10:
                    continue
                if (a + b + c) != 15:
                    continue
                if (g + h + k) != 15:
                    continue
                if (a + d + g) != 15:
                    continue
                if (c + f + k) != 15:
                    continue
                result += 1

        return result

s = Solution()

grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
print(f"Output: {s.numMagicSquaresInside(grid)} | Expected: 1")

grid = [[8]]
print(f"Output: {s.numMagicSquaresInside(grid)} | Expected: 0")