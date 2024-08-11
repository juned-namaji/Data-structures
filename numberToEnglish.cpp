#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> d = {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"},
    {100, "Hundred"},
    {1000, "Thousand"},
    {1000000, "Million"},
    {1000000000, "Billion"}};

string convert(string str, int st, int end)
{
    int n = end - st;
    // if (n > 2)
    //     return "";
    cout << st << " " << end << endl;
    int num = stoi(str.substr(st, end - st + 1));
    cout << num << endl;
    string ans = "";
    if (n == 0)
        ans += d[num];
    else if (n == 1)
    {
        if (d.find(num) != d.end())
            ans += d[num];
        else
        {
            int base = num - (num % 10);
            ans += d[base] + " ";
            ans += d[num % 10];
        }
    }
    else
    {
        int firstLetter = str[st] - '0';
        ans += d[firstLetter] + " ";
        if (d.find(num) != d.end())
            ans += d[num];
        else
        {
            ans += d[100] + " ";
            int remainder = num % 100;
            if (remainder != 0)
            {
                if (d.find(remainder) != d.end())
                    ans += d[remainder];
                else
                {
                    int base = remainder - (remainder % 10);
                    ans += d[base] + " ";
                    ans += d[remainder % 10];
                }
            }
        }
    }
    // gotta give a suffix to the number(thousand, million, etc.)
    int len = str.length() - end - 1;
    if (len > 0)
    {
        string suffix = "1";
        for (int i = 0; i < len; i++)
            suffix += '0';
        ans += " " + d[stoi(suffix)];
    }

    cout << ans << endl;
    return ans;
}

void numToStr(string &str, string &ans, int endIdx, int stIdx)
{
    if (endIdx < 0)
        return;
    if (endIdx <= 2)
    {
        ans += convert(str, stIdx, endIdx);
        return;
    }
    numToStr(str, ans, endIdx - 3, max(0, stIdx - 3));
    cout << stIdx << " " << endIdx << endl;
    ans += " " + convert(str, stIdx, endIdx);
}

string numberToWords(int num)
{
    string n = to_string(num);
    int size = n.length();
    string ans = "";
    int idx = size - 1;
    numToStr(n, ans, idx, max(0, idx - 2));
    return ans;
}

int main()
{
    string str = "200";
    cout << numberToWords(stoi(str)) << endl;
    return 0;
}