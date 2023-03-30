#include <bits/stdc++.h>
using namespace std;

const string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

//recursive function to write the digits in words of a number
void digit(long long int num)
{
    // base case
    if(num == 0)
        return;
    // recursive case
    digit(num / 10);

    auto n = num % 10;
    cout<<digits[n]<<endl;
}

//main function
int main()
{
    int n;
    cin>>n;
    digit(n);

    return 0;
}