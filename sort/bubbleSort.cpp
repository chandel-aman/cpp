#include<bits/stdc++.h>
using namespace std;

//function to swap two values
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to print the array
void display(vector<int>& arr){
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}

//function to sort an array using bubble sort algorithm
void bubbleSort(vector<int>& arr){
    bool check = false;
    for(int i = 0; i < arr.size()-1; i++){
        check = false;
        for(int j = 0; j < arr.size()-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                check = true;
            }
        }
        if(!check)
            break;
    }
}

//main function
int main(){
    vector<int> arr = {34, 22, 0, 6, 1, 45};
    cout<<"Before sorting"<<endl;
    display(arr);
    bubbleSort(arr);
    cout<<"After sorting"<<endl;
    display(arr);
}