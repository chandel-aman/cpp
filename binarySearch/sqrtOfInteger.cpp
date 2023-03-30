#include <bits/stdc++.h>

using namespace std;

//function to find the square root of an integer using binary search
long long int sqrtOfInt(int & n){
    int ll = 0, ul = n/2;
    long long int mid = ll + (ul - ll)/2;
    long long int sqrt;
    while(ll <= ul){
        long long int sqr = mid*mid;
        if(sqr == n)
            return mid;
        else if(sqr > n)
            ul = mid - 1;
        else{
            sqrt = mid;
            ll = mid + 1;
        }

        mid = ll + (ul-ll)/2;
    }
    return sqrt;
}

//function to add more precision to the square root of the integer
double addPrecision(int & n, int precision, int intPart){
    double counter = 1;
    double sqrt = intPart;
    for(int i = 0; i<precision; i++){
        counter /= 10;
        for(double j = sqrt; j*j<n; j+=counter)
            sqrt = j;
    }
    
    return sqrt;
}

//main function
int main(){
    int n;
    cout<<"Enter a number ";
    cin>>n;

    int & num = n;

    int && intPart = sqrtOfInt(num);

    cout<<addPrecision(num, 3, intPart)<<endl;

    return 0;
}