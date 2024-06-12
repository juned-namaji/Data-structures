#include <vector>
#include <iostream>
using namespace std;

void findCount(int &count0, int &count1, vector<int> &v, int st, int end)
{
    if (v[0] == 1)
    {
        count0 = 0;
        count1 = v.size();
        return;
    }

    while (st < end)
    {
        int mid = (st + end) / 2;

        if (v[mid] == 0)
        {
            if (v[mid + 1] == 1)
            {
                count0 = mid + 1;
                count1 = v.size() - mid - 1;
                return;
            }
            st = mid + 1;
        }
        else
        {
            if (v[mid - 1] == 1)
            {
                end = mid - 1;
            }
            else if (v[mid - 1] == 0)
            {
                count0 = mid;
                count1 = v.size() - mid;
                return;
            }
        }
    }
}
int main()
{
    vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1};
    int count0 = 0;
    int count1 = 0;
    findCount(count0, count1, v, 0, v.size() - 1);

    cout << "Count of 0's: " << count0 << "\nCount of 1's: " << count1;

    return 0;
}