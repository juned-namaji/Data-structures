#include <bits/stdc++.h>
using namespace std;
// Given an array of strings words, return the smallest string that contains each string in
// words as a substring. If there are multiple valid strings of the smallest length, return any of them.
// You may assume that no string in words is a substring of another string in words.

/// Diabolic solution :::DDD
int findConcatSize(string s1, string s2)
{
    int l1 = s1.length(), l2 = s2.length();
    int i = 0, cnt = 0;
    while (i < l1)
    {
        if (s1[i] == s2[0])
        {
            int tI = i, tJ = 0;
            while (tI < l1 && tJ < l2)
            {
                if (s1[tI] != s2[tJ])
                {
                    cnt = 0;
                    break;
                }
                else
                {
                    cnt++;
                }
                tI++, tJ++;
            }
            if (tI == l1)
                return cnt;
        }
        i++;
    }
    return 0;
}

string findSuper(int node, int mask, vector<string> &arr, vector<vector<pair<int, int>>> &adj, vector<vector<string>> &dp)
{
    if (mask == ((1 << arr.size()) - 1))
    {
        return arr[node];
    }
    if (dp[node][mask] != "-1")
        return dp[node][mask];
    string ans = arr[node];
    int len = 1e8;

    for (pair<int, int> next : adj[node])
    {
        int nNode = next.first, wt = next.second;
        string curr = arr[node];
        if (!((mask >> nNode) & 1))
        {
            string str = findSuper(nNode, mask | (1 << nNode), arr, adj, dp);
            curr += str.substr(wt);
            if (len > curr.length())
            {
                len = curr.length();
                ans = curr;
            }
        }
    }
    return dp[node][mask] = ans;
}

string superString(vector<string> &arr)
{
    int n = arr.size();
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            adj[i].push_back({j, findConcatSize(arr[i], arr[j])});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> next : adj[i])
        {
            cout << arr[i] << " --> " << arr[next.first] << " : " << next.second << endl;
        }
    }
    string ans = "";
    int len = 1e8;
    vector<vector<string>> dp(n, vector<string>((1 << n), "-1"));
    for (int i = 0; i < n; i++)
    {
        string str = findSuper(i, (1 << i), arr, adj, dp);
        if (len > str.length())
        {
            len = str.length();
            ans = str;
        }
    }

    return ans;
}

int main()
{ // Expected answer: "rfgruuzjr"
    vector<string> arr = {"bbabbaa", "aaaaaa", "aaabab", "baaabba", "bbbaabbbabaab", "abbabaaabbbabaaabbbb", "ababbba"};
    cout << superString(arr) << endl;

    return 0;
}