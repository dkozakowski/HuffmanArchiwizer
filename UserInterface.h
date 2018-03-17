#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Huffman.h"

#include <conio.h>
#include <iostream>

#define RET_CODE 0
#define END 48
#define BACK 57

using namespace std;

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();

        char start();

    protected:
    private:
        char compression();
        char decompression();
};

#endif // USERINTERFACE_H
