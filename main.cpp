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
    // cout << "KEYS: " << endl;
    // cout << "-----------------------" << endl;
    // for (int i = 0; i < keys.size(); i++) {
    //     cout << keys.at(i) << " ";
    // }
    // cout << endl << endl;
    // cout << "TEXT: " << endl;
    // cout << "-----------------------" << endl;
    // for (int i = 0; i < text.size(); i++) {
    //     cout << text.at(i) << " ";
    // }
    // cout << endl << endl;

        // ------------------------- PART 2 (ENCRYPTION) -------------------------
    cout << endl << "PART 2" << endl << endl; 

    int seed = 1;
    int userInput = 0;
    string userText;
    string randomKey;
    

    cout << "Enter a seed value: ";
    cin >> seed;
    cout << "Enter the text to encrypt: ";
    cin.ignore();
    getline(cin, userText);

    userInput = userText.size();

    long long rand = (((seed * seed * seed * seed * 26921 )));
    int counter = 1;                           

    while (counter < userInput + 1){                             
        
        while (rand <= 1000){
            rand = ((rand+1786) * (seed+7234) * (seed+3863) * (seed+59) * (26921  * counter) );

        }
        
        rand = (rand / 10000) * 9501;
        counter++;
        // seed++;

        // cout << "Random number: " << rand << endl; // debugging purposes, can remove later
        randomKey += (rand % 26) + 'A';

    }

    string outputFilepath = "encrypt.txt";
    ofstream outputFile;
    outputFile.open(outputFilepath, ios::app); // I figured using an ifstream would be similar to an ofstream, however I did not know how to append instead of overwriting. Had to google how to append instead of writing to a file in C++.

    for (int i = 0; i < userInput; i++) {
        userText.at(i) = toupper(userText.at(i));
        if (i!=0) {
            
        }
        outputFile << (char)((((userText.at(i) - 'A') + (randomKey.at(i) - 'A')) % 26) + 'A');
        cout << (char)((((userText.at(i) - 'A') + (randomKey.at(i) - 'A')) % 26) + 'A'); // used google/ai for a refresher on the encrypt formula
    }
    outputFile << endl;
    outputFile.close();


    return 0;
}