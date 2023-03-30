#include <bits/stdc++.h>

using namespace std;

//function to return the first and last occurence of a number
//check for first occurence if c == 1 else last occurence
int occurence(vector <int> & arr, int &key, int c){
    int ll = 0, ul = arr.size()-1;
    int mid = ll + (ul-ll)/2;
    int occ = -1;

    while(ll<=ul){
        if(arr[mid]==key){
            occ = mid;
            if(c == 1)
                ul = mid - 1;
            else
                ll = mid + 1;
        }
        else if(arr[mid]>key)
            ul = mid-1;
        else
            ll = mid + 1;
        
        //update the mid
        mid = ll + (ul-ll)/2;
    }
    
    //if the key is not present in the given array
    return occ;
}

//main function
int main(){
    int key;
    vector <int> arr = {1,2,3,3,3,3,5,5,6,7};
    cout<<"Enter the key ";
    cin>>key;
    int & k = key;
    pair<int, int> occur(occurence(arr, k, 1), occurence(arr, k, 0));
    cout<<"First occurence of " << key << " is at index " << occur.first <<endl;
    cout<<"Last occurence of " << key << " is at index " << occur.second <<endl;

    return 0;
}