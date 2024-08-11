#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dir)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 1)
        return;
    grid[x][y] = 1;
    for (vector<int> d : dir)
    {
        dfs(grid, x + d[0], y + d[1], dir);
    }
}
int regionsBySlashes(vector<string> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int exRowSize = rows * 3;
    int exColSize = cols * 3;
    vector<vector<int>> expandedGrid(exRowSize, vector<int>(exColSize));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int stRow = i * 3;
            int stCol = j * 3;
            if (grid[i][j] == '/')
            {
                expandedGrid[stRow][stCol + 2] = 1;
                expandedGrid[stRow + 1][stCol + 1] = 1;
                expandedGrid[stRow + 2][stCol] = 1;
            }
            else if (grid[i][j] == '\\')
            {
                expandedGrid[stRow][stCol] = 1;
                expandedGrid[stRow + 1][stCol + 1] = 1;
                expandedGrid[stRow + 2][stCol + 2] = 1;
            }
        }
    }

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int regions = 0;
    for (int i = 0; i < exRowSize; i++)
    {
        for (int j = 0; j < exColSize; j++)
        {
            if (expandedGrid[i][j] == 0)
            {
                dfs(expandedGrid, i, j, dir);
                regions++;
            }
        }
    }
    return regions;
}
int main()
{
    vector<string> str = {" /", "  "};
    cout << regionsBySlashes(str);
    return 0;
}