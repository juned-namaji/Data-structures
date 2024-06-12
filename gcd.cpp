#include <bits/stdc++.h>
using namespace std;

int gcd(int &a, int &b)
{
    while (a)
    {
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int div = a / b;
        a = a - (b * div);
    }
    return b;
}
int gcdDAC(int a, int b, int res)
{
    if (a == 0)
    {
        return b * res;
    }
    else if (b == 0)
    {
        return a * res;
    }
    else if (a == b)
    {
        return a * res;
    }
    else if (a % 2 == 0 && b % 2 == 0)
    {
        return gcdDAC(a / 2, b / 2, 2 * res);
    }
    else if (a % 2 == 0)
    {
        return gcdDAC(a / 2, b, res);
    }
    else if (b % 2 == 0)
    {
        return gcdDAC(a, b / 2, res);
    }
    else if (a > b)
    {
        return gcdDAC(a - b, b, res);
    }
    else
    {
        return gcdDAC(a, b - a, res);
    }
}

int main()
{
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;

    int result = gcd(a, b);
    cout << "Greatest Common Divisor (gcd function): " << result << endl;

    int resultDAC = gcdDAC(a, b, 1);
    cout << "Greatest Common Divisor (gcdDAC function): " << resultDAC << endl;
    cout << flush;

    return 0;
}
