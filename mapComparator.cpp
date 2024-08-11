#include <bits/stdc++.h>
using namespace std;

struct comparator
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

int main()
{
    map<string, int, comparator> mpp;
    mpp["Juned"] = 940;
    mpp["raghav"] = 930;
    mpp["NAMAJI"] = 1000;

    for (auto &it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}