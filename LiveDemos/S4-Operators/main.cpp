#include <iostream>
#include <string>
using namespace std;

/*
    Codelab 1, Session 4

    Live demo code for Friday 11th October codelab 1 session.
    Covers variables, primitives, strings, input, output and operators.

    Hollie Baker, 11/10/2024
    Copyright (c) 2024, all rights reserved.
*/

int main()
{
    // Variables
    // initialise: <type> <name>;

    // declare and initialise some variables
    int age;
    age = 25;
    float height = 169.25; // here we declare and initialise all in one go
    double mass = 60.01257;
    bool isAsleep = true;

    cout << "Age = " << age 
      << ", height = " << height 
      << ", mass = " << mass 
      << ", isAsleep = " << isAsleep 
      << endl;

    // re-assign isAsleep
    isAsleep = 0; 
    cout << "new value of isAsleep is " << isAsleep << endl;

    // strings
    string welcomeMessage = "Hello, codelab 1!";
    cout << welcomeMessage << endl;

    // check if user can drink alcohol
    const int DRINKING_AGE = 18;
    bool canDrinkAlcohol = age >= DRINKING_AGE;
    // assignment operator = 

    // input and output
    // we outptu strings to our console using cout and the insertion operator
    cout << "Please enter your name." << endl;
    // insertion operator <<

    // declare a variable to store user's name, and read the name in from the console
    string usersName = "";
    // standard input (stuff typed on the console) is the stream cin
    // to read a value from a stream and store it in a variable, we use the extraction operator >>
    cin >> usersName;


    // greet the user by name
    cout << "Hello, " << usersName << endl;
    // extraction operator >>

    // mathematical operators
    int num1 = 5;
    int num2 = 3;
    int sum = num1 + num2;

    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;

    double myDouble = 3.5 + 2.6;
    double subtraction = 10.0 - 2.5;

    int myProduct = 5 * 3;
    int myDecimalProduct = 2.4 * 5.6;

    // division
    // floating point division
    float myDividend = 5.0 / 2.0;
    cout << "5.0 / 2.0 = " << myDividend << endl;
    float threeAndAThird = 10.0 / 3.0;
    cout << "10.0 / 3.0 = " << threeAndAThird << endl;

    // integer division with /, % (modulus % only works with integers)
    int share = 10 / 3;
    cout << "integer division of 10 / 3 is " << share << endl;
    int remainder = 10 % 3;
    cout << "the remainder of integer division of 10 / 3 is" << remainder << endl;
    
    // string concatenation
    string message = "Welcome, ";
    string name = "Oreo";
    string outputMessage = message + name;
    cout << outputMessage << endl;

    // by convention, returning 0 indicates that the program exited successfully
    return 0;
}