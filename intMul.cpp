#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long mul(long long a, long long b)
{
    if (a < 10 || b < 10)
    {
        return a * b;
    }

    int numDigits = max(log10(a) + 1, log10(b) + 1);

    int halfDigits = (numDigits + 1) / 2;
    long long power = pow(10, halfDigits);

    long long a1 = a / power;
    long long a2 = a % power;
    long long b1 = b / power;
    long long b2 = b % power;

    long long a1b1 = mul(a1, b1);
    long long a2b2 = mul(a2, b2);
    long long middle = mul(a1 + a2, b1 + b2) - a1b1 - a2b2;

    return a1b1 * pow(10, 2 * halfDigits) + middle * power + a2b2;
}
int main()
{
    int x = 4256;
    int y = 7834;
    int ans = mul(x, y);
    cout << ans << endl;
    return 0;
}
