#include "Hashtable.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

// If the string parameter is not in the HashTable parameter, returns
// all string in the HashTable parameter that can be made by deleting
// a single letter from the string parameter.
vector<string> extraLetter (const HashTable & dict, string word)
{
    vector<string> result;
    // Check if the parameter 'word' is in the parameter 'dict'. If the 
    // word is in the dict, add the word to the vector and return the vector.
    if (dict.find(word)){
        result.push_back(word);
        return result;
    }
    // Else, using a temp string and the string member function erase(), 
    // erase one letter from the word and check if the word is in the dict.
    // If it is, then add the word to the vector. Else, reset the word and 
    // erase the next letter. Repeat until all the letters have been erased once. 
    else{
        string tempWord;
        vector<string>::iterator it;
        for (int i=0; i<word.size(); i++){
            tempWord = word;
            tempWord.erase(i,1);
            // Only insert the word into the vector if the word is not already 
            // in the vector.
            it = find(result.begin(), result.end(), tempWord);
            if(dict.find(tempWord)&&it==result.end()){
                result.push_back(tempWord);
            }
        }
        // Sort the vector before returning it by using the algorithm member 
        // function sort.
        sort(result.begin(), result.end());
    }
    return result;
}

// If the string parameter is not in the HashTable parameter, returns
// all string in the HashTable parameter that can be made swapping any
// two adjacent letters in word.
vector<string> transposition (const HashTable & dict, string word)
{
    vector<string> result;
    // Check if the parameter 'word' is in the parameter 'dict'. If the 
    // word is in the dict, add the word to the vector and return the vector.
    if (dict.find(word)){
        result.push_back(word);
        return result;
    }
    // Else, using a temp string and temp char to not alter the real word, 
    // swap adjacent letters in the word starting from the left and check if 
    // the word is in the dict. If it is, then add the word to the vector. Else,
    // reset the word and swap the next letter. Repeat until all letters have
    // been swapped once.
    else{
        string tempWord;
        char tempLetter;
        vector<string>::iterator it;
        for (int i=0; i<word.size()-1; i++){
            tempWord = word;
            tempLetter = tempWord[i];
            tempWord[i] = tempWord[i+1];
            tempWord[i+1] = tempLetter;
            // Only insert the word into the vector if the word is not already 
            // in the vector.
            it = find(result.begin(), result.end(), tempWord);
            if(dict.find(tempWord)&&it==result.end()){
                result.push_back(tempWord);
            }
        }
        // Sort the vector before returning it by using the algorithm member 
        // function sort.
        sort(result.begin(), result.end());
    }
    return result;
}

// If the string parameter is not in the HashTable parameter, returns
// all string in the HashTable parameter that can be made by inserting a single
// space in word; each string in the result should consist of the two strings 
// from dict separated by a space.
vector<string> missingSpace (const HashTable & dict, string word)
{
    vector<string> result;
    // Check if the parameter 'word' is in the parameter 'dict'. If the 
    // word is in the dict, add the word to the vector and return the vector.
    if (dict.find(word)){
        result.push_back(word);
        return result;
    }
    // Else, using temp strings to not alter the real word and using the string
    // member function insert(), insert a space between letters starting from the 
    // left. Then, separate the new word containing the space into two sub-strings
    // using the string member function substr(). Check if both words are in the
    // dict. If it is, then add the word to the vector. Else, reset the word and
    // add the space between the next letters. Repeat until a space was add between
    // every letter.
    else{
        string tempWord, firstWord, secondWord;
        vector<string>::iterator it;
        for (int i=0; i<word.size()-1; i++){
            tempWord = word;
            tempWord.insert(i+1," ");
            firstWord = tempWord.substr (0, i+1);
            secondWord = tempWord.substr (i+2);
            // Only insert the word into the vector if the word is not already 
            // in the vector.
            it = find(result.begin(), result.end(), tempWord);
            if(dict.find(firstWord)&&dict.find(secondWord)&&it==result.end()){
                result.push_back(tempWord);
            }
        }
        // Sort the vector before returning it by using the algorithm member 
        // function sort.
        sort(result.begin(), result.end());
    }
    return result;
}

// If the string parameter is not in the HashTable parameter, returns
// all string in the HashTable parameter that can be made by inserting
// any single letter of the alphabet at any position in word.
vector<string> missingLetter (const HashTable & dict, string word)
{
    vector<string> result;
    // Check if the parameter 'word' is in the parameter 'dict'. If the 
    // word is in the dict, add the word to the vector and return the vector.
    if (dict.find(word)){
        result.push_back(word);
        return result;
    }
    // Else, using temp strings to not alter the real word and a string
    // member function insert(), insert a letter starting at the left of 
    // the word and starting with the letter a. If the new word is in 
    // dict, add the word to the vector. Else, check the next letter. 
    // Once, all the letters have been checked, reset the word and insert
    // the letter one index to the right. Repeat until all letters have 
    // been inserted at all positions in the word.
    else{
        string tempWord, tempLetter;
        vector<string>::iterator it;
        for (int i=0; i<word.size()+1; i++){
            for (int j=0; j<26; j++){
                tempWord = word;
                tempLetter = j+97;
                tempWord.insert(i, tempLetter);
                // Only insert the word into the vector if the word is not already 
                // in the vector.
                it = find(result.begin(), result.end(), tempWord);
                if(dict.find(tempWord)&&it==result.end()){
                    result.push_back(tempWord);
                }
            }
        }
        // Sort the vector before returning it by using the algorithm member 
        // function sort.
        sort(result.begin(), result.end());
    }
    return result;    
}

// If the string parameter is not in the HashTable parameter, returns
// all string in the HashTable parameter that can be made by changing any
// single letter of word to a different letter in the alphabet.
vector<string> incorrectLetter (const HashTable & dict, string word)
{
    vector<string> result;
    // Check if the parameter 'word' is in the parameter 'dict'. If the 
    // word is in the dict, add the word to the vector and return the vector.
    if (dict.find(word)){
        result.push_back(word);
        return result;
    }
    // Else, using a temp string, replace letters from the word starting from
    // the left. Replace the letters from a to z and check if the new word is 
    // in the dict. If it is, add the word to the vector. Else, reset the word
    // and move to the next letter of the word. Repeat until all the letters
    // of the word has been replaced once.
    else{
        string tempWord;
        vector<string>::iterator it;
        for (int i=0; i<word.size(); i++){
            for (int j=0; j<26; j++){
                tempWord = word;
                tempWord[i] = j+97;
                // Only insert the word into the vector if the word is not already 
                // in the vector.
                it = find(result.begin(), result.end(), tempWord);
                if(dict.find(tempWord)&&it==result.end()){
                    result.push_back(tempWord);
                }
            }
        }
        // Sort the vector before returning it by using the algorithm member 
        // function sort.
        sort(result.begin(), result.end());
    }
    return result;   
}
