#include <iostream>
#include "HashTable.h"
#include <string>
using std::string;

// Default constructor - creates a hash table default size: 101.
HashTable::HashTable()
{
    // Sets items to 0 and the hash table size to 101,
    // sets the value used by the second hash table,
    // creates a new hash table of size 101.
    items = 0;
    hashSz = 101;
    halfPrime = findPrime(hashSz/2);
    strArr = new string [101];
}

// Constructor - creates a hash table of size: 2n.
HashTable::HashTable(int n)
{   
    // Sets items to 0 and the hash table size to 
    // the first prime number greater than 2n,
    // sets the value used by the second hash table,
    // creates a new hash table of the hash table size.
    items = 0;
    hashSz = findPrime(2*n);
    strArr = new string [hashSz];
    halfPrime = findPrime(hashSz/2);
}

// Copy constructor - creates a deep copy of its HashTable 
// reference parameter.
HashTable::HashTable(const HashTable & ht)
{
    // Sets all private attributes to the reference parameter's
    // private attributes. Then, copy each element over to the
    // calling object's hash table.
    halfPrime = ht.halfPrime;
    items = ht.items;
    hashSz = ht.hashSz;
    strArr = new string[hashSz];
    for (int i=0; i<hashSz; i++){
        strArr[i] = ht.strArr[i];
    }
}

// Destructor - de-allocates any dynamic memory associated with
// the calling object.
HashTable::~HashTable()
{
    // Call delete on the calling object's hash table to de-allocate
    // any dynamic memory associated with it. Then, set the rest
    // of its private attributes to 0.
    delete [] strArr;
    items = 0;
    hashSz = 0;
    halfPrime = 0;
}

// Operator= - overloads the assignment operator for HashTable objects - 
// makes the calling object a deep copy of its HashTable reference parameter.
HashTable & HashTable::operator=(const HashTable & ht)
{
    // Check if the parameter is already the calling object.
    if (&ht!=this){
        // De-allocate the current calling object's hash table. Then,
        // set all private attributes to the reference parameter's
        // private attributes. Then, copy each element over to the
        // calling object's hash table.
        delete [] strArr;
        halfPrime = ht.halfPrime;
        items = ht.items;
        hashSz = ht.hashSz;
        strArr = new string[hashSz];
        for (int i=0; i<hashSz; i++){
            strArr[i] = ht.strArr[i];
        }
    }
    // Return a reference to the calling object.
    return *this;
}

// Insert - Searches the hash table for the method's string parameter,
// if a matching string is not found it inserts the parameter string
// into the hash table.
void HashTable::insert(string str)
{
    // If the string parameter is not found, insert the string parameter.
    if (!find(str)){

        // Call the insert helper function to insert the string into the hash
        // table using hash functions. Then, increment the current size by one.
        insertHelp(strArr,str);
        items++;

        // Check if the load factor exceeds 0.67.
        if (loadFactor()>0.67){

            // If it does, create a new hash table of size equal to the first 
            // prime number greater than twice the size of the original table.
            int temp = hashSz;
            hashSz = findPrime(hashSz*2);
            string* newHash = new string [hashSz];
            // Then, set the value used by the second hash function.
            halfPrime = findPrime(hashSz/2);
            // Then, insert the original contents in the new table using the 
            // hash functions again.
            for (int i=0; i<temp-1; i++){
                if (!strArr[i].empty()){
                    insertHelp(newHash, strArr[i]);
                }
            }
            // Delete the old hash table then, set the old pointer to the new hash table.
            delete [] strArr;
            strArr = newHash;
        }
    }
}

// Find - If its string parameter is in the hash table returns true, else
// returns false.
bool HashTable::find(string str) const
{
    // Call the first hash function to get the initial index of the string.
    int hash = h1(str);
    // Check if the string is there or not.
    if (strArr[hash]==str){
        return true;
    }
    // If the hash function is empty at the initial index, return false.
    else if (strArr[hash].empty()){
        return false;
    }
    // If there is a different string in the initial index, use the second
    // hash function to find the next index.
    else{
        int doubleHash = h2(str);
        hash += doubleHash;
        // Whenever adding the second hash function's value, check if the 
        // index exceeds the hash table size minus one. If it does, use modulo
        // to circle back into the hash table to get a valid index.
        if (hash>hashSz-1){
            hash = hash%hashSz;
        }
        // Check until the index is empty or the string is found.
        while (!strArr[hash].empty()&&strArr[hash]!=str){
            hash += doubleHash;
            if (hash>hashSz-1){
                hash = hash%hashSz;
            }   
        }
        // Check whether the index was empty or if the string was found.
        if (strArr[hash]==str){
            return true;
        }
    }
    return false;
}

