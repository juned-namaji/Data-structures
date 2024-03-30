#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    int n;
    vector<int> seg;
    vector<int> arr;

public:
    // 0-BASED index Segment tree
    SegmentTree(vector<int> &_arr)
    {
        arr = _arr;
        n = arr.size();
        seg.resize(4 * n, 0);
        cout << "Size of the input array is: " << n << endl;
        buildTree(0, 0, n - 1);
        printTree(seg);
    }
    //{4,2,1,4,3,4}
    void buildTree(int idx, int low, int high)
    {
        if (low >= high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        buildTree(2 * idx + 1, low, mid);
        buildTree(2 * idx + 2, mid + 1, high);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    void printTree(vector<int> &seg)
    {
        for (int i : seg)
            cout << i << " ";
    }
    int queryMin(int l, int r, int low, int high, int idx)
    {
        // No overlap in the range l to r
        if (high < l || low > r)
            return INT_MAX;
        // Complete overlap
        else if (high <= r && low >= l)
            return seg[idx];
        // Partial overlap
        int mid = (low + high) / 2;
        int left = queryMin(l, r, low, mid, 2 * idx + 1);
        int right = queryMin(l, r, mid + 1, high, 2 * idx + 2);
        return min(left, right);
    }

    void pointUpdate(int idx, int val, int low, int high, int i)
    {
        if (low == high)
        {
            seg[i] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            pointUpdate(idx, val, low, mid, 2 * i + 1);
        else
            pointUpdate(idx, val, mid + 1, high, 2 * i + 2);
        seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
};

int main()
{
    vector<int> arr = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    SegmentTree s(arr);
    cout << "\nThe input array is: ";
    s.printTree(arr);
    int a, b, n, idx, val;
    cout << "\nEnter the number of queries: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int q;
        cout << "Enter 1 for query and 2 for Updation: " << endl;
        cin >> q;
        if (q == 1)
        {
            cout << "Enter the lower bound for the query " << endl;
            cin >> a;
            cout << "Enter the upper bound for the query " << endl;
            cin >> b;
            cout << "Min number from range " << a << " to " << b << " is: " << s.queryMin(a, b, 0, arr.size() - 1, 0) << endl;
        }
        else if (q == 2)
        {
            cout << "Enter the index to be updated: ";
            cin >> idx;
            cout << "Enter the value to be update: ";
            cin >> val;
            s.arr[idx] = val;
            cout << "Updated array: " << endl;
            s.printTree(s.arr);
            cout << endl;
            s.pointUpdate(idx, val, 0, arr.size() - 1, 0);
        }
    }
    return 0;
}