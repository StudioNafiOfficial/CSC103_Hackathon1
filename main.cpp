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
    vector<string> text;
    textFS.open(textFilename);
    if (textFS.is_open()) {
        while (!textFS.eof() && textFS.good()) {
            if (!textFS.fail()) {
                textFS >> input;
                text.push_back(input);
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

    // read out all the lines (remove later, just making sure it works)
    cout << "KEYS: " << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < keys.size(); i++) {
        cout << keys.at(i) << " ";
    }
    cout << endl << endl;
    cout << "TEXT: " << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < text.size(); i++) {
        cout << text.at(i) << " ";
    }
    cout << endl << endl;


    return 0;
}