
/*=====================================Operating System=======================================*/

/* Class header file for Memory Manager (Operating System) */

#pragma once

#include "BackingStore.hpp"
#include "ProcessControlBlock.hpp"
#include "Ram.hpp"
#include "PageReplacementAlgorithm.hpp"
#include "LRU_Replacement.hpp"

class MemoryManager {
public:
    MemoryManager(); 
    void pageIn(uint32_t pNum); 

private:
    bool free_frames[RAM_SIZE];
 
    Ram r;
    BackingStore b;
    ProcessControlBlock p;
    PageReplacementAlgorithm pra;
    LRU_Replacement lru;

};