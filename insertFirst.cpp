#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7};
    arr.insert(arr.begin(), 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}