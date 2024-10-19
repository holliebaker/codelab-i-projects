/*
    Convert an arabic numeral from 1 to 10 into the corresponding roman numeral.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // request, read, store
    int num;
    cout << "Please enter a number from 1 to 10." << endl;
    cin >> num;

    // constants
    const string ONE = "i";
    const string FIVE = "v";
    const string TEN = "x";

    // to store reman numeral
    string roman = "";
    int original = num;
    if (num > 5) {
        roman = "v";
        num -= 5;
    }

    switch (num) {
        case 4:
            roman = ONE;

        case 5:
            if (original == 10) {
                roman = TEN;
            } else if (original > 5) {
                roman += TEN;
            } else {
                roman += FIVE;
            }
            break;

        case 3:
            roman += ONE;
        
        case 2:
            roman += ONE;

        case 1:
            roman += ONE;
            break;

        default:
            roman = "INVALID";
    }

    cout << "The roman numeral for " << num << " is " << roman << endl;

    return 0;
}
