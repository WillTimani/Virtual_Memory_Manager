
/*=====================================Operating System=======================================*/

#pragma once

#include <Configuration.hpp>

struct pageTableEntry{
	int frame_number;
	bool valid;
};

struct ProcessControlBlock {
	ProcessControlBlock(){
		for(int i = 0; i < PAGE_SIZE; i++){
			myPageTable[i].valid = false;
		}
	}
	static pageTableEntry myPageTable[PAGE_SIZE];
};

