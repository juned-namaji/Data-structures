// Articulation point in the graph is an edge or a vertex on whose removal the graph is divided into 2 or more components
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &time, vector<int> &vis, vector<int> &tin, vector<int> &minTin, vector<vector<int>> &adj, vector<vector<int>> &points)
{
    vis[node] = 1;
    tin[node] = time;
    minTin[node] = time;

    for (auto v : adj[node])
    {
        if (!vis[v])
        {
            time++;
            dfs(v, node, time, vis, tin, minTin, adj, points);
            if (minTin[v] > tin[node])
            {
                points.push_back({node, v});
            }
            else
            {
                minTin[node] = minTin[v];
            }
        }
        else
        {
            if (v != parent)
            {
                minTin[node] = min(minTin[node], minTin[v]);
            }
        }
    }
}
vector<vector<int>> articulationPoints(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> adj(n + 1);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> vis(n);
    vector<int> tin(n);
    vector<int> minTin(n);
    vector<vector<int>> articulationPs;
    int time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, time, vis, tin, minTin, adj, articulationPs);
        }
    }
    return articulationPs;
}
int main()
{
    int n = 12;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {6, 9}, {8, 10}, {10, 11}, {11, 12}, {10, 12}};
    vector<vector<int>> points = articulationPoints(edges, n);
    for (auto point : points)
    {
        cout << point[0] << "->" << point[1] << endl;
    }
    return 0;
}