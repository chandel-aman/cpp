#include<bits/stdc++.h>
using namespace std;

//main function
int main(){

    //taking array size inputs
    int row;
    cin>>row;

    int col;
    cin>>col;

    //creating a array of pointers
    int ** ar = new int * [row];

    //creating a 1D array for each array pointer
    for(int i=0; i<row; i++){
        ar[i] = new int[col];
    }

    //taking input in the array
    for(int i = 0; i < row; i++){
        for( int j = 0; j < col; j++){
            cin>>ar[i][j];
        }
    }
    
    //displaying the array contents
    for(int i = 0; i < row; i++){
        for( int j = 0; j < col; j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }

    //freeing the array memory
    //deleting the 1d array or the columns
    for(int i = 0; i < row; i++){
        delete [] ar[i];
    }

    //deleting the array of pointers or the rows
    delete [] ar;

    return 0;
}