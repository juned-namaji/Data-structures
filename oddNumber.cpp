#include <iostream>
#include <vector>
using namespace std;

int findOdd(vector<int> &arr, int l, int u)
{
    if (l == u)
        return arr[l];
    int mid = (l + u) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        return arr[mid];
    if (mid % 2 == 0)
    {
        if (arr[mid + 1] != arr[mid])
        {
            return findOdd(arr, l, mid - 1);
        }
        else
        {
            return findOdd(arr, mid + 1, u);
        }
    }
    else
    {
        if (arr[mid - 1] != arr[mid])
        {
            return findOdd(arr, l, mid - 1);
        }
        else
        {
            return findOdd(arr, mid + 1, u);
        }
    }
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7};
    cout << findOdd(arr, 0, arr.size() - 1) << endl;
    return 0;
}