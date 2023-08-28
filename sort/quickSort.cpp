#include <bits/stdc++.h>
using namespace std;

// Display function
void display(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

// Function to implement to find the pivot
int partition(vector<int> &arr, int start, int high)
{
    int pivot = arr[start];
    int i = start;
    int j = high;
    while (i < j)
    {
        while (i <= high - 1 && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= start + 1 && arr[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);

    return j;
}

// Quick Sort
void quickSort(vector<int> &arr, int start, int high)
{
    if (start < high)
    {
        int pivot = partition(arr, start, high);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, high);
    }
}

// main function
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    cout << "Before sorting" << endl;
    display(arr);
    quickSort(arr, 0, arr.size() - 1);
    cout << "After sorting" << endl;
    display(arr);

    return 0;
}