/*
* File name: LRUBufferPool.h -- This file creates a Least Recently Used (LRU) Buffer Pool by inheriting from BufferPoolADT
* CSIS 215-B01
* References: Most of the code for this program remains in its original state, as provided by Liberty University for use in this assignment.  Only this LRUBufferPool.h file and the BufferBlock.h file have been created by me.
*/

// Include statements
#include <fstream>
#include <iostream>
#include <array>
#include <string>
#include "BufferPoolADT.h"
#include "BufferBlock.h"

// Class for Least Recently Used (LRU) Buffer Pool - made with the inherited Buffer Pool ADT
class LRUBufferPool : public BufferPoolADT {
private:
	std::array<BufferBlock*, 5> blockArray; // Array to store each of the five blocks
	BufferBlock* block; // Block to be inserted into the buffer pool
	char* data = new char[4096]; // Char to hold data from file
	fstream input; // Input file
	string inputFile; // Name of the input file
public:
	// Constructor
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) {

		// Open the binary file
		inputFile = filename;
		input.open(filename.c_str(), fstream::in | fstream::binary);

		// Iterates through the size of the pool and adds more blocks accordingly
		for (int i = 0; i < poolSize; i++) {

			// Find and read the data for chosen block
			int temp = i * 4096;
			input.seekg(temp);
			input.read(data, blockSize);

			// Create a new block, add data to it, and give it a new ID
			block = new BufferBlock(data, blockSize);
			blockArray[i] = block;
			block->setID(i);
		}

		// Close file
		input.close();
	}

	// Destructor
	~LRUBufferPool() {}

	// From position "pos" in the buffered storage, copy "sz" bytes to "space"
	void getBytes(char* space, int sz, int pos) {

		bool inPool = false; // If the block is already in the pool, then this will be true
		int ID = pos / BLOCKSIZE; // Block ID

		// Confirm if the block is already in the pool
		for (int i = 0; i < POOL_SIZE; i++) {
			if (blockArray[i]->getID() == ID) {
				inPool = true;
			}
		}

		// If the block is already in the pool...
		if (inPool) {
			int i = 0; // Set counter at 0

			// Loop through the pool until the block ID is found
			while (blockArray[i]->getID() != ID)
				i++;

			// Create a temporary block by copying the data from the block being accessed 
			BufferBlock* temp = blockArray[i];

			// Shift blocks down in the pool
			while (i > 0) {
				blockArray[i] = blockArray[i - 1];
				i--;
			}

			// Puts the temporary block at the top
			blockArray[0] = temp;
		}
		// If the block is not already in the pool...
		else {

			// Shift all blocks down in the pool
			int i = 4;
			while (i > 0) {
				blockArray[i] = blockArray[i - 1];
				i--;
			}

			// Reopen the file
			fstream input;
			input.open(inputFile.c_str(), fstream::in | fstream::binary);

			// Create a new block and put it at the top of the pool
			int temp = ID * 4096;
			input.seekg(temp);
			input.read(data, 4096);
			block = new BufferBlock(data, 4096);
			blockArray[0] = block;
			block->setID(ID);
		}

		// Get the data from the top block
		blockArray[0]->getData(pos, sz, space);
	}

	// Print the blocks in order using their block IDs
	void printBufferBlockOrder() {

		// Output message
		std::cout << "My buffer block order from most recently used to LRU is:" << std::endl << "	";

		// Loop through all the blocks in the pool
		for (int i = 0; i < 5; i++) {
			std::cout << blockArray[i]->getID() << ", ";
		}

		std::cout << std::endl << std::endl;
	}

	// Get the least recently used (LRU) buffer block ID
	int getLRUBlockID() {
		return blockArray[0]->getID();
	}
};