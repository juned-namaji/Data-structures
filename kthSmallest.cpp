#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bruteForce(vector<int> &nums, int k)
{
    // Brute force would be to sort the array and return the kth element
    // Same can be done using a heap which also takes same time as sorting
    cout << "Given array: ";
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    for (auto &num : temp)
        cout << num << " ";
    cout << endl;
    return temp[k - 1];
}

int partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[l];
    int i = l + 1;
    int j = r;

    while (i <= j)
    {
        while (i <= j && nums[i] < pivot)
            i++;
        while (j >= i && nums[j] > pivot)
            j--;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[j]);
    return j;
}
int divideAndConquer(vector<int> &nums, int k, int l, int r)
{
    if (l > r)
        return -1;
    int parInd = partition(nums, l, r);
    if (parInd == k)
        return nums[parInd];
    else if (parInd > k)
        return divideAndConquer(nums, k, l, parInd - 1);
    return divideAndConquer(nums, k, parInd + 1, r);
}
int main()
{
    vector<int> nums = {3, 6, 2, 6, 9, 9, 4, 39, 30, -3, -35};
    int k = 6;
    int bAns = bruteForce(nums, k);
    cout << k << "th smallest elemnt form the array is:" << bAns << endl;
    int divAns = divideAndConquer(nums, k - 1, 0, nums.size() - 1);
    cout << "DAC: " << divAns << endl;
    return 0;
}