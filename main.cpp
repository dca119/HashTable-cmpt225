#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <fstream>
#include "HashTable.h"
#include "spellcheck.h"

using namespace std;


int main(){
    // TEST OF FUNCTIONS
    /*
    HashTable dict;
    fstream file;
    file.open("wordlist1000.txt", fstream::in);
    if( file.is_open() ) {
        string value;
        while(file >> value) {
            dict.insert(value);
        }
        file.close();
    }
    vector<string> result;
    result = extraLetter(dict, "addy"); // add, ddy
    cout << "Extra Letter: " << endl;
    for(int i=0; i<result.size(); i++){
        cout << result.at(i) << endl;
    }
    result = transposition(dict, "amogn"); // among, maogn
    cout << endl << "Transposition: " << endl;
    for(int i=0; i<result.size(); i++){
        cout << result.at(i) << endl;
    }
    result = missingSpace(dict, "become"); // be come, bec ome
    cout << endl << "Missing Space: " << endl;
    for(int i=0; i<result.size(); i++){
        cout << result.at(i) << endl;
    }
    result = missingLetter(dict, "ver"); // ever, over, very
    cout << endl << "Missing Letter: " << endl;
    for(int i=0; i<result.size(); i++){
        cout << result.at(i) << endl;
    }
    result = incorrectLetter(dict, "thed"); // shed, thee, them, then, they, thud, toed
    cout << endl << "Incorrect Letter: " << endl;
    for(int i=0; i<result.size(); i++){
        cout << result.at(i) << endl;
    }
    */



    // TRY TEST
    HashTable dict(10);

    fstream newfile;


    newfile.open("wordlist1000.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            // cout << tp << "\n"; //print the data of the string

            dict.insert(tp);
        }
        newfile.close(); //close the file object.
    }


    newfile.open("words2.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            // cout << tp << "\n"; //print the data of the string

            dict.insert(tp);
        }
        newfile.close(); //close the file object.
    }

    cout << "Testing extra letter" << endl;

    // TEST HERE 
    string testletter = "fire";




    vector <string> extraletters = extraLetter(dict,  testletter);

    for (int ii = 0; ii< extraletters.size(); ii++)
    {
    cout<< extraletters[ii] << endl;
    }

    cout << "~~~~" << endl;
    cout << "~~~~" << endl;
    cout << "~~~~" << endl;
    cout << "Testing transposition" << endl;


    vector <string> transpos = transposition(dict,  testletter);

    cout << transpos.size() << endl;
    for (int ii = 0; ii< transpos.size(); ii++)
    {
    cout<< transpos[ii] << endl;
    }

    cout << "~~~~" << endl;
    cout << "~~~~" << endl;
    cout << "~~~~" << endl;

    cout << "Testing missing space" << endl;

    vector <string> misspace = missingSpace(dict,  testletter);

    cout << misspace.size() << endl;
    for (int ii = 0; ii< misspace.size(); ii++)
    {
    cout<< misspace[ii] << endl;
    }

    cout << "~~~~" << endl;
    cout << "~~~~" << endl;
    cout << "~~~~" << endl;

    cout << "Testing Missing letter" << endl;

    vector <string> misslett = missingLetter(dict,  testletter);

    cout << misslett.size() << endl;
    for (int ii = 0; ii< misslett.size(); ii++)
    {
    cout<< misslett[ii] << endl;
    }




    cout << "~~~~" << endl;
    cout << "~~~~" << endl;
    cout << "~~~~" << endl;

    cout << "Testing incorrect letter" << endl;

    vector <string> incorlet = incorrectLetter(dict, testletter);

    cout << incorlet.size() << endl;
    for (int ii = 0; ii< incorlet.size(); ii++)
    {
    cout<< incorlet[ii] << endl;
    }




    return 0;
}