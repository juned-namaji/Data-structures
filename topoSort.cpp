#include <bits/stdc++.h>
using namespace std;

bool topo(vector<vector<int>> &adj, stack<int> &st, int node, vector<int> &vis, vector<int> &pathVis)
{
    cout << node << endl;
    pathVis[node] = true, vis[node] = true;

    for (int next : adj[node])
    {
        if (pathVis[next])
            return false;
        if (!vis[next])
        {
            if (!topo(adj, st, next, vis, pathVis))
            {
                return false;
            }
        }
    }
    pathVis[node] = false;
    st.push(node);
    return true;
}
vector<int> topoSort(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < arr.size(); i++)
        adj[arr[i][0]].push_back(arr[i][1]);
    vector<int> vis(n + 1, false), pathVis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!topo(adj, st, i, vis, pathVis))
            {
                return {};
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 1}, {2, 3}};
    vector<int> topo = topoSort(v, 3);

    for (int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
    return 0;
}