#include <bits/stdc++.h>

using namespace std;

/*
arr = [1,2,3,4,5,6,7,8,9,10,11,12]
rotated = [11,12,1,2,3,4,5,6,7,8,9,10]
pivotIndex = 2
*/
//function to find the pivot in a sorted rotated array
int pivot(vector<int> & arr){
    int ll = 0, ul = arr.size()-1;
    int mid = ll + (ul-ll)/2;

    while(ll<ul){
        if(arr[mid]>arr[0])
            ll = mid+1;
        else
            ul = mid;
        mid = ll + (ul-ll)/2;
    }
}

//function to implement binary search
int binarySearch(const vector <int> & arr, int s, int e, int & key){
    int ll = s, ul = e;
    int mid = ll + (ul-ll)/2;

    while(ll<=ul){
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            ul = mid-1;
        else
            ll = mid + 1;
        
        //update the mid
        mid = ll + (ul-ll)/2;
    }
    
    //if the key is not present in the given array
    return -1;
}

//main function
int main(){
    vector<int> arr = {18,19,1,2,3,4,5,6,7,8,9,10,11,12};
    int && p = pivot(arr);
    int key;
    cout<<"Enter the key ";
    cin>>key;

    int & k = key;
    if(key >= arr[p] && key <= arr[arr.size()-1])
        cout<<binarySearch(arr, p, arr.size()-1, k)<<endl;
    else
        cout<<binarySearch(arr, 0, p-1, k)<<endl;

    return 0;
}