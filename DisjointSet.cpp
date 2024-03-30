#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;

public:
    DisjointSet(int size)
    {
        parent.resize(size, -1);
    }

    int findParent(int node)
    {
        if (parent[node] < 0)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (parent[pu] < parent[pv])
        {
            parent[pu] = parent[pu] + parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = parent[pu] + parent[pv];
            parent[pu] = pv;
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(1, 3);
    cout << "Parent of 1 is: " << ds.findParent(1) << endl;
    cout << "Parent of 2 is: " << ds.findParent(2) << endl;
    ds.unionBySize(5, 6);
    cout << "Parent of 1 is: " << ds.findParent(1) << endl;
    cout << "Parent of 6 is: " << ds.findParent(6) << endl;
    ds.unionBySize(1, 6);
    cout << "After union:   " << endl;
    cout << "Parent of 1 is: " << ds.findParent(1) << endl;
    cout << "Parent of 6 is: " << ds.findParent(6) << endl;

    return 0;
}