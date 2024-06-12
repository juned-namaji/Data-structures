#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findLcs(string &s1, string &s2)
{ // This is for subsequence
    int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    // O(n*m)
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    string ans = "";
    for (int i = 0; i < dp[l1][l2]; i++)
    {
        ans += '$';
    }
    int idx = ans.length() - 1;

    int i = l1, j = l2;
    // O(n+m)
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[idx--] = s1[i - 1];
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    return ans;
}

int subStr(string &s1, string &s2)
{
    int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    int ans = 0;
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int main()
{
    string s1 = "tyfg";
    string s2 = "cvbnuty";
    // string ans = findLcs(s1, s2);
    int ans = subStr(s1, s2);
    cout << ans << endl;
}