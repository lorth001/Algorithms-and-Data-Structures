/*
* File name: BufferBlock.h -- This file is used to create a class for blocks used in the LRUBufferPool.  It does this by inheriting from BufferBlockADT
* CSIS 215-B01
* References: Most of the code for this program remains in its original state, as provided by Liberty University for use in this assignment.  Only this BufferBlock.h file and the LRUBufferPool.h file have been created by me.
*/

// Include statements
#include <iostream>
#include "BufferBlockADT.h"
#include "constants.h"

// Class for Buffer Pool blocks - made with the inherited BufferBlock ADT
class BufferBlock : public BufferblockADT {
private:
    int blockID; // block ID
    char* block; // single buffer pool block
public:
    // Constructor
    BufferBlock() {}
    BufferBlock(char* data, int sz = 4096) {

        // Create block of specified size
        block = getCharArray(sz);

        // Insert data into the block
        for (int i = 0; i < sz; i++) {
            block[i] = data[i];
        }
    }

    // Destructor
    ~BufferBlock() {}

    // Parse block from "pos" to "pos + sz-1" (end of the block)
    void getData(int pos, int sz, char* data) {

        // Find the position of the data in the block
        pos = pos % BLOCKSIZE;

        // Create a new block with the same data
        char* curBlock = getBlock();

        // Loop to get the first sz characters from the block
        for (int i = 0; i < sz; i++) {
            data[i] = curBlock[pos + i];
        }
    }

    // Get ID of the block
    int getID() const {
        return blockID;
    }

    // Get the block's size
    int getBlocksize() const {
        return BLOCKSIZE;
    }

    // Return the block
    char* getBlock() const {
        return block;
    }

    // Set the ID of the block
    void setID(int id) {
        blockID = id;
    }

    // Set the block
    void setBlock(char* blk) {
        block = blk;
    }
};