#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int closest = INT_MAX;
    int ans;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++)
    {
        int left = i + 1;
        int right = size - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target)
                return sum;
            else if (sum > target)
                right--;
            else
                left++;
            if (abs(target - sum) < closest)
            {
                closest = abs(target - sum);
                ans = sum;
            }
        }
    }
    return ans;
}

// main function
int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int ans = threeSumClosest(nums, 1);
    cout << ans;
    return 0;
}