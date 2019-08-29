
/*=====================================Operating System=======================================*/

/* Class implementation file for Memory Manager (Operating System) */

#include "MemoryManager.hpp"

MemoryManager::MemoryManager() {
	Ram r();
	BackingStore b();
	ProcessControlBlock p();
	PageReplacementAlgorithm pra();
	LRU_Replacement lru();

	for(int i = 0; i < RAM_SIZE; i++){
		free_frames[i] = true;
	}
}

void MemoryManager::pageIn(uint32_t pNum){
   
	/*===================Check if ram is full========================*/

	bool noFreeFrames = true;

	for(int i = 0; i < RAM_SIZE; i++){
		if(free_frames[i]){
			unsigned char * arr = new unsigned char;

			b.read(pNum, arr); 			// read in frame to arr from backing store
 
			r.read(arr);				// read in frame into ram from arr

			p.myPageTable[pNum].valid = true;						// set page to valid in page table
			p.myPageTable[pNum].frame_number = r.ramV.size() - 1;	// set frame number to index in Ram array

			free_frames[i] = false;
			noFreeFrames = false;
			break;
		}
	}
   
	/*======================If ram is full use PRA=====================*/
	if(noFreeFrames){

		// Find victim based on options of the page replacement algorithim
		int temp;
		if(pra.getPRA() == 1){
			temp = pra.findVictim();
		} else {
			temp =lru.findVictim();
		}

		// Find frame in page table in order to update it 
		for(int i = 0; i < PAGE_SIZE; i++){
			if(p.myPageTable[i].frame_number == temp){
				//Update page table for page being replaced
				p.myPageTable[i].valid = false;

				break;
			}
		}

		// Read replace frame at frame number with new frame
		unsigned char * arr = new unsigned char;
		b.read(pNum, arr); 							// read in frame to arr

		//cout << dec << "Replacing ram position: " << temp << " with new page: " << pNum << endl; 

		//Update page table for replaced page
		p.myPageTable[pNum].valid = true;				
		p.myPageTable[pNum].frame_number = temp;

		if(r.statusArr[p.myPageTable[pNum].frame_number].dirty){
			//write out previous frame to backing store
		}

		// Replace the frame at victim frame number
		r.ramV[temp] = arr;


	}
}


