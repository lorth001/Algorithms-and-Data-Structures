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

// Self-ordering linked list - this is done by switching the currently accessed element with the previous one
template <typename E>
class MovetoFrontList : public SelfOrderedListADT<E> {
private:
    Link<E>* head;       // List header
    Link<E>* tail;       // Last element
    Link<E>* curr;       // Current element
    int compares;        // Number of compares
    int numElements;     // Number of elements
public:

    // Constructor with initializations
    MovetoFrontList() {
        curr = tail = head = new Link<E>;
        numElements = 0;
        compares = 0;
    }

    // Destructer
    ~MovetoFrontList() {}

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
            if (size() != 0) {
                compares++;
            }
            add(it);
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
            curr = head;
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

    // Move the accessed node to the front of the list
    void reorder() {

        if (curr != head) {
            Link<E>* prev = head;
            while (prev->next != curr) prev = prev->next;
            Link<E>* newHead = new Link<E>;
            newHead->element = curr->element;
            newHead->freq = curr->freq;
            newHead->next = head;
            head = newHead;
            Link<E>* temp = prev->next;     // Link node
            if (tail == prev->next) tail = prev; // Reset the tail
            prev->next = prev->next->next;   // Remove value from the list
            delete temp;                    // Delete the space
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