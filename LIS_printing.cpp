#include <bits/stdc++.h>
using namespace std;

void lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> idx(n);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        idx[i] = i;
        for (int p = 0; p < i; p++)
        {
            if (nums[i] > nums[p])
            {
                if (1 + dp[p] > dp[i])
                {
                    dp[i] = 1 + dp[p];
                    idx[i] = p;
                    ans = max(ans, dp[i]);
                }
            }
        }
    }
    cout << "Lenth of the longest increasing subsequence is: " << ans << endl;
    cout << "DP array: ";
    for (auto i : dp)
        cout << i << " ";
    cout << "\nThe index array: ";
    for (auto i : idx)
        cout << i << " ";

    cout << "\nThe longest increasing subsequence is: " << endl;

    int t = n - 1;
    while (dp[t] != ans)
        t--;

    int prev = -1;
    vector<int> v;
    while (prev != t)
    {
        v.push_back(nums[t]);
        prev = t;
        t = idx[t];
    }
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
}
int main()
{
    vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    lengthOfLIS(nums);
    return 0;
}