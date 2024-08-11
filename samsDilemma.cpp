#include <iostream>
#include <vector>

using namespace std;

int countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int countTripletsWithEvenSetBits(vector<int> &input1, int input2, vector<int> &input3, int input4, vector<int> &input5, int input6)
{
    int count = 0;
    for (int i = 0; i < input2; ++i)
    {
        for (int j = 0; j < input4; ++j)
        {
            for (int k = 0; k < input6; ++k)
            {
                int xorResult = input1[i] ^ input3[j] ^ input5[k];
                int setBits = countSetBits(xorResult);
                if (setBits % 2 == 0)
                {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main()
{
    vector<int> A1 = {1, 2};
    vector<int> B1 = {3};
    vector<int> C1 = {2, 3};
    cout << "Output for Example 1: " << countTripletsWithEvenSetBits(A1, 2, B1, 1, C1, 2) << endl;

    vector<int> A2 = {4};
    vector<int> B2 = {4};
    vector<int> C2 = {4};
    cout << "Output for Example 2: " << countTripletsWithEvenSetBits(A2, 1, B2, 1, C2, 1) << endl;

    return 0;
}