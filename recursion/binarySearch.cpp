#include<bits/stdc++.h>
using namespace std;

// recursive function to perform binary search
bool bin_search(int arr[], int start, int end, int key)
{
    if(start > end)
        return false;
    
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true;
    
    if (arr[mid] > key)
        return bin_search(arr, start, mid - 1, key);
    else
        return bin_search(arr, mid + 1, end, key);

    return false;
}

//main function
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
 
    int key;
    cin >> key;

    bool check = bin_search(arr, 0, 5, key);
    
    if (check)
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;

    return 0;
}