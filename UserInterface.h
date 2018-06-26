#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Huffman.h"
#include "Huffman2.h"

#include <conio.h>
#include <iostream>

#define END 48
#define BACK 57
//#define START 1

using namespace std;

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();

        char start();

    protected:
    private:
        uint8_t compression();
        uint8_t decompression();
        uint8_t errorMsg(uint8_t errorCode);
};

#endif // USERINTERFACE_H
