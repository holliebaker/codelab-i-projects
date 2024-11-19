/**
 * Enygma Machine
 *
 * An implementation of the basic (three-rotor) enygma machine
 * see https://www.codesandciphers.org.uk/enigma/index.htm
 */

#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_LENGTH = 26;

// rotor and reflector configurations
const char ROT_III[]   = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
const char ROT_II[]    = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
const char ROT_I[]     = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
const char REFLECTOR[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
const int NOTCH_II = 7;
const int NOTCH_I = 19;

/**
 * Perform the substitution with given rotor at given postion, on given character
 */
char subst(const char rotor[], int disp, char c);

/**
 * Perform the reverse substitution with given rotor at given postion, on given character
 */
char revSubst(const char rotor[], int disp, char c);

/**
 * Run Enygma machine on given string
 */
string enygma(string plainText);

int main(int argc, const char **argv)
{
    if (argc < 2) {
        cerr << "Error: please enter some plaintext to encrypt." << endl;

        return 1;
    }

    // first argument is the plaintext
    string plainText = (argv[1]);

    // encipher
    string cipherText = enygma(plainText);

    // print
    cout << plainText << endl;
    cout << cipherText << endl;

    return 0;
}

char subst(const char rotor[], int disp, char c)
{
    // treating char as int, find the index to look up in rotor
    int index = (c - 'A' + disp) % ALPHABET_LENGTH;

    return rotor[index];
}

char revSubst(const char rotor[], int disp, char c)
{
    // given rotor, displacement and input C, we need to find D such that D -> C
    // .e., locate the index of C in the rotor
    int index;
    for (index = 0; index < ALPHABET_LENGTH && rotor[index] != c; index++); // linear search loop

    // convert back to a character, using ascii magic!
    cout << (index + (26 - disp)) % ALPHABET_LENGTH << endl;
    return 'A' + (index + (26 - disp)) % ALPHABET_LENGTH;
}

string enygma(string plainText)
{
    // initial displacements
    int dispIII = 25, dispII = 0, dispI = 0;

    // initial cipher text, to populate later
    int len = (int) plainText.length();
    string cipherText = plainText;

    for (int i = 0; i < len; i++) {
        dispIII = (dispIII + 1) % ALPHABET_LENGTH; // rotate rotor III every time current passes
        if (dispIII == NOTCH_II) dispII = (dispII + 1) % ALPHABET_LENGTH; // rotate rotor II when the notch on rotor III catches it
        if (dispII == NOTCH_I) dispI = (dispI + 1) % ALPHABET_LENGTH; // rotate rotor I when the notch on rotor II catches it
        cout << dispIII << ", " << dispII << ", " << dispI << endl;

        // current passes "forward" through the three rotors, from rght to left
        char in = toupper(plainText[i]), c = in;
        c = subst(ROT_III, dispIII, c); // rotor III, forward
        c = subst(ROT_II, dispII, c); // rotor II, forward
        c = subst(ROT_I, dispI, c); // rotor I, forward

        // then current hits the reflector.
        // this performs a further substitution, and sends the current back in the opposite direction
        c = subst(REFLECTOR, 0, c); // substitution given by the reflector

        // current now passes back through the rotors in the opposite direction
        c = revSubst(ROT_I, dispI, c); // rotor I, backward
        c = revSubst(ROT_II, dispII, c); // rotor II, backward
        c = revSubst(ROT_III, dispIII, c); // rotor III, backward

        cipherText[i] = c;

        // output substitution
        cout << in << " -> " << cipherText[i] << endl;
    }

    return cipherText;
}
