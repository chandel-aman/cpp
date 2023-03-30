#include <bits/stdc++.h>
using namespace std;

// recursive function to find the value of given base with given exponent
int power(int e, int p)
{
    // base case
    if (e == 0 && p == 0)
        return -1;
    if (e == 1 || p == 0)
        return 1;
    if (p == 1)
        return e;
    if (e == 0)
        return 0;

    // recursive case
    int pow = power(e, p/2);
    if(p % 2 == 0)
        return pow * pow;
    else
        return e * pow * pow;
}

// main function
int main()
{
    int e, p;
    cin >> e >> p;
    int &&pow = power(e, p);
    if (pow == -1)
        cout << "Undefined" << endl;
    else
        cout << e << "^" << p << " = " << pow << endl;

    return 0;
}