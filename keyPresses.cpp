#include <iostream>
#include <string>

using namespace std;

int minKeyPresses(const string &S)
{
    int keyPresses = 0;
    int i = 0;

    while (i < S.length())
    {
        if (S[i] == '0' && i + 1 < S.length() && S[i + 1] == '0')
        {
            keyPresses++;
            i += 2;
        }
        else
        {
            keyPresses++;
            i += 1;
        }
    }

    return keyPresses;
}

int main()
{
    string input1 = "127";
    cout << "Output for input \"" << input1 << "\": " << minKeyPresses(input1) << endl;
    return 0;
}