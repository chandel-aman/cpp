#include<bits/stdc++.h>
using namespace std;

//function to sort using insertion algorithm
void insertionSort(vector<int>& arr){
    //for loop to iterate to each element
    for(int i=1; i<arr.size(); i++){
        int temp = arr[i];
        int j = i-1;
        //while loop to iterate to all the elements left of ith element
        while(j >= 0 && arr[j] >= temp){
            //one or more elements are greater than the element at ith position then move the element at jth position to left untill it is at it's correct position
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

//function to print the array
void display(vector<int>& arr){
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}

//main function
int main(){
    vector<int> arr = {34, 22, 0, 6, 1, 45};
    cout<<"Before sorting"<<endl;
    display(arr);
    insertionSort(arr);
    cout<<"After sorting"<<endl;
    display(arr);
}