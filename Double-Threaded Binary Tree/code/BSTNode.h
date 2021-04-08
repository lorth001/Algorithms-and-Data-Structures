// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include for access to the complete binary node
// template implementation

#include "book.h"
#include "BinNode.h"

#ifndef BSTNODE_H
#define BSTNODE_H

// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E> {
private:
    Key k;                      // The node's key
    E it;                       // The node's value
    unsigned int leftBit : 1;   // Indicator to determine if left pointer is a thread or branch
    unsigned int rightBit : 1;  // Indicator to determine if right pointer is a thread or branch
    BSTNode* lc;                // Pointer to left child
    BSTNode* rc;                // Pointer to right child

public:
    // Two constructors -- with and without initial values
    BSTNode() { lc = rc = NULL; }
    BSTNode(Key K, E e, BSTNode* l = NULL, BSTNode* r = NULL)
    {
        k = K; it = e; lc = l; rc = r;
    }
    ~BSTNode() {}             // Destructor

    // Functions to set and return the value and key
    E& element() { return it; }
    void setElement(const E& e) { it = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    // Functions to set and return the children
    inline BSTNode* left() const { return lc; }

    // Setter method for left child
    void setLeft(BinNode<E>* b)
    {
        lc = (BSTNode*)b;
        // Set left bit to 1
        leftBit = 1;
    }

    inline BSTNode* right() const { return rc; }

    // Setter method right child
    void setRight(BinNode<E>* b)
    {
        rc = (BSTNode*)b;
        // Set right bit to 1
        rightBit = 1;
    }

    // Functions to set and return the children
    void setLeftBit(bool flag) { leftBit = flag; }
    void setRightBit(bool flag) { rightBit = flag; }
    bool getLeftBit() { return leftBit; }
    bool getRightBit() { return rightBit; }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};

#endif