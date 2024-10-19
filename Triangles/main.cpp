/*
    Classify different types of triangle based on side length and angles
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // request, read and store input
    cout << "Please enter side lengths separated by new lines." << endl;
    double sideA, sideB, sideC;
    cin >> sideA;
    cin >> sideB;
    cin >> sideC;

    // print, for confirmation
    cout << "A = " << sideA << ", B = " << sideB << ", C = " << sideC << endl;

    // first check: is equalateral
    if (sideA == sideB && sideB == sideC) {
        // all sides equal length
        cout << "Equilateral" << endl;
    } else {
        // right angled, accute or obtuce. use pythagoras!
        // first, find longest side
        // rearrange so that C has longest length
        if (sideC < sideA) { // A is longer, swap with C
            double swp = sideA;
            sideA = sideC;
            sideC = swp;
        }

        // same with B and C
        if (sideC < sideB) { // swap B and C
            double swp = sideB;
            sideB = sideC;
            sideC = swp;
        }
        cout << "A = " << sideA << ", B = " << sideB << ", C = " << sideC << endl;

        // do a pythagoras
        double sumABSquare = pow(sideA, 2.0) + pow(sideB, 2.0);
        double sideCSquare = pow(sideC,2.0);

        if (sumABSquare == sideCSquare) { // a^2 + b^2 = c^2
            // pythagoras says it must be right angled
            cout << "Right angled" << endl;
        } else if (sumABSquare < sideCSquare) { 
            // hypotinuse is too long, must be obtuce
            cout << "Obtuce" << endl;
        } else { // otherwise, a^2 + b^2 > c^2 
            // hypotinuse is too short, must be accute
            cout << "Accute" << endl;
        }

        // finally work out if it's scalene (two sides of same length, or not
        if (sideA == sideB || sideB == sideC || sideA == sideC) { // two sdes of equal length
            cout << "Scalene" << endl;
        } else {
            cout << "All sides have diffeent length" << endl;
        }
    }

    return 0;
}
