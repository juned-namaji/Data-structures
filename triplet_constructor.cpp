#include <bits/stdc++.h>
using namespace std;

struct triplet
{
    int pos, health;
    char direction;

    triplet(int a, int b, char c)
    {
        pos = a;
        health = b;
        direction = c;
    }

public:
    void reduceHealth()
    {
        health--;
    }
};

struct comparator
{
    bool operator()(const triplet &a, const triplet &b) const
    {
        return a.pos < b.pos;
    }
};

int main()
{
    set<triplet, comparator> st;
    st.insert(triplet(4, 5, 'a'));
    st.insert(triplet(6, 3, 'z'));
    st.insert(triplet(2, 3, 'k'));

    for (auto &curr : st)
    {
        triplet t = curr;
        t.reduceHealth();
        cout << t.pos << " " << t.health << endl;
    }

    vector<int> v = {3, 5, 2, 6};
    vector<int> ind(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](int l, int r)
         { return v[l] < v[r]; });

    for (int i = 0; i < v.size(); i++)
    {
        cout << ind[i] << " ";
    }
    return 0;
}