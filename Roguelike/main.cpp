#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// output messages
const string OUT_OF_BOUNDS = "Out of bounds!";
const string INVALID_COMMAND = "Invalid input.";

// emoji for game icons -- change to your preference :)
const string PLAYER = "🐶";
const string GOLD = "🧀";
const string EXIT = "🚪";
const string WALL = "🌳";
const string EMPTY = "  ";

int main()
{
    // seed for random number generation, based on current time
    srand(time(NULL));

    // dimension of game area
    int DIMENSION = 20;
    int VISIBLE = 3; // (VISIBLE * 2) + 1

    // exit position
    int exitX = rand() % DIMENSION;
    int exitY = rand() % DIMENSION;

    // multiple gold, array of x and y coordinates
    const int TOTAL_GOLD = 3;
    const int REQUIRED_GOLD = 1;

    int goldXs[TOTAL_GOLD];
    int goldYs[TOTAL_GOLD];
    bool goldTaken[TOTAL_GOLD] = { false };

    // initialise gold with random values
    for (int i = 0; i < TOTAL_GOLD; i++) {
        int randX = rand() % DIMENSION;
        int randY = rand() % DIMENSION;

        goldXs[i] = randX;
        goldYs[i] = randY;
        cout << "Gold at " << randX << ", " << randY << endl; // debugging
    }

    // player position
    int posX = DIMENSION / 2;
    int posY = DIMENSION / 2;

    // game variables
    bool play = true;
    int goldCollected = 0;
    int moves = 0;

    // game loop
    do {
        // print the grid with a double for loop
        //for (int i = posY - VISIBLE; i < posY + VISIBLE + 1 ; ++i) {
        for (int i = -1; i < DIMENSION + 1; i++) { // printing ALL HE MAP!
            // for (int j = posX - VISIBLE; j < posX + VISIBLE + 1; ++j) {
            for (int j = -1; j < DIMENSION + 1; ++j) { // printing ALL the map.
                // border
                if (i < 0 || i >= DIMENSION || j < 0 || j >= DIMENSION) {
                    cout << WALL;

                    continue;
                }

                // player position
                if (j == posX && i == posY) {
                    cout << PLAYER;

                    continue;
                }

                // exit
                if (j == exitX && i == exitY) {
                    cout << EXIT;

                    continue;
                }

                // gold
                // check if current square contains gold
                bool hasGold = false;
                for (int goldIndex = 0; goldIndex < TOTAL_GOLD; goldIndex++) { // loop through gold
                    // first check if it's already taken
                    if (goldTaken[goldIndex]) {
                        // don't draw, just keep searching

                        continue; // continue search loop
                    }

                    int goldX = goldXs[goldIndex];
                    int goldY = goldYs[goldIndex];

                    if (j == goldX && i == goldY) { // found
                        hasGold = true;

                        break; // exit search loop
                    }
                }

                // check for gold, print if needed
                if (hasGold) {
                    cout << GOLD;

                    continue; // continue print loop
                }

                // otherwise, empty square
                cout << "  ";
            }

            cout << endl; // end of row
        }

        cout << "Moves: " << moves
             << ", cheese eaten: " << goldCollected
             << ", cheese to win: " << REQUIRED_GOLD
             << endl;

        // end printing, do user input and process command
        string cmd;
        cin >> cmd;

        // if-else statement to process command. could alternatively switch on cmd[0]
        // wasd to move, q to exit x to pickup
        if (cmd == "q") {
            cout << "Quit.";
          
            play = false;
        } else if (cmd == "x") {
            // check for exit
            if (posX == exitX && posY == exitY) {
                // win check
                if (goldCollected < REQUIRED_GOLD) {
                    cout << "Insufficient cheese." << endl;
                } else {
                    cout << "You win!!" << endl;

                    play = false;
                }
            } else { // not exit, checking for gold
                int foundIndex = -1; // will remain -1 if not found, used in later check
                for (int goldIndex = 0; goldIndex < TOTAL_GOLD; goldIndex++) { // loop through gold
                    // first check if it's already taken
                    if (goldTaken[goldIndex]) {
                        // skip check, just keep searching

                        continue; // continue search loop
                    }
                    
                    // not taken, check if player is on this gold
                    int goldX = goldXs[goldIndex];
                    int goldY = goldYs[goldIndex];
                    if (posX == goldX && posY == goldY) {
                        foundIndex = goldIndex;

                        break; // exit search loop
                    }
                } // end search loop
                
                if (foundIndex != -1) { // -1 means not found
                    cout << "Num num num!" << endl;

                    ++goldCollected; // cound how much cheese we ate
                    goldTaken[foundIndex] = true; // mark as taken
                }

                // this gold check is almost identical to the one in the print loop -- refactor??
            }
        } else if (cmd == "a") { // left
            if (posX == 0) {
                cout << OUT_OF_BOUNDS << endl;
            } else {
                --posX;
                ++moves;
            }
        } else if (cmd == "d") { // right
            if (posX == DIMENSION - 1) {
                cout << OUT_OF_BOUNDS << endl;
            } else {
                ++posX;
                ++moves;
            }
        } else if (cmd == "w") { // up
            if (posY == 0) {
                cout << OUT_OF_BOUNDS << endl;
            } else {
                --posY;
                ++moves;
            }
        } else if (cmd == "s") { // down
            if (posY == DIMENSION - 1) {
                cout << OUT_OF_BOUNDS << endl;
            } else {
                ++posY;
                ++moves;
            }

            // the code for each movement operation is very repetitive, could that be refactored?
        } else {
            cout << INVALID_COMMAND << endl;
        }
        // this if-else is long! although each block is different and, apart from the movement, not repetitive, might be easier to follow if each command was its own function?
    } while (play);

    return 0;
}
