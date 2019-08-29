
/*=====================================Operating System=======================================*/

#include <PageReplacementAlgorithm.hpp>

using namespace std;

PageReplacementAlgorithm::PageReplacementAlgorithm(){
   frameNum = 0;
   options = true;	// Set to true to use FIFO method, set to false to use LRU method
}

int PageReplacementAlgorithm::findVictim(){
  frameNum++;
  return (frameNum-1)%128;
}

int PageReplacementAlgorithm::getPRA(){
	if(options){
		return 1;
	} else {
		return 2;
	}
}