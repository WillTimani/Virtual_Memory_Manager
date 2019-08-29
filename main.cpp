#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <MemoryManager.hpp>
#include <MemoryManagementUnit.hpp>

using namespace std;

int main(){

	MemoryManagementUnit mmu;
	MemoryManager mm;

	ifstream inpFile;
	inpFile.open("addresses.txt");

	ofstream outFile;
	outFile.open("output.txt");

	if(inpFile.is_open()){

		string line;

		while(!inpFile.eof()){

			inpFile >> line;

			if(!inpFile.eof()){

				Address currentAddr(line);
				try{
					outFile << hex << static_cast<int32_t>(mmu.read(currentAddr)) << endl;

				} catch(pageFault& pF){

					mm.pageIn(pF.pageNumber_);

					outFile << hex << static_cast<int32_t>(mmu.read(currentAddr)) << endl;

				}

			}
		}
	}
	inpFile.close();

	outFile << dec << "Page Accesses: " << mmu.pageAccesses() << endl;
	outFile << dec <<"Page Faults: " << mmu.pageFaults() << endl;

	double pfr = mmu.pageFaults();
	pfr/=(mmu.pageAccesses() + mmu.pageFaults());

	outFile << fixed << "Page Fault Rate: " << pfr << endl;

	outFile << dec << "TLB Hits: " << mmu.tlbAccesses() << endl;
	outFile << dec <<"TLB Misses: " << mmu.tlbFaults() << endl;

	double tmr = mmu.tlbFaults();
	tmr/=(mmu.tlbAccesses() + mmu.tlbFaults());

	outFile << fixed << "TLB Miss Rate: " << tmr << endl;

	outFile.close();

	cout << "Corresponding bytes have been output to the file: output.txt" << endl;

	return 0;
}

