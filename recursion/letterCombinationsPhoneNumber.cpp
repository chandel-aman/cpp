/*
explanation for the below code when the input is 23
letterCombinations("23")   // calls findCombinations with initial arguments
                            // digits="23", output=[], combination="", digitLetterMapping=["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"], i=0
    findCombinations("23", [], "", digitLetterMapping, 0) // i=0
        digit = 2
        mappedString = "abc"
        loop over characters in mappedString:
            combination = "a"
            findCombinations("23", [], "a", digitLetterMapping, 1) // i=1
                digit = 3
                mappedString = "def"
                loop over characters in mappedString:
                    combination = "ad"
                    findCombinations("23", [], "ad", digitLetterMapping, 2) // i=2
                        base case met: add "ad" to output
                    combination = "ae"
                    findCombinations("23", [], "ae", digitLetterMapping, 2) // i=2
                        base case met: add "ae" to output
                    combination = "af"
                    findCombinations("23", [], "af", digitLetterMapping, 2) // i=2
                        base case met: add "af" to output
        return output = ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

*/

#include <bits/stdc++.h>
using namespace std;

// function to get all combination of letters using back tracking algorithm
void backTracking(string input, vector<string> &output, string combination, string mappedArray[], int index)
{
    // base case
    if (index >= input.length())
    {
        // add the resultant combination at the end of each recursive cycle
        output.push_back(combination);
        // return the function
        return;
    }

    // recursive case
    // extracting the digit corresponding to the index
    int digit = input[index] - '0';
    // storing the mapped letters for the corresponding digit
    string mappedString = mappedArray[digit];

    // iterating over the length of mapped string to find all the combinations
    for (int i = 0; i < mappedString.length(); i++)
    {
        // adding the letter at index i in mapped string to the combination string
        combination.push_back(mappedString[i]);
        // calling the function itself to check for the base case and return the value, or to backtrack and go on with next digit in the input
        backTracking(input, output, combination, mappedArray, index + 1);
        // once we are back tracking we want our combination to begin from start, so remove the added letter from the mapped string
        combination.pop_back();
    }
}

// function to return all the combination of letters for a given digit seqeuence
vector<string> findCombinations(string input)
{
    vector<string> output;
    if (input.length() == 0)
        return output;

    string combination = "";
    // mapped string array of strings with the respective digits
    string mappedArray[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuvw",
    };

    // index to iterate over the input string
    int index = 0;

    // invoking the backtracking function to find all the possible combinations
    backTracking(input, output, combination, mappedArray, index);

    // return the output once all the recursion is over
    return output;
}

int main()
{
    string input;

    cout << "All the digits should be between 2-9." << endl;
    cout << "Enter the digits: ";
    cin >> input;

    if (input.find("0") != string::npos || input.find("1") != string::npos)
    {
        cout << "INVALID INPUT" << endl;
        return 0;
    }

    vector<string> output = findCombinations(input);

    // displaying the vector with all combinations of letter for the given digit seqeuence
    cout << endl;
    for (string s : output)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}