#include "Huffman.h"

Huffman::Huffman()
{
    //ctor
}

Huffman::~Huffman()
{
    //dtor
}

uint8_t Huffman::compress(string path)
{
    fstream fileToCompress;

    fileToCompress.open(path, ios::in | ios::binary);
    if(!fileToCompress.good()) {
        return 240;
    }
    return 0;
}
