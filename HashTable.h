#pragma once
#include <iostream>
#include <string>
using std::string;

class HashTable
{
public:

    // Default constructor
    HashTable();

    // Constructor
    HashTable(int n);

    // Copy constructor
    HashTable(const HashTable & ht);

    // Destructor
    ~HashTable();

    // Operator=
    HashTable & operator=(const HashTable & ht);

    // Insert
    void insert(string str);

    // Find
    bool find(string str) const;

    // Size
    int size();

    // MaxSize
    int maxSize();

    // LoadFactor
    double loadFactor();


private:

    // Underlying array of string objects
    string* strArr;

    // Size of the underlying array
    int hashSz;

    // Value used by h2
    int halfPrime;

    // Current number of items in the hash table
    int items;

    // Function that looks for the next prime number
    int findPrime(int n);

    // Function that checks if the parameter integer is a prime number
    bool isPrime(int n);

    // Function that inserts the parameter string into the parameter array
    // using hash functions
    void insertHelp(string* arr, string str);

    // First hash function
    int h1(string str) const;

    // Second hash function for double hashing
    int h2(string str) const;

};