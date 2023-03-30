#include<bits/stdc++.h>
using namespace std;


// recursive function to perform linear search
bool linearSearch(int arr[], int size, int key)
{
    // base condition
    if (size == 0)
        return false;

    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        // recursive condition
        bool present = linearSearch(arr+1, size-1, key);
        return present;
    }
}

//main function
int main()
{
    int arr[] = {1, 0, 5, 8, 9, 2};
 
    int key;
    cin >> key;

    bool check = linearSearch(arr, 5, key);
    
    if (check)
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;

    return 0;
}