#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {

    // put every key into a vector

    string input;
    string keysFilename = "keys.txt";
    fstream keysFS;
    vector<string> keys;
    keysFS.open(keysFilename);
    if (keysFS.is_open()) {
        while (!keysFS.eof() && keysFS.good()) {
            if (!keysFS.fail()) {
                keysFS >> input;
                keys.push_back(input);
            }
        }
        if (!keysFS.eof()) {
            cout << "Error reading " << keysFilename << "." << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cout << "Could not open " << keysFilename << "." << endl;
        return 1;
    }

    // put every line of text into a vector 

    string textFilename = "7.txt";
    fstream textFS;
    vector<string> plaintext;
    textFS.open(textFilename);
    if (textFS.is_open()) {
        while (!textFS.eof() && textFS.good()) {
            if (!textFS.fail()) {
                textFS >> input;
                plaintext.push_back(input);
            }
        }
        if (!textFS.eof()) {
            cout << "Error reading " << textFilename << "." << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cout << "Could not open " << textFilename << "." << endl;
        return 1;
    }

    /**
    * Part 1: Decrypt.
    * We must:
    *   1) Output a frequency analysis showing the counts of every letter of your team's encrypted text
    *   2) Output the correct key that we discovered
    *   3) Output the correct original (decrypted) English plaintext
    *   4) Output a description of the context of this plaintext - where is this text from, and what does it mean? what does your team think of this text?
    */
    
    vector<string> decryptedText = plaintext;
    vector<int> keyShifts;
    int currKeyShiftIndex;
    cout << "STARTING MAIN LOOP" << endl;
    for (int keyIndex = 0; keyIndex < keys.size(); keyIndex++) {
        cout << "FOR EVERY KEY INDEX: " << endl;
        for (int keyLetterIndex = 0; keyLetterIndex < keys.at(keyIndex).size(); keyLetterIndex++) {
            cout << "FOR EVERY KEY LETTER INDEX: " << endl;
            if (isupper(keys.at(keyIndex).at(keyLetterIndex))) {
                keyShifts.push_back(-1 * int(keys.at(keyIndex).at(keyLetterIndex)) - 'A' + 1);
            } else {
                keyShifts.push_back(-1 * int(keys.at(keyIndex).at(keyLetterIndex)) - 'a' + 1);
            }
        }
        cout << "CALCULATED ALL KEYS!" << endl;
        currKeyShiftIndex = 0;
        for (int textIndex = 0; textIndex < plaintext.size(); textIndex++) {
            cout << "FOR EVERY TEXT INDEX: " << endl;
            for (int textLetterIndex = 0; textLetterIndex < plaintext.size(); textLetterIndex++) {
                cout << "FOR EVERY TEXT LETTER INDEX: " << endl;
                if (isalpha(plaintext.at(textIndex).at(textLetterIndex))) {
                    cout << "IF LETTER IS ALPHA" << endl;
                    if (!isalpha(plaintext.at(textIndex).at(textLetterIndex)) + keyShifts.at(currKeyShiftIndex)) {
                        cout << "IF RESULT ISN'T ALPHA" << endl;
                        if (islower(plaintext.at(textIndex).at(textLetterIndex))) {
                            decryptedText.at(textIndex).at(textLetterIndex) = (plaintext.at(textIndex).at(textLetterIndex) - 'a' + keyShifts.at(currKeyShiftIndex)) % 26 + 'a';
                        } else {
                            decryptedText.at(textIndex).at(textLetterIndex) = (plaintext.at(textIndex).at(textLetterIndex) - 'A' + keyShifts.at(currKeyShiftIndex)) % 26 + 'A';
                        }
                    } else {
                        decryptedText.at(textIndex).at(textLetterIndex) = plaintext.at(textIndex).at(textLetterIndex) + keyShifts.at(currKeyShiftIndex);
                    }
                } else {
                    decryptedText.at(textIndex).at(textLetterIndex) = plaintext.at(textIndex).at(textLetterIndex);
                }
                cout << "DONE WITH LETTER: INCREMENT KEY" << endl;
                currKeyShiftIndex++;
                currKeyShiftIndex = currKeyShiftIndex % keyShifts.size();
            }
            currKeyShiftIndex++;
            currKeyShiftIndex = currKeyShiftIndex % keyShifts.size();
        }
        
        cout << endl;
    }


    return 0;
}