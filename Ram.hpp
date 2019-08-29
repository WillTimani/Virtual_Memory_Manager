
/*==========================HARDWARE================================*/

#pragma once
#include <Configuration.hpp>
#include <vector>
#include <iostream>

using namespace std;

struct Status {
	Status(){
		dirty = false;
	}
	bool dirty;
};

class Ram {

	public:
		void read(unsigned char* frame);
		static vector<unsigned char*> ramV;
		static Status statusArr[RAM_SIZE];

		Ram();
};