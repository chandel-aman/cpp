#include <bits/stdc++.h>

using namespace std;

// function to merge the sorted array
void merge(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start)/2;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // creating two new vectors for the left and right halves
    vector<int> left(n1), right(n2);

    int c = start;
    // filling the left vector
    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];

    c = mid + 1;
    // filling the right vector
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];

    // l and r are the indexes for left and right vectors, and i corresponds to the index of main vector
    int l = 0;
    int r = 0;
    c = start;

    // merging the left and right vectors while sorting them
    while (l < n1 && r < n2)
    {
        // place the smaller among them in the main array
        if (left[l] <= right[r])
            arr[c++] = left[l++];
        else
            arr[c++] = right[r++];
    }

    // if in case we run out of element in either 'left' or 'right' then place the left over element in the main array
    // of elements of left are left out
    while (l < n1)
        arr[c++] = left[l++];

    // if in case we run out of element in either 'left' or 'right' then place the left over element in the main array of elements of left are left out
    while (r < n2)
        arr[c++] = right[r++];
}

// merge sort
void mergeSort(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    // middle index
    int mid = start + (end - start) / 2;

    // sorting the first half of the array
    mergeSort(arr, start, mid);
    // sorting the second half of the array
    mergeSort(arr, mid + 1, end);

    // merging the sorted array
    merge(arr, start, end);
}

//function to display a vector
void display(vector<int> & arr){
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}

// main function
int main()
{
    vector<int> arr = {3, 7, 0, 9, 1, 98, 12, 56};

    cout<<"Before sorting: ";
    display(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout<<"After sorting: ";
    display(arr);

    return 0;
}