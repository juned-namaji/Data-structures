#include <bits/stdc++.h>
using namespace std;

int minimize(vector<vector<int>> &cost, int visited, int node, vector<vector<int>> &dp, int n)
{
    if (visited == (1 << n) - 1)
        return dp[node][visited] = cost[node][0];
    if (dp[node][visited] != -1)
    {
        return dp[node][visited];
    }
    int mini = 1e8;

    for (int i = 0; i < n; i++)
    {
        if (!((visited >> i) & 1))
        {
            mini = min(mini, cost[node][i] + minimize(cost, visited | (1 << i), i, dp, n));
        }
    }

    return dp[node][visited] = mini;
}

int total_cost(vector<vector<int>> cost)
{
    int n = cost[0].size();
    vector<vector<int>> dp(n, vector<int>((1 << n), -1));
    int ans = minimize(cost, 1, 0, dp, n);
    return ans;
}

int main()
{
    vector<vector<int>> cost = {{227, 356, 493}, {8, 268, 56}, {333, 322, 167}};
    cout << total_cost(cost) << endl;
    return 0;
}