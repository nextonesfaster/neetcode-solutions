// https://neetcode.io/problems/count-number-of-islands

#include <array>
#include <stack>
#include <utility>
#include <vector>

class Solution
{
    const std::array<int, 5> OFFSETS = {-1, 0, 1, 0, -1};

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int M = grid.size(), N = grid[0].size();
        int count = 0;

        for (int r = 0; r < M; r++)
        {
            for (int c = 0; c < N; c++)
            {
                if (grid[r][c] == '0')
                    continue;

                std::stack<std::pair<int, int>> stack;
                stack.push({r, c});
                grid[r][c] = '0';

                while (!stack.empty())
                {
                    auto [i, j] = stack.top();
                    stack.pop();

                    for (int k = 0; k < OFFSETS.size() - 1; k++)
                    {
                        int ni = i + OFFSETS[k], nj = j + OFFSETS[k + 1];
                        if (ni >= 0 && ni < M && nj >= 0 && nj < N && grid[ni][nj] == '1')
                        {
                            stack.push({ni, nj});
                            grid[ni][nj] = '0';
                        }
                    }
                }

                count++;
            }
        }

        return count;
    }
};
