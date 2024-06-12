#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), backTrack(n, -1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                backTrack[i] = j;
            }
        }
    }
    int maxLen = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            idx = i;
        }
    }

    while (backTrack[idx] != -1)
    {
        cout << arr[idx] << " ";
        idx = backTrack[idx];
    }
    cout << arr[idx] << endl;

    return maxLen;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 7, 7, 7};
    cout << "The length of LIS of the given array is: " << LIS(arr) << endl;
    return 0;
}