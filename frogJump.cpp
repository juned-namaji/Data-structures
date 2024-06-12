#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> heights = {
        27,
        35,
        43,
        34,
        27,
        19,
        7,
        38,
        16,
        18,
        46,
        13,
        14,
        50,
        34,
        38,
        36,
        34,
        26,
        39,
        6,
        41,
        23,
        1,
        33,
        30,
        45,
        13,
        47,
        13,
        22,
        20,
        3,
        1,
        17,
        26,
        45,
        39,
        22,
        45,
        21,
        11,
        30,
        44,
        36,
        45,
        29,
        27,
        39,
        42,
        40,
        35,
        46,
        31,
        21,
        6,
        31,
        50,
        20,
        50,
        10,
        10,
        24,
        6,
        30,
        29,
        44,
        39,
        42,
        14,
        23,
        12,
        4,
        1,
        35,
        5,
        45,
        40,
        44,
        42,
        47,
        24,
        48,
        16,
        21,
        50,
        34,
        4,
        13,
        5,
        36,
        46,
        20,
        45,
        3,
        13,
        7};
    // Tabulation solution
    int n = heights.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i], min(abs(heights[i] - heights[i - 1]) + dp[i - 1], abs(heights[i] - heights[i - 2]) + dp[i - 2]));
    }

    cout << dp[n - 1] << endl;

    // Space optimized solution
    int first = 0;
    int second = abs(heights[0] - heights[1]);

    for (int i = 2; i < n; i++)
    {
        int curr = min(abs(heights[i] - heights[i - 1]) + second, abs(heights[i] - heights[i - 2]) + first);
        first = second;
        second = curr;
    }

    cout << second << endl;
}