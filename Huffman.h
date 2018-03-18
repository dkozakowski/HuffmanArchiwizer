#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;


class Huffman
{
    public:
        Huffman();
        virtual ~Huffman();

        uint8_t compress(string path);
        char decompress(string path);

    protected:
    private:
};

#endif // HUFFMAN_H
