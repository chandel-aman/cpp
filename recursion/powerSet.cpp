/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.*/

/* to find the powerset of a set we'll use the concept of backtracking using recursion
at every call of the function iterating over each of the elements of the sets we'll have two choices
1) to include the element and move to backtracking
2) to exclude the element and move to backtracking
 */

#include <bits/stdc++.h>
using namespace std;

// recursive function to find the all the subsets of a set
void backtrack(vector<int> &set, vector<vector<int>> &subset, vector<int> output, int i)
{
    // base case
    if (i >= set.size())
    {
        subset.push_back(output);
        return;
    }
    // recursive case
    // case 1: exclude the current element and backtrack
    backtrack(set, subset, output, i + 1);
    // case 2: include the current element and backtrack
    output.push_back(set[i]);
    backtrack(set, subset, output, i + 1);
}

vector<vector<int>> subsets(vector<int> &set)
{
    vector<vector<int>> subset;
    vector<int> output;
    int index = 0;
    backtrack(set, subset, output, index);
    return subset;
}

int main()
{
    vector<int> set = {1, 2, 3};
    vector<vector<int>> powerset;
    powerset = subsets(set);
    // displaying the powerset for the set
    cout << "{"<<endl;
    for (auto subset : powerset)
    {
        cout << "{";
        for (auto element : subset)
        {
            cout << element << ",";
        }
        cout << "},"<<endl;
    }
    cout << "}";

    return 0;
}
