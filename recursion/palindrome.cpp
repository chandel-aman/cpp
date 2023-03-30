#include<bits/stdc++.h>
using namespace std;

//recursive function to check whether a string is a palindrome or not
bool isPalindrome(string &str, int i){
    if(i > str.length()-1)
        return true;
    
    if(str[i] != str[str.length()-i-1])
        return false;
    else
        return isPalindrome(str, i+1);
}

//main function
int main(){
    string str;
    getline(cin, str);

    if(isPalindrome(str, 0))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not a palindrome"<<endl;

    return 0;
}