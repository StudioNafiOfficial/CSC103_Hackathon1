#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    //-------------------------------------------just for easy testing
    vector<string> keys = {"education", "fill", "symptomatic", "ice", "endurable", "massive", "ajustment", "servant", "absorbing", "chivalrous", "share", "hammer", "letter", "outrageous", "gifted", "snobbish", "delicious", "difficult", "land", "filthy", "tick", "alluring", "dangerous", "pigs", "farm", "drop", "juggle", "available", "suggest", "lunch", "brash", "innate", "frightened", "song", "astonishing", "gigantic", "arch", "home", "turn", "bubble", "apparel", "raspy", "clip", "loud", "huge", "tangy", "steep", "first", "brother", "load", "wacky", "numberless", "bomb", "trick", "organic", "shut", "stupid", "well-off", "frequent", "intend", "bird", "plot", "sticky", "longing", "waste", "breakfast", "addition", "rough", "creator", "squirrel", "rest", "windy", "obsolete", "gleaming", "arrogant", "list", "vulgar", "shop", "orange", "blade", "hurt", "mom", "powerful", "acrid", "sponge", "snotty", "hypnotic", "park", "noiseless", "anxious", "thunder", "jog", "fabulous", "nod", "boot", "man", "coat", "drag", "heat", "spiffy", "pen", "steadfast", "sea", "face", "prevent", "reply", "tramp", "peck", "explode", "bore", "crate", "unable", "aboriginal", "silent", "sleet"};

    string text = "HIWO YEEC HJUO WIGK WOWK PEOI GBDU PFKE WDHO EXXV BTBI DXTW HIWX LGJY OSVZ ZSFA SBNS DJES KFJG LRWP SBNS DXAI OOSZ JXBG OMWB RMGI VBKB ZTKI HFFG TSGW KISH PZXV HPGF TKBR OUWO YCML WOYW EGTR RPOV LXXZ SSOS VRHA VPOH ZSKH SSAH ESII FGGF XMMG OOXC WPHA OOSZ JWBW PVLW ELTW BPHC HIKS TBFH TGBT OUAB REGC OOSZ JXBG OMJS WEMM COKC CXKY HIKW EWIV CWAB NIBW HPSG DMLX ITAB XEDM BHSJ LMEE PMWK SEMA SBJS LPKI OEQO NUNE WOLS OABX VUZS CITV SJFO WPXB HFFG TSGW CGZI XEGT CXWF ZVTH RJLW ZRLX CIMA LRDR CXDS OKXZ OSAC FWVS ZMSH PVTP WOXZ FIGG STTS DMWI GUZS XEBR OOVD CMFE FZGP UIVX OULO TRXH";
    //----------------------------------------------------------------
    
    string text1 = "";

    for (unsigned int i = 0; i < text.size(); i++){
        if (!isspace(text.at(i))) {
            text1 += text.at(i);
        }
    }

    // for (unsigned int i = 0; i < text1.size(); i++) {
    //     cout << text1.at(i);
    // }

    // cout << endl << text1.size() << endl << endl << text.size() << endl;



    //NEED For loop to iterate through keys
    //NEED Adjacent Vector with the keys repeated for all 464 characters
        //probably using (% keys.at(i).size())

    //Another loop to iterate along both string / vector at the same indexes, un-raveling the text.
        //Can have a counter to check if the number of consonants in a row ever reaches past 7 or 8, abort key immediately
        //Can add a counter and checks if the consonants are NOT in any common form like "th" "sh" 

    unsigned int i;
    int j;
    int text1Size = text1.size();
    int kSize;

    // string key = "";
    // for (i = 1; i < 2; i++) {                       //the 1 here is going to be keys.size();
    //     kSize = keys.at(i).size();
    //     for (j = 0; j < text1Size; j++) {
    //         key += keys.at(i).at(j % kSize);
    //     }
    // }


    //                                    // --------------------------- TESTING IF string key WORKED
    // for (i = 0; i < text1Size; i++) {                     
    //     cout << key.at(i);
    // }
    // cout << endl << endl << key.size() << endl; 
    



    // WE NOW HAVE spaceless TEXT, repeated keys

    // ---------------------------------------------------CEASER CIPHER respective INDEXes

    // string ciphered = "";
    // int consonants = 0;
    // char c;

    // for (i = 0; i < text1Size; i++) {
    //     //cout << text1.at(i) << "    and    " << char(toupper(key.at(i))) << endl;
    //     ciphered += (((text1.at(i) - 'A') - (toupper(key.at(i)) - 'A') + 26) % 26) + 'A';
    //     cout << ciphered.at(i);
    //     c = ciphered.at(i);
    //     if ((c != 'A') && (c != 'E') && (c != 'I') && (c != 'O') && (c != 'U') && (c != 'Y')){
    //         consonants++;
    //         if (consonants > 7) {
    //             cout << endl << endl << "RANDOM LETTERS DETECTED, ABORTING KEY" << endl << endl;
    //             break;                  //break out of the entire key checking
    //         }
    //     } else {
    //         consonants = 0;
    //     }
    // }
    
    
    //-----------------------------------------------------------------------------------------



    // PUT these together
    
    
    string key = "";
    string ciphered = "";
    int consonants = 0;
    char c;
    int cS;

    for (i = 0; i < keys.size(); i++) {                             // keys.size()
        // ----------------------------------- KEY setup
        kSize = keys.at(i).size();
        for (j = 0; j < text1Size; j++) {
            key += keys.at(i).at(j % kSize);
        }
        //---------------- LOGIC

        for (j = 0; j < text1Size; j++) {
            //cout << text1.at(i) << "    and    " << char(toupper(key.at(i))) << endl;
            ciphered += (((text1.at(j) - 'A') - (toupper(key.at(j)) - 'A') + 26) % 26) + 'A';    // used google / ai for a refresher of the decrypt formula, edited the formula to make it work in this way.
            cout << ciphered.at(j);
            
            c = ciphered.at(j);
            if ((c != 'A') && (c != 'E') && (c != 'I') && (c != 'O') && (c != 'U') && (c != 'Y')){
                consonants++;
                if (consonants > 4) {           //started off with 7, lowest it works with is 4;
                    cout << endl << endl << "RANDOM letters DETECTED, ABORTING key " << i << endl << endl;
                    key = "";
                    ciphered = "";
                    consonants = 0;
                    break;                  //break out of the entire key checking, reset all variables
                }
            } else {
                consonants = 0;
            }
        }
        // ------------------------------------ Possible check if answer is found
        cS = ciphered.size();
        if (cS == text1Size) {
            break;
        }

        // -------------------------
    }

    return 0;
}