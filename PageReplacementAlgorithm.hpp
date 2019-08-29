
/*=====================================Operating System=======================================*/

#pragma once

#include <Configuration.hpp>

class PageReplacementAlgorithm {
public:
  	PageReplacementAlgorithm();
  	int findVictim();
  	int getPRA();

private:
	int frameNum;
  	bool options;

};