// Size - Returns the current number of items stored in the hash table.
int HashTable::size()
{
    // Returns the private attribute that keeps track of the current
    // number of items in the hash table.
    return items;
}

// MaxSize - Returns the size of the hash table's underlying array.
int HashTable::maxSize()
{
    // Returns the private attribute that records the size of the underlying
    // array.
    return hashSz;
}

// LoadFactor - Returns the load factor of the hash table as a double.
double HashTable::loadFactor()
{
    // Check if the size of the underlying array is 0 or not. If it is,
    // return 0;
    double load = 0;
    if (hashSz!=0){
        // Load factor is the number of current items in the hash table
        // divided by the size of the underlying array.
        load = (double)items/(double)hashSz;
    }
    return load;
}


// HELPER FUNCTIONS 

// A helper function for insert. Inserts the string parameter into the string 
// array parameter.
void HashTable::insertHelp(string* arr, string str)
{
    // Call the first hash function to get the initial index of the string.
    int hash = h1(str);
    // Check if the index is empty or not. If it is, insert the string parameter
    // at the index.
    if (arr[hash].empty()){
        arr[hash] = str;
    }
    // Else, use the second hash function to find the next index.
    else{
        int doubleHash = h2(str);
        hash += doubleHash;
        // Whenever adding the second hash function's value, check if the 
        // index exceeds the hash table size minus one. If it does, use modulo
        // to circle back into the hash table to get a valid index.
        if (hash>hashSz-1){
            hash = hash%hashSz;
        }
        // Check until an empty index is found.
        while (!arr[hash].empty()){
            hash += doubleHash;
            if (hash>hashSz-1){
                hash = hash%hashSz;
            }
        }
        // Once an empty index is found, insert the string parameter
        // at the index.
        arr[hash] = str;
    }
}

// A helper function to find prime numbers. Checks each number greater than
// the integer parameter until a prime number is found.
int HashTable::findPrime(int n)
{
    int i = n+1;
    // Check each number greater than the integer parameter by calling the
    // isPrime helper function until it returns true.
    while(!isPrime(i)){
        i++;
    }
    return i;
}

// A helper function to check for prime numbers. Checks if its integer parameter
// is a prime number or not.
bool HashTable::isPrime(int n)
{
    bool prime = true;
    // Check if the integer parameter is 0 or 1.
    if (n==0 || n==1){
        prime = false;
    }
    // If it's not, then using each number starting at 2 to the integer parameter
    // divided by 2, check for prime by using (integer parameter % each number).
    else{
        for (int i=2; i<n/2&&prime; ++i){
            if (n%i==0){
                prime = false;
            }
        }
    }
    return prime;
}

// Hash function - Used by insertion and find to map strings to array indexes.
int HashTable::h1(string str) const
{
    // Use Horner's method for hashing all the individual characters in the string
    // to avoid an overflow. This is done by using modulo between each calculations
    // of the characters. The calculation is: string_value % array_size.
    int strVal = str[str.size()-1];
    if (str.size()==1){
        return strVal%hashSz;
    }
    int asc;
    for (int i=0; i<str.size()-1; i++){
        // Conversion from character to integer.
        asc = str[i+1] - 96;
        strVal = strVal * 32 + asc;
        strVal = strVal%hashSz;
    }
    return strVal;
}

// Second hash function for collisions - Used by insertion and find to determine
// the distance to move from the initial index in the event of a collision.
// (method used: double hashing)
int HashTable::h2(string str) const
{
    // Use Horner's method for hashing all the individual characters in the string
    // to avoid an overflow. This is done by using modulo between each calculations
    // of the characters. The calculation is: P2 - (string_value % P2). 
    // (P2 being halfPrime).
    int strVal = str[str.size()-1];
    if (str.size()==1){
        return halfPrime - (strVal%halfPrime);
    }
    int asc;
    for (int i=0; i<str.size()-1; i++){
        // Conversion from character to integer.
        asc = str[i+1] - 96;
        strVal = strVal * 32 + asc;
        strVal = strVal%halfPrime;
    }
    return halfPrime - strVal;
}