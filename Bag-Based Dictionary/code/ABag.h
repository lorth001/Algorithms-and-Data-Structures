/*
* File: ABag.h - Used to implement the bag-array used in this assignment
* CSIS 215-B01
*/

#pragma once

// My include statements
#include "bagADT.h"
#include <memory>

// Template class for implementing the bag functions
template <typename E>
class ABag : public Bag <E>
{
public:

    // Constructor
    ABag() {}

    // Destructor
    ~ABag() {}

    // Function for inserting a new item into the bag
    bool addItem(const E& item) {
        // Initialize return value for indicating if the operation was a success
        bool retVal = true;

        // If the bag's size equals it's capacity, then the bag is full
        if (bagCapacity() == size()) {
            retVal = false;
        }

        // If the size does not equal the capacity, add item and increment the count
        else {
            int tSize = size();
            bag[tSize] = item;
            count++;
        }

        // Return
        return retVal;
    }

    // Function for overloading
    bool operator+=(const E& addend) {
        // Initialize return value for indicating if the operation was a success
        bool retVal;

        // Add the item to the bag
        retVal = addItem(addend);

        // Return
        return retVal;
    }

    // Function to remove an item from the bag (if item is found)
    bool remove(E& item) {
        // Initialize return value for indicating if the operation was a success
        bool retVal = true;

        // If the size is 0, then the bag is empty
        if (size() == 0) {
            retVal = false;
        }

        // If the item is found in the bag, the return value will return true.  If not, then false
        retVal = find(item);

        // If the item is found...
        if (retVal == true) {

            // Find the position of the top item
            int top = size() - 1;

            // Find the item to be removed
            while (!(bag[top] == item))
                top--;

            // Any items found above the item to be removed, shift down by one
            for (int j = top; j < size(); j++) {
                bag[j] = bag[j + 1];
            }

            // Decrement the size
            count--;
        }
        // Return
        return retVal;
    }

    // Function to remove the top item from the bag
    bool removeTop(E& returnValue) {
        // Initialize return value for indicating if the operation was a success
        bool retVal = true;

        // If the bag is empty, return false
        if (size() == 0) {
            retVal = false;
        }

        // Otherwise, remove item on top and decrement the count
        else {
            inspectTop(returnValue);
            count--;
        }
        // Return
        return retVal;
    }

    // Function to find an item in the bag
    bool find(E& returnValue) const {
        // Initialize variable to hold index
        int index = 0;

        // Initialize return value for indicating if the operation was a success
        bool retVal = false;

        // Loop through the bag while return value is false
        while (!retVal) {
            // If item is found, set return value to true
            if (bag[index] == returnValue) {
                returnValue = bag[index];
                retVal = true;
            }
            index++;
        }

        // Return
        return retVal;
    }

    // Function to find the top item in the bag
    bool inspectTop(E& item) const {
        // Initialize return value for indicating if the operation was a success
        bool retVal = true;

        // If the bag is empty, set return value to false
        if (size() == 0) {
            retVal = false;
        }
        // Otherwise, get the top item
        else {
            item = bag[size() - 1];
        }

        // Return
        return retVal;
    }

    // Function to completely empty the bag
    void emptyBag() {
        // Loop throug the bag and remove all items found
        for (int i = size() - 1; i > 0; i--) {
            remove(bag[i]);
        }

        // Reset count to 0
        count = 0;
    }

    // Function to determine the zie of the bag
    int size() const {
        // Return the number of items in the bag
        return count;
    }

    // Function to determine the capacity of the bag
    int bagCapacity() const {
        // Return the max number of items the bag can hold
        return 10;
    }

private:
    int count = 0; // Keeps track of the total number of items in the bag
    E bag[10]; // Bag created with size 10
};