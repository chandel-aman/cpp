#include <bits/stdc++.h>
using namespace std;

void backTracking(string s1, vector<string> & permutation, int index)
{
    // base case
    if (index >= s1.length())
    {
        permutation.push_back(s1);
        
        return;
    }

    // recursive case
    for(int i = index; i<s1.length(); i++){
        swap(s1[index], s1[i]);
        backTracking(s1, permutation, index + 1);
        swap(s1[index], s1[i]);
    }
}

bool checkInclusion(string s1, string s2)
{
    if (s1.length() == 0)
        cout << "invalid";
    vector<string> permutation;
    string output = "";
    int index = 0;
    backTracking(s1, permutation, index);
    bool isPresent = false;
    for (string s : permutation)
    {
        if (s2.find(s) != string::npos)
        {
            isPresent = true;
            break;
        }
    }

    return isPresent;
}

int main()
{
    string s1 = "abc";
    string s2 = "fasdfcobafdfiop";
    cout<<checkInclusion(s1, s2);
    return 0;
}