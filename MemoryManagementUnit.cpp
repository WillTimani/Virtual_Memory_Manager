
/*==========================HARDWARE================================*/

#include <MemoryManagementUnit.hpp>

MemoryManagementUnit::MemoryManagementUnit(){
	Ram r();
	ProcessControlBlock p();
	LRU_Replacement lru();

	tlb_.reserve(TLB_SIZE);

	page_access_count = 0;
	page_in_faults = 0;
	tlb_access_count_ = 0;
	tlb_faults_ = 0;
}

unsigned char MemoryManagementUnit::read(Address addr){
	/*=================Check TLB===================*/
	bool tlbMiss = true;
	
	for(unsigned int i = 0; i < tlb_.size(); i++){
		if(addr.page() == tlb_[i].PageNum){
			
			tlb_access_count_++;
			
			//cin << outFile << hex << static_cast<int32_t>(r.ramV[tlb_[i].pTE.frame_number][addr.displacement()]) << endl;

			r.statusArr[tlb_[i].pTE.frame_number].dirty = true;

			// Update lru algorithim if it is being used
			if(lru.getPRA() == 2){
				lru.updateUsage(tlb_[i].pTE.frame_number);
			}

			//Update TLB
			tlbEntry temp = tlb_[i];
			tlb_.erase(tlb_.begin() + i);
			tlb_.push_back(temp);
			tlbMiss = false;
			
			return r.ramV[tlb_[i].pTE.frame_number][addr.displacement()];

		}
	} 
	/*==================Check Page Table===================*/
	if(tlbMiss){
		tlb_faults_++;
		if(p.myPageTable[addr.page()].valid){ // page in memory
			page_access_count++;
			
			//cin << outFile << hex << static_cast<int32_t>(r.ramV[addr.frame(p.myPageTable)][addr.displacement()]) << endl;
			
			r.statusArr[addr.frame(p.myPageTable)].dirty = true;

			// Update lru algorithim if it is being used
			if(lru.getPRA() == 2){
				lru.updateUsage(addr.frame(p.myPageTable));
			}

			//Update TLB
			tlbEntry temp;
			temp.pTE = p.myPageTable[addr.page()];
			temp.PageNum = addr.page();

			if(tlb_.size() >= 16){
				tlb_.erase(tlb_.begin());
			}

			tlb_.push_back(temp);

			return r.ramV[addr.frame(p.myPageTable)][addr.displacement()];

	/*===================Generate Page Fault==========================*/	
		} else { 
			page_in_faults++;
			throw pageFault(addr.page());
		}
	}
	return 0;
}

void MemoryManagementUnit::clearTLB(){
	tlb_.erase(tlb_.begin(),tlb_.end());
}

int MemoryManagementUnit::pageAccesses(){
	return page_access_count;
}

int MemoryManagementUnit::pageFaults(){
	return page_in_faults;
}

int MemoryManagementUnit::tlbAccesses(){
	return tlb_access_count_;
}

int MemoryManagementUnit::tlbFaults(){
	return tlb_faults_;
}
