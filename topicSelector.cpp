#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> vec = {"Array", "matrix", "string", "searching", "LL", "Binary tree", "BST", "Greedy", "Backtracking", "Stack and queues", "Heap", "Graph", "Trie", "DP", "Bit manipulation"};

    srand(time(0));

    int randomNum = rand() % vec.size();
    string str = vec[randomNum];
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "You will be doing " << str << " today :)" << endl;
    return 0;
}
