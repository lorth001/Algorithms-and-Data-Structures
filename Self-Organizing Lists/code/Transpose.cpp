/*
* File name: Driver.cpp -- This file is used to test the SelfOrderedListADT and the linked-list implementations.
                           It does this by both prompting the user for input and reading from a "test.txt" file, then orders these inputs.
* CSIS 215-B01
* References: The contained in the link.h and SelfOrderedListADT.h files were provided by Liberty University for use in this assignment.
              The TransposeList.h, Transpose.cpp, MovetoFrontList.h, CountList.h, and Driver.cpp files were developed by me.
              I did reference Clifford A. Shaffer's textbook "A Practical Introduction to Data Structures and Algorithm Analysis, Third Edition (C++)" during the development of this program.
*/

#pragma once

// Include statements
#include <iostream>
#include "link.h"
#include "SelfOrderedListADT.h"

// Self-ordering linked list - this is done using the number of times each node has been accessed
template <typename E>
class CountList : public SelfOrderedListADT<E> {
private:
    Link<E>* head;       // List header
    Link<E>* tail;       // Last element
    Link<E>* curr;       // Current element
    int compares;        // Number of compares
    int numElements;     // Number of elements
public:

    // Constructor with initializations
    CountList() {
        curr = tail = head = new Link<E>;
        numElements = 0;
        compares = 0;
    }

    // Destructor
    ~CountList() {}

    // Function to find the character being searched.  If it's found, run the appropriate self-order heuristic
    bool find(const E& it) {

        curr = head; // Set current element to head of list
        bool flag = false; // Flag indicating if value was found

        // Iterate through the list and search for value
        while (curr->element != it && curr->next != NULL) {
            curr = curr->next;
            compares++;
        }

        // If the value can't be found, add it to the end of the list
        if (curr == tail && curr->element != it) {
            add(it);
            compares++;
        }
        
        else {
            curr->freq += 1;
            flag = true;
            compares++;
        }

        // Reorder list based on new element
        reorder();

        // Return
        return flag;
    }

    // Add value to the list
    void add(const E& it) {
        // Create head node if the list is empty
        if (numElements == 0) {
            head = new Link<E>(it, NULL);
            tail = head;
            // Icrease size of the list
            numElements++;
        }
        // If the list is not empty, add value to end of the list
        else {
            tail = tail->next = new Link<E>(it, NULL);
            curr = tail;
            // Increases list size
            numElements++;
        }
    }

    // Get the total number of compares performed
    int getCompares() const {
        return compares;
    }

    // Get the size of the list
    int size() const {
        return numElements;
    }

    // Print the whole list
    void printlist() {
        curr = head; // Set current element to head of list

        // Loop through and print list
        for (int i = 0; i < size(); i++) {
            std::cout << curr->element << "-" << curr->freq << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    // Print nodes
    void printlist(int n) {
        curr = head; // Set current element to head of list

        // Loop through and print list
        for (int i = 0; i < n; i++) {
            std::cout << curr->element << "-" << curr->freq << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    // Reorder the list by using the most frequently used values
    void reorder() {

        Link<E>* prev = new Link<E>; // Previous node
        Link<E>* temp = new Link<E>; // Temporary variable

        // Set current element to head of list if only one element has been added
        if (numElements == 1) {
            curr = head;
        }

        // Find previous element (if it exists)
        while (curr != head) {
            // Get previous node
            prev = head;
            while (prev->next != curr) prev = prev->next;

            // Switch the elements
            if (curr->freq > prev->freq) {
                temp->element = curr->element;
                temp->freq = curr->freq;
                curr->element = prev->element;
                curr->freq = prev->freq;
                prev->element = temp->element;
                prev->freq = temp->freq;
            }
            curr = prev;
        }
    }

    // Move link nodes to free store
    void removeall() {
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
};