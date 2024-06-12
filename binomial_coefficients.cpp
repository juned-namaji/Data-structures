#include <bits/stdc++.h>
using namespace std;

int memoi(int n, int m, vector<vector<int>> &dp)
{
    // T.C = O(n*m)
    // S.C = O(n*m) + O(n) for auxillary stack space
    if (n == m || m == 1)
        return dp[n][m] = 1;
    if (dp[n][m] != 0)
        return dp[n][m];
    return dp[n][m] = memoi(n - 1, m - 1, dp) + memoi(n - 1, m, dp);
}

int tab(int n, int m)
{
    // Space optimized
    // T.C = O(n*m)
    // S.C = O(m)
    vector<int> dp(m + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = min(m, i); j >= 2; j--)
        {
            if (i == j)
                dp[j] = 1;
            else
                dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[m];
}

int main()
{
    int n, m;
    cout << "Enter the power of the expression(n): " << endl;
    cin >> n;
    cout << "Enter the index of the term that you want to get(k): " << endl;
    cin >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int term = memoi(n, m, dp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The " << m << "th coefficient in the " << n << " power binomial equation is:(Memoization) " << term << endl;

    cout << "Tabulation: " << tab(n, m) << endl;

    return 0;
}