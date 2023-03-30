/*
Given an array ‘pages’ of integer numbers, where ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to their students. 

Allocate books in a way such that:

1. Each student gets at least one book.

2. Each book should be allocated to a student.

3. Book allocation should be in a contiguous manner.

You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
*/

#include <bits/stdc++.h>

using namespace std;


//function to check whether allocation is possible with given number of maximum pages
bool isPossible(vector<int> & arr, int & n, int & m, int maxPages){
    //iterate over the given array and allocate book(s) to a student if the sum of pages is less than or equal to mid, else move to the next student or if there are no students left then allocation is not possible
    
    int numStudents = 1;
    int sumOfPages = 0;

    //iterate over the array
    for(int i = 0; i<n; i++){
        if(arr[i] > maxPages)
            return false;

        if(sumOfPages + arr[i] <= maxPages)
            sumOfPages += arr[i];
        else{
            //go to next student
            numStudents++;
            if(numStudents > m)
                return false;
            
            //change the sum of pages to the current number of pages of the book
            sumOfPages = arr[i];
        }
    }

    return true;
}

//function to allocate the books to in such a way that the maximum number of pages allocated to a student is minimum
int allocateBook(vector<int> & arr, int & n, int & m){

    //the number of the student is more than the number of books then return -1
    if(m>n)
        return -1;

    //else allocate the books

    //find the sum of all the pages of all the books
    int sum = 0;
    for(int i : arr)
        sum += i;
    
    int ll = 0, ul = sum;
    int mid = ll + (ul - ll)/2;
    int ans = -1;

    //binary search
    while(ll <= ul){
        //if it is possible to allocate with number of pages at index mid then search of lesser number of pages
        if(isPossible(arr, n, m, mid)){
            //store the value
            ans = mid;
            //search in the first half of the array
            ul = mid-1;
        }else{
            //search in the latter half of the array
            ll = mid+1;
        }
        //update the mid
        mid = ll + (ul - ll )/2;
    }

    //return the ans
    return ans;
}

//main function
int main(){
    vector<int> arr = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    int & books = n;
    int & students = m;
    cout<<allocateBook(arr, books, students)<<endl;

    return 0;
}