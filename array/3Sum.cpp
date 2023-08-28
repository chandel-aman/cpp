#include <bits/stdc++.h>
using namespace std;

// Display function
void display(vector<vector<int>> &arr)
{
    if (arr.size() == 0)
    {
        cout << "[]" << endl;
        return;
    }
    for (vector<int> i : arr)
    {
        cout << "[";
        for (int j : i)
            cout << j << " ";
        cout << "]";
    }
    cout << endl;
}

// function to return the indices of the number
vector<vector<int>> threeSum(vector<int> &arr)
{
    vector<vector<int>> ans;
    int size = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size - 1; i++)
    {
        // skip the duplicates
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int left = i + 1;
        int right = size - 1;
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0)
            {
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;

                // skip the duplicates
                while (left < right && arr[left] == arr[left - 1])
                    left++;
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return ans;
}

// main function
int main()
{
    vector<int> nums = {-1, 0, 2, -1, 2, 2, 2, 3, 4, -5, 0, 0};
    vector<vector<int>> ans = threeSum(nums);
    display(ans);
    return 0;
}