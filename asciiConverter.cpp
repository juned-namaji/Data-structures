#include <bits/stdc++.h>
using namespace std;

string countOfAtoms(string formula)
{
    int n = formula.length();
    unordered_map<int, int> bracketToMultiplier;
    stack<int> st;
    int i;
    for (i = 0; i < n; i++)
    {
        if (formula[i] == '(')
            st.push(i);
        else if (formula[i] == ')')
        {
            int stIdx = st.top();
            st.pop();
            string multiplier = "";
            while (i < n && isdigit(formula[++i]))
            {
                multiplier += formula[i];
            }
            i--;
            bracketToMultiplier[stIdx] = multiplier == "" ? 1 : stoi(multiplier);
        }
    }
    map<string, int> atomCount;
    int multiplier = 1;
    for (i = 0; i < n; i++)
    {
        if (formula[i] == '(')
        {
            multiplier *= bracketToMultiplier[i];
            st.push(bracketToMultiplier[i]);
        }
        else if (formula[i] == ')')
        {
            multiplier /= st.top();
            st.pop();
        }
        else if (!isdigit(formula[i]))
        {
            string element = "", localMul = "";
            element += formula[i];
            while (i < n && islower(formula[++i]))
                element += formula[i];
            while (i < n && isdigit(formula[i]))
                localMul += formula[i++];
            int totalMul = multiplier * (localMul == "" ? 1 : stoi(localMul));
            atomCount[element] += totalMul;
            i--;
        }
    }
    string ans = "";
    for (auto it = atomCount.begin(); it != atomCount.end(); it++)
    {
        ans += it->first;
        if (it->second > 1)
            ans += to_string(it->second);
    }
    return ans;
}
int main()
{
    string a = "Mg(H2O)N";
    cout << countOfAtoms(a) << endl;
    return 0;
}