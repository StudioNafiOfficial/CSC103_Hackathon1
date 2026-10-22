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
    string plaintext;
    textFS.open(textFilename);
    if (textFS.is_open()) {
        while (!textFS.eof() && textFS.good()) {
            if (!textFS.fail()) {
                textFS >> input;
                plaintext += input;
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

    string text1 = plaintext;
    string ciphered = "";
    string key = "";
    int consonants = 0;
    char c;

    // for (unsigned int i = 0; i < plaintext.size(); i++) {
    //     if (!isspace(plaintext.at(i))) {
    //         text1 += plaintext.at(i);
    //         cout << plaintext.at(i) << endl;
    //     }
    // }

    for (int i = 0; i < keys.size(); i++) {
        for (int j = 0; j < text1.size(); j++) {
            key += keys.at(i).at(j % keys.at(i).size());
        }

        for (int j = 0; j < text1.size(); j++) {
            ciphered += (((text1.at(j) - 'A') - (toupper(key.at(j)) - 'A') + 26) % 26) + 'A';
            cout << ciphered.at(j);

            c = ciphered.at(j);
            if ((c != 'A') && (c != 'E') && (c != 'I') && (c != 'O') && (c != 'U') && (c != 'Y')) {
                consonants++;
                if (consonants > 4) {
                    cout << "rand letters, abort key " << i << endl;
                    key = "";
                    ciphered = "";
                    consonants = 0;
                    break;
                }
            } else {
                consonants = 0;
            }
        }

        if (ciphered.size() == text1.size()) {
            break;
        }
    }
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    

    vector<int> decryptedLetterFrequencies (27, 0);
    vector<int> encryptedFrequencies (27, 0);

    cout << "DECRYPTED: " << endl;
    for (int i = 0; i < ciphered.size(); i++) {
        decryptedLetterFrequencies.at(ciphered.at(i) - 'A' + 1) += 1;
    }

    for (int i = 1; i < decryptedLetterFrequencies.size(); i++) {
        cout << (char) ('A' + (i - 1)) << "'s: " << decryptedLetterFrequencies.at(i) << " | ";
    }

    cout << endl << "ENCRYPTED: " << endl;
    for (int i = 0; i < plaintext.size(); i++) {
        encryptedFrequencies.at(plaintext.at(i) - 'A' + 1) += 1;
    }

    for (int i = 1; i < encryptedFrequencies.size(); i++) {
        cout << (char) ('A' + (i - 1)) << "'s: " << encryptedFrequencies.at(i) << " | ";
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

    cout << endl;
    cout << endl;

    cout << "DECRYPTED TEXT: " << endl << endl;
    for (int i = 0; i < ciphered.size(); i++) {
        cout << ciphered.at(i);
    }

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