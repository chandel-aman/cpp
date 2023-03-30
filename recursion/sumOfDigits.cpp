#include<bits/stdc++.h>
using namespace std;

// recursive function to find the sum of numbers in an array
int getSum(int arr[], int size)
{
    if (size == 0)
        return 0;
    else if(size == 1)
        return arr[0];

    int sum = arr[0] + getSum(arr+1, size-1);
    return sum;
}

//main function
int main(){
    int arr[] = {1, 4, 2, 7, 0, 8};

    cout<<getSum(arr, 6);
    
    return 0;
}