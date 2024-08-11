#include <bits/stdc++.h>
using namespace std;

int findConcatSize(string s1, string s2)
{
    int l1 = s1.length(), l2 = s2.length();
    int i = 0, cnt = 0;
    while (i < l1)
    {
        if (s1[i] == s2[0])
        {
            int tI = i, tJ = 0;
            while (tI < l1 && tJ < l2)
            {
                if (s1[tI] != s2[tJ])
                {
                    cnt = 0;
                    break;
                }
                else
                {
                    cnt++;
                }
                tI++, tJ++;
            }
            if (tI == l1)
                return cnt;
        }
        i++;
    }
    return 0;
}

int main()
{
    cout << findConcatSize("bbabbaa", "abbabaaabbbabaaabbbb");
    return 0;
}