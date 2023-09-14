#include <bits/stdc++.h>
using namespace std;

// recursive function to perform bubble sort
void bblSort(int arr[], int size)
{
    if (size == 0 || size == 1)
        return;
    int swapped = 0;
    // place the largest number at the end of the array

    for (int j = 0; j < size - 1; j++)
    {
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
        swapped = 1;
    }

    if (!swapped)
        return;
    // recursive case
    bblSort(arr, size - 1);
}

// main function
int main()
{
    int arr[] = {1, 3, 0, 9, 6, 1};
    bblSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}