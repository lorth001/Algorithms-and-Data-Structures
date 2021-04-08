/*
* File: BDictionary.h -- implement a dictionary use an array-based bag
* CSIS 215-B01
*/

#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#pragma once

// My include statements
#include "dictionaryADT.h"
#include "kvpair.h"
#include "ABag.h"
#include <memory>

// Template class for implementing the dictionary functions
template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E>
{
public:

    // Constructor
    BDictionary(int dictSize) {}

    // Destructor
    ~BDictionary() {}

    // Refresh the dictionary
    void clear() {
        // Uses the ABag "emptyBag" function
        myDictionary.emptyBag();
    }

    // Insert a new record
    bool insert(const Key& k, const E& e) {

        // Initialize the return value to determine if operation is a success
        bool retVal;

        // Create a new key value pair
        KVpair<Key, E> newKV(k, e);

        // Add the new key value pair to the bag
        retVal = myDictionary += newKV;

        // Return
        return retVal;
    }

    // Remove record from dictionary with key
    bool remove(const Key& k, E& rtnVal) {

        // Initialize the return value to determine if operation is a success
        bool retVal = false;

        // Create a new key value pair
        KVpair<Key, E> newKV(k, rtnVal);

        // If the size is not empty
        if (size() > 0) {
            // Find the value and remove it from the dictionary
            retVal = myDictionary.remove(newKV);
            rtnVal = newKV.value();
        }

        // Return
        return retVal;
    }

    // Remove an arbitrary record from the dictionary
    bool removeAny(E& returnValue) {

        // Initialize the return value to determine if operation is a success
        bool retVal = false;

        // Create a new key value pair
        KVpair<Key, E> newKV;

        // Remove this value from the dictionary
        retVal = myDictionary.removeTop(newKV);
        returnValue = newKV.value();

        // Return
        return retVal;
    }

    // Find record using a key
    bool find(const Key& k, E& returnValue) const {

        // Initialize the return value to determine if operation is a success
        bool retVal = true;

        // Create a new key value pair
        KVpair<Key, E> newKV(k, returnValue);

        // Try to find the value with the key
        retVal = myDictionary.find(newKV);
        returnValue = newKV.value();

        // Return
        return retVal;
    }

    // Get the number of records in the dictionary
    int size() {
        // Use the ABag "size" function to get size of dictionary
        return myDictionary.size();
    }

private:
    ABag<KVpair<Key, E>> myDictionary; // Using smart pointers to create the dictionary
};

#endif /* BDICTIONARY_H */