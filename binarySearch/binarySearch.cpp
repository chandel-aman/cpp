#include <bits/stdc++.h>

using namespace std;

//function to implement binary search
int binarySearch(const vector <int> &arr, int key){
    int ll = 0, ul = arr.size()-1;
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
    int key;
    const vector <int> arr = {1,2,3,4,5,6,7,8,9};
    cout<<"Enter the key ";
    cin>>key;
    cout<<"The index of "<<key<<" is "<<binarySearch(arr, key)<<endl;
    return 0;
}