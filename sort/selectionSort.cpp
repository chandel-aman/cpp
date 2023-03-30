#include<bits/stdc++.h>

using namespace std;

//function to swap to numbers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to print an array
void display(vector<int> & arr){
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}

//function to perform sorting using selection sorting algorithm
void selectionSort(vector<int> & arr){
    auto min = &arr[0];
    for(int i=0; i<arr.size()-1 ;i++){
        min = &arr[i];
        for(int j=i+1; j<arr.size(); j++)
            if(arr[j] < *min)
                min = &arr[j];
        
        swap(&arr[i], min);
    }
}

//main function
int main(){
    vector<int> arr = {34, 22, 0, 6, 1, 45};
    cout<<"Before sorting"<<endl;
    display(arr);
    selectionSort(arr);
    cout<<"After sorting"<<endl;
    display(arr);
}