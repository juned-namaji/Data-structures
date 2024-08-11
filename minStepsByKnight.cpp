#include <bits/stdc++.h>
using namespace std;

int minSteps(int prevx, int prevy, vector<int> &knightPos, vector<int> &target, vector<vector<int>> &dp, int n)
{
    int x = knightPos[0], y = knightPos[1];
    cout << x << " " << y << " " << n << endl;
    if (x <= 0 || y <= 0 || x > n || y > n)
        return 1e8;
    if (x == target[0] && y == target[1])
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    int mini = INT_MAX;
    for (int i = x - 2; i <= x + 2 && i != 0; i++)
    {
        if (i == x)
            continue;
        for (int j = -2; j <= 2; j++)
        {
            if (j == y || ((abs(x - i) == 2 && abs(j) == 2) || (abs(x - i) == 1 && abs(j) == 1)))
                continue;
            int newx = i, newy = y + j;
            if (newx != prevx || newy != prevy)
            {
                knightPos[0] = newx, knightPos[1] = newy;
                mini = min(mini, 1 + minSteps(x, y, knightPos, target, dp, n));
            }
        }
    }
    return dp[x][y] = mini;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return minSteps(-1, -1, KnightPos, TargetPos, dp, N);
}

int main()
{
    vector<int> k = {4, 5};
    vector<int> t = {1, 1};
    int n = 6;
    cout << minStepToReachTarget(k, t, n) << endl;
    return 0;
}
