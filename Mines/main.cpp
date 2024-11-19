#include <iostream>
#include <string>
#include <time.h>
using namespace std;

/**
 * Minesweeper!!
 */

int main()
{
    // seed for random numbers based on current time
    srand(time(NULL));

    // use a 2d array for the grid
    const int ROWS = 5;
    const int COLS = 7;
    int mines[ROWS][COLS];
    int revealed[ROWS][COLS];

    // track the number of clear squares, as the goal is to uncover them all.
    int clearSquares = 0;

    // initialise the grid
    for (int row = 0; row < ROWS; row++) {
        // for each row in the grid
        for (int col = 0; col < COLS; col++) {
            // go through each column

            // randomly decide if there is a mino on this square
            bool hasMine = (rand() % 5) == 0; // one in five chance of there being a mine on that square

            // initialise the mines grid, square [row][ccol]
            mines[row][col] = hasMine;

            // initially all squares are covered
            revealed[row][col]= false;

            // cound how many clear squares we have
            if (!hasMine) {
                clearSquares++;
            }

            // debugging
            if (hasMine) {
                cout << "Mine at " << row << ", " << col << endl;
            }
        }
    }

    // game loop
    // stops when we have uncovered all clear squares
    int numRevealed = 0;
    while (clearSquares > numRevealed) {
        // print number of squares left to reveal
        cout << "Number of squares to reveal: " << (clearSquares - numRevealed) << endl;

        // print grid
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (!revealed[row][col]) {
                    // square covered
                    cout << "# ";
                } else {
                    // square does not contain a mine
                    // figure out how many mines in surrounding squares
                    int surroundingMines = 0;

                    if (row > 0 && mines[row - 1][col]) {
                        // there is a mine above
                        surroundingMines++;
                    }

                    if (col > 0 && mines[row][col - 1]) {
                        // there is a mine to the left
                        surroundingMines++;
                    }

                    // last element is ROWS - 1
                    if (row - 1 < ROWS && mines[row + 1][col]) {
                        // there is a mine below
                        surroundingMines++;
                    }

                    if (col + 1 < COLS && mines[row][col + 1]) {
                        // there is a mine to the right
                        surroundingMines++;
                    }

                    // print either the number of mines, or a blank square if none
                    if (surroundingMines > 0) {
                        cout << surroundingMines << " ";
                    } else {
                        cout << "  ";
                    }
                }
            }

            // end of row, print new line
            cout << endl;
        }


        int showRow, showCol;
        cin >> showRow >> showCol;

        // number validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cerr << "Please enter a number." << endl;
            continue;
        }

        // range validation
        if (showRow < 0 || showRow >= ROWS || showCol < 0 || showCol >= COLS) {
            cerr << "Index out of range." << endl;

            continue;
        }

        // valid number. check if we hit a mine.
        if (mines[showRow][showCol]) {
            cout << "BOOOOOM!" << endl;

            break; // lose, ext game lop
        }

        // otherwise, reveal the square
        revealed[showRow][showCol] = true;
        numRevealed++;
    }

    return 0;
}
