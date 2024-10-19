/*
  Hello World
  Prints "hello world" to the console.
*/

#include <iostream> // this pastes the contents of iestream into the file,
                    // this gives us access to standard c++ library function for reading and writing data
#include <string>
using namespace std;

// every c++ program should have a main function
// the main function is the entry point of our program
int main()
{
    // write hello world to standard out
    // cout is the output stream
    // << is the insertion operator
    // endl writes a new line and prints everything to standard out
    cout << "It's raining, so hard!!" << endl;

    // doing variable things
    // <type> <name>;
    int myNumber; // declare a new integer, call it myNumber. right now the value is unknown
    // initialise myNumber
    cout << "My number is not initialised. its value is " << myNumber << endl;
    myNumber = 5;

    // declaration and initialisation
    // <type> <name> = <initial-value>
    double myDecimal = 2.707; 
    bool isRaining = true;

    cout << "The value of myNumber is " << myNumber << endl;
    cout << "The value of myDecimal is " << myDecimal << endl;    
    cout << "The value of isRaining is " << isRaining << endl;

    // re-assigning variables
    myNumber = 26;
    cout << "I re-initialised myNumber, it's now value is " << myNumber << endl;

    // it stopped raining
    isRaining = false;
    cout << "The new value of isRaining is " << isRaining << endl;

    // string things
    string usersName = "Arthur Dent";
    cout << "Welcome, " << usersName << "!" << endl;

    usersName = "John Appleseed";
        cout << "Welcome, " << usersName << "!" << endl;

    if (myNumber > 0) {
        if (myNumber % 2 == 0) {
            // different things
        } else {
            // more things
        }
    } else {
        // do something else
    }

    // every main function should return an integer value
    // 0 indicates that the function completed successfully
    return 0;
}
