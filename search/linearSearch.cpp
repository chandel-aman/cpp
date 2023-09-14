#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int key)
{
    for (int i = 0; i<arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main(){
    vector<int>arr = {2,3,4,1,0,6,9,2};
    int key = 2;
    cout<<linearSearch(arr, key);
    return 0;
}