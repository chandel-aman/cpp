#include<bits/stdc++.h>
using namespace std;

//recursive function to reverse the given string
string revStr(string str){
    //base case
    if(str.length() == 0){
        return "INVALID INPUT";
    }
    if(str.length() == 1){
        return str;
    }

    string rev = "";
    rev = revStr(str.substr(1)) + str[0];
    return rev;
}

//another approach
void revStr2(string &str, int i){
    if(i > str.length()-i)
        return;
    
    swap(str[i], str[str.length()-i-1]);
    i++;

    revStr2(str, i);
}

//main function
int main(){
    string str;
    getline(cin, str);
    // cout<<revStr(str)<<endl;
    revStr2(str, 0);
    cout<<str<<endl;

    return 0;
}