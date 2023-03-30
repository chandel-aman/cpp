#include <bits/stdc++.h>

using namespace std;

// function to find the peak index in a mountain array
int peakIndex(vector<int> &arr)
{
    int ll = 0, ul = arr.size()-1;
    int mid = ll + (ul - ll) / 2;
    while (ll < ul)
    {
        if (arr[mid] < arr[mid + 1])
            ll = mid + 1;
        else
            ul = mid;
        mid = ll + (ul - ll) / 2;
    }
    return ll;
}

//main function
int main(){
    vector<int> arr = {6,7,3,0,-1,-4,-6,-10};
    cout<<peakIndex(arr);
    return 0;
}