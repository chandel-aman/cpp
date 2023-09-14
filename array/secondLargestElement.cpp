#include <bits/stdc++.h>
using namespace std;

// brute force
// int secondLargest(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     return nums[nums.size() - 2];
// }

// efficient approach
int secondLargest(vector<int> &nums)
{
    int first = 0, second = -1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[first])
        {
            second = first;
            first = i;
        }
        else if (nums[i] < nums[first])
        {
            if (second == -1 || nums[second] < nums[i])
            {
                second = i;
            }
        }
    }
    return second;
}

// main function
int main()
{
    vector<int> nums = {5, 1, 0, 8, 9, 2};
    cout << nums[secondLargest(nums)];
    return 0;
}