/*
    Hollie's Live Demo
*/

#include <iostream>
#include <string>
using namespace std;

const string OOB = "Out of bounds!";
const string INV = "Invalid input.";

int main()
{
    // dimension of game area
    int DIMENSION = 20;
    int VISIBLE = 3; // (VISIBLE * 2) + 1

    // exit position
    int exitX = 1;
    int exitY = 1;

    // gold position
    int goldX = DIMENSION - 2;
    int goldY = DIMENSION - 2;

    // my position
    int posX = DIMENSION / 2;
    int posY = DIMENSION / 2;

    // game variables
    bool play = true;
    int goldCollected = 0;
    int REQUIRED_GOLD = 1;
    int moves = 0;

    // game loop
    do {
        // print the grid with a double for loop
        for (int i = posY - VISIBLE; i < posY + VISIBLE + 1 ; ++i) {
            for (int j = posX - VISIBLE; j < posX + VISIBLE + 1; ++j) {
                // border
                if (i < 0 || i >= DIMENSION || j < 0 || j >= DIMENSION) {
                    cout << "🌳";

                    continue;
                }

                // my position
                if (j == posX && i == posY) {
                    cout << "🐶";

                    continue;
                }

                // exit
                if (j == exitX && i == exitY) {
                    cout << "🚪";

                    continue;
                }

                // exit
                if (j == goldX && i == goldY) {
                    cout << "🧀";

                    continue;
                }

                cout << "  ";
            }

            cout << endl;
        }

        cout << "Moves: " << moves
             << ", cheese eaten: " << goldCollected
             << ", cheese to win: " << REQUIRED_GOLD
             << endl;

        // user input
        string cmd;
        cin >> cmd;

        // wasd to move
        if (cmd == "x") {
            cout << "Exit.";
          
            play = false;
        } else if (cmd == "u") {
            if (posX == goldX && posY == goldY) { // found cheese
                cout << "Num num num!" << endl;

                ++goldCollected;
            } else if (posX == exitX && posY == exitY) {
                if (goldCollected < REQUIRED_GOLD) {
                    cout << "Insufficient cheese." << endl;
                } else {
                    cout << "You win!!" << endl;

                    play = false;
                }
            }
        } else if (cmd == "a") { // left
            if (posX == 0) {
                cout << OOB << endl;
            } else {
                --posX;
                ++moves;
            }
        } else if (cmd == "e") { // right
            if (posX == DIMENSION - 1) {
                cout << OOB << endl;
            } else {
                ++posX;
                ++moves;
            }
        } else if (cmd == ",") { // up
            if (posY == 0) {
                cout << OOB << endl;
            } else {
                --posY;
                ++moves;
            }
        } else if (cmd == "o") { // down
            if (posY == DIMENSION - 1) {
                cout << OOB << endl;
            } else {
                ++posY;
                ++moves;
            }
        } else {
            cout << INV << endl;
        }
    } while (play);

    return 0;
}
