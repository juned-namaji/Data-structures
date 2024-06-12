#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

long long solve(int st, int end, bool isTrue, string &exp, vector<vector<vector<int>>> &dp)
{
    if (st > end)
        return 0;
    if (st == end)
    {
        if (isTrue)
            return exp[st] == 'T';
        else
            return exp[st] == 'F';
    }
    if (dp[st][end][isTrue] != -1)
        return dp[st][end][isTrue];

    long long ways = 0;

    for (int i = st + 1; i < end; i += 2)
    {
        char sym = exp[i];
        long long leftT = solve(st, i - 1, true, exp, dp) % mod;
        long long leftF = solve(st, i - 1, false, exp, dp) % mod;
        long long rightT = solve(i + 1, end, true, exp, dp) % mod;
        long long rightF = solve(i + 1, end, false, exp, dp) % mod;

        if (isTrue)
        {
            if (sym == '|')
                ways = (ways + ((leftT * rightT) % mod + (leftF * rightT) % mod + (leftT * rightF) % mod) % mod) % mod;
            else if (sym == '&')
                ways = (ways + (leftT * rightT) % mod) % mod;
            else
                ways = (ways + ((leftT * rightF) % mod + (leftF * rightT) % mod) % mod) % mod;
        }
        else
        {
            if (sym == '|')
                ways = (ways + (leftF * rightF) % mod) % mod;
            else if (sym == '&')
                ways = (ways + ((leftF * rightF) % mod + (leftT * rightF) % mod + (leftF * rightT) % mod) % mod) % mod;
            else
                ways = (ways + ((leftF * rightF) % mod + (leftT * rightT) % mod) % mod) % mod;
        }
    }

    return dp[st][end][isTrue] = ways;
}

long long evaluateExp(string &exp)
{
    int n = exp.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(0, exp.length() - 1, 1, exp, dp) % mod;
}

int main()
{
    string exp = "F^F^F^F&T|T|F|T|F|F|T|T|T|T&T|T|T&T|F&T|F|T|T|T^T|F^T|T&F^T|F|T|F|T&T|T^F|F^T&T^T&T^T&T^T&F&T^F|F^T|T|F|F^F|F&F|F|T&F&F";
    cout << evaluateExp(exp) << endl;

    return 0;
}