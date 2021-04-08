/*
* File name: test.cpp -- This file is used to test the traversal of a given Double-Threaded Binary Tree using the provided (and augmented) ADTs
* CSIS 215-B01
* References: Most of the code for this program remains in its original state, as provided by Liberty University for use in this assignment.  Only this test.cpp file and certain parts of the BST.h and BSTNode.h files have been created by me.
*/

#include <iostream>
#include <string>
#include "BST.h"


int main() {

    // General message with student info and meaning of the program's output
    cout << "Luke Orth -- CSIS 215 Programming Assignment 2 -- Double-Threaded Binary Tree" << endl << endl;
    std::cout << "Testing the insert function to build my tree." << endl;

    // New tree creation
    BST<int, string>* tree = new BST<int, string>;

    // Inserting elements as instructed to build the tree
    tree->insert(77, "seventy-seven");
    tree->insert(70, "seventy");
    tree->insert(75, "seventy-five");
    tree->insert(66, "sixty-six");
    tree->insert(79, "seventy-nine");
    tree->insert(68, "sixty-eight");
    tree->insert(67, "sixty-seven");
    tree->insert(69, "sixty-nine");
    tree->insert(90, "ninety");
    tree->insert(85, "eighty-five");
    tree->insert(83, "eighty-three");
    tree->insert(87, "eighty-seven");
    tree->insert(65, "sixty-five");

    // Message to show tree size
    std::cout << "My BST tree size is " << tree->size() << " nodes." << endl << endl;

    // Graphical visualization of the tree - tests the print and printHelp functions
    std::cout << "My tree's structure is" << endl;
    std::cout << "(tests my changes to the print function):" << endl;
    tree->print();
    cout << endl;

    // Print the tree in order - tests the printInOrder and printInOrderHelp functions
    std::cout << "Inorder printing of my tree" << endl;
    std::cout << "(tests my right threads and printInorder function):" << endl;
    tree->printInOrder();
    cout << endl;

    // Print the tree in reverse order - tests the printReverse and printReverseHelp functions
    std::cout << "Reverse order printing of my tree" << endl;
    std::cout << "(tests my left threads and printReverse function):" << endl;
    tree->printReverse();
    cout << endl;

    system("pause");
    return 0;
}