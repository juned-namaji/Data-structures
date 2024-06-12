// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
void buildTree(int idx, int low, int high, vector<int> &arr, vector<int> &seg, int orr)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * idx + 1, low, mid, arr, seg, !orr);
    buildTree(2 * idx + 2, mid + 1, high, arr, seg, !orr);
    if (orr)
    {
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    }
    else
    {
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
}
void update(int idx, int val, int low, int high, int i, vector<int> &seg, int orr)
{
    if (low == high)
    {
        seg[i] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (idx <= mid)
        update(idx, val, low, mid, 2 * i + 1, seg, !orr);
    else
        update(idx, val, mid + 1, high, 2 * i + 2, seg, !orr);
    if (orr)
    {
        seg[i] = seg[2 * i + 1] | seg[2 * i + 2];
    }
    else
    {
        seg[i] = seg[2 * i + 1] ^ seg[2 * i + 2];
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    int el = pow(2, n);
    vector<int> arr(el);
    for (int i = 0; i < el; i++)
        cin >> arr[i];

    vector<int> seg(el * 4);
    int orr = n % 2 != 0;
    buildTree(0, 0, el - 1, arr, seg, orr);
    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        update(idx - 1, val, 0, el - 1, 0, seg, orr);
        cout << seg[0] << endl;
    }
    return 0;
}