#include <iostream>
#include <cmath>
using namespace std;

int countSpecialGroups(int n)
{
    int count = 0;
    for (int c = 1; c <= n; ++c)
    {
        for (int b = 1; b < c; ++b)
        {
            int aSquare = c * c - b * b;
            int a = sqrt(aSquare);
            if (a * a == aSquare && a > 0 && a < b)
            {
                count++;
            }
        }
    }
    return count * 2;
}

int main()
{
    int n = 5;
    int specialGroups = countSpecialGroups(n);
    cout << "The number of special groups of three houses in a kingdom with houses numbered from 1 to " << n << " is " << specialGroups << "." << endl;
    return 0;
}
