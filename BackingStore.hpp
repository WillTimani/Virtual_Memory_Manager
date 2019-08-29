
/*==========================HARDWARE================================*/

/* Class header file: Backing Store (Hardware) */

#pragma once
#include "Configuration.hpp"
#include <iostream>
#include <fstream> // To use std::ifstream

using namespace std;

class BackingStore {
public:
    /* Instantiates BackingStore */
    BackingStore* instance();

    /* Reads from page number to find frame number */
    void read(int page_number, unsigned char* arr);

    /* Opens backing store */
    BackingStore();

    /* Destroys backing store */
    ~BackingStore();

private:
    /* Declares BackingStore object and binary file variables, global to all instances */
    static BackingStore* b_store;
    static ifstream bin_file;
};