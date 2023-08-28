#include<bits/stdc++.h>
using namespace std;

// Display function
void display(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

//function to return the indices of the number
vector<int> twoSum(vector<int> &arr, int target){
    vector<int> ans;        //to store the indices of the numbers
    unordered_map<int, int> numToIndices;       //to store the numbers as the key and their index as the value
    for(int i=0; i<arr.size(); i++){
        //complement is the number to be added to the number at ith position so that the sum is equal to the target
        int complement = target - arr[i];
        //if the complement exists then return the indices of the number and its complement
        if(numToIndices.find(complement) != numToIndices.end()){
            return {numToIndices[complement], i};
        }
        //else if the complement is not present in the hash map then add the number to it
        numToIndices[arr[i]] = i;
    }

    //else return an empty array
    return {};
}

//main function
int main(){
    vector<int> nums = {0, 3, 2, 5, 9};
    int target = 5;
    vector<int> ans = twoSum(nums, target);
    display(ans);
    return 0;
}