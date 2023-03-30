#include <bits/stdc++.h>

using namespace std;

// function to find the pivot in the array

int partition(vector<int> &ar, int start, int end)
{
    //choosing the pivot element as the last element
    int pivot = ar[end];
    //pointer
    int low = start - 1;

    for(int i = start; i<end; i++){
        if(ar[i]<pivot){
            
        }
    }

}

// function to sort using quick sort algorithm
void quickSort(vector<int> &ar, int start, int end)
{
    int p = partition(ar, start, end);
    quickSort(ar, start, p);
    quickSort(ar, p + 1, end);
}

// function to display the array elements
void display(vector<int> &ar)
{
    for (int i : ar)
        cout << i << " ";
    
    cout << endl;
}

// main function
int main()
{
    vector<int> arr = {4, 1, 9, 12, 0, 45, 3, 8};
    cout << "Before sorting: ";
    display(arr);
    quickSort(arr, 0, 7);
    cout << "After sorting: ";
    display(arr);

    return 0;
}