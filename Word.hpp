/*====================================HARDWARE=================================*/

#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Word {
	Word(string s){
		value_ = stoi(s);
		cout << "Virtual Address: " << value_ << endl;
	}
	uint32_t value_;
};

struct Address : Word {
	Address(string s) : Word(s){}

	uint32_t displacement() {
		// offset which is the leftmost 8 bits
		return value_ & 255;
	}
	uint32_t frame(pageTableEntry pT[]) {
		return pT[this->page()].frame_number;
	}
	uint32_t page() {
		// page number which is the 8 bits to the right of the offset
		return (value_ >> 8) & 255;
	}

};