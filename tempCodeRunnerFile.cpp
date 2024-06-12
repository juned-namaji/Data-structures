#include <bits/stdc++.h>
using namespace std;
class T
{
public:
    int open, close, full;

public:
    T(int _o, int _c, int _f)
    {
        open = _o;
        close = _c;
        full = _f;
    }
};

void buildTree(int idx, int low, int high, string &s, vector<T> &t)
{
    if (low == high)
    {
        int open, close, full;
        open = close = full = 0;
        if (s[low] == '(')
            open++;
        else
            close++;
        t[idx] = T(open, close, full);
        return;
    }
    int mid = (low + high) / 2;
    buildTree(idx * 2 + 1, low, mid, s, t);
    buildTree(idx * 2 + 2, mid + 1, high, s, t);
    T left = t[idx * 2 + 1], right = t[idx * 2 + 2];
    int open = left.open + right.open - min(left.open, right.close);
    int close = left.close + right.close - min(left.open, right.close);
    int full = left.full + right.full + min(left.open, right.close);
    t[idx] = T(open, close, full);
}

T query(int l, int r, int low, int high, int idx, vector<T> &t)
{
    if (high < l || low > r)
        return T(0, 0, 0);
    else if (low >= l && high <= r)
    {
        return t[idx];
    }
    int mid = (low + high) / 2;
    T left = query(l, r, low, mid, idx * 2 + 1, t);
    T right = query(l, r, mid + 1, high, idx * 2 + 2, t);
    int open = left.open + right.open - min(left.open, right.close);
    int close = left.close + right.close - min(left.open, right.close);
    int full = left.full + right.full + min(left.open, right.close);
    return T(open, close, full);
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int q;
    cin >> q;
    vector<T> arr(4 * n);
    buildTree(0, 0, s.length() - 1, s, arr);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r - 1, 0, n - 1, 0, arr).full * 2 << endl;
    }
    return 0;
}