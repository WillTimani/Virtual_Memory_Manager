
/*==========================HARDWARE================================*/

/* Class implementation file: Backing Store (Hardware) */

#include "BackingStore.hpp"

using namespace std;

BackingStore* BackingStore::b_store;
ifstream BackingStore::bin_file;

BackingStore* BackingStore::instance(){
    if (b_store == nullptr){
        b_store = new BackingStore();
    }
    return b_store;
    cout << "Backing store created" << endl;
}

void BackingStore::read(int page_number, unsigned char * arr){
 
    bin_file.seekg(page_number * FRAME_SIZE, ios::beg); //Finds frame number by multiplying page number (unsigned hex) and page size (256)
    bin_file.read(reinterpret_cast<char*>(arr), FRAME_SIZE); // Saves frame number to page entry
    
}

BackingStore::~BackingStore(){
    bin_file.close();
    delete b_store;     //Prevents memory leak
    b_store = nullptr;  //Prevents dangling pointer
    cout << "Backing store destroyed" << endl;
}

BackingStore::BackingStore(){
    bin_file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        bin_file.open("BACKING_STORE.bin", ios::binary); // Read existing binary file
        cout << "Sucessfully opened file" << endl;
    } catch (ifstream::failure error){
        cerr << "Error opening BACKING_STORE.bin" << error.what() << endl;
    }
}