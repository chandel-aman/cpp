#include <bits/stdc++.h>
using namespace std;

/* using set*/

// set<int> unionArray(vector<int> &n1, vector<int> &n2)
// {
//     set<int> unionSet;
//     for (int i : n1)
//         unionSet.insert(i);
//     for (int i : n2)
//         unionSet.insert(i);

//     return unionSet;
// }

/*using two pointers*/

vector<int> unionArray(vector<int> &n1, vector<int> &n2)
{
    int s1 = n1.size();
    int s2 = n2.size();
    int i = 0, j = 0;

    vector<int> n;
    int lastInserted = INT_MIN;

    while (i < s1 && j < s2)
    {
        if (n1[i] <= n2[j])
        {
            if (n.size() == 0 || n.back() != n1[i])
            {
                n.push_back(n1[i]);
            }
            i++;
        }
        else
        {
            if (n.size() == 0 || n.back() != n2[j])
            {
                n.push_back(n2[j]);
            }
            j++;
        }
    }
    // inserting the remaining elements
    while (i < s1)
    {
        if (n.back() != n1[i])
            n.push_back(n1[i]);
        i++;
    }
    while (j < s2)
    {
        if (n.back() != n2[j])
            n.push_back(n2[j]);
        j++;
    }

    return n;
}

int main()
{
    vector<int> n1 = {1, 2, 3, 3, 5, 6};
    vector<int> n2 = {4, 5, 7, 7, 8, 9};
    vector<int> n = unionArray(n1, n2);

    for (int i : n)
        cout << i << " ";

    return 0;
}