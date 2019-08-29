
/*==========================HARDWARE================================*/

#pragma once 

#include <Configuration.hpp>
#include <ProcessControlBlock.hpp>
#include <Word.hpp>
#include <Ram.hpp>
#include <LRU_Replacement.hpp>

struct tlbEntry{
	pageTableEntry pTE;
	uint32_t PageNum;
};

struct pageFault : runtime_error{
	pageFault(uint32_t pn) : runtime_error("Page Fault"){
		pageNumber_ = pn;
	}
	uint32_t pageNumber_;
};

class MemoryManagementUnit {
	public:
		void clearTLB();
		MemoryManagementUnit();
		int pageAccesses();
		int pageFaults();
		unsigned char read(Address addr);
		int tlbAccesses();
		int tlbFaults();

	private:
		Ram r;
		ProcessControlBlock p;
		vector<tlbEntry> tlb_;
		LRU_Replacement lru;

		int page_access_count;
		int page_in_faults;
		int tlb_access_count_;
		int tlb_faults_;
};