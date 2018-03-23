#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <map>

using namespace std;


class Huffman
{
    public:
        Huffman();
        virtual ~Huffman();

        uint8_t compress(string);
        uint8_t decompress(string path);

    protected:
    private:
        uint8_t countWords(fstream&, map<uint8_t,unsigned int>&);

        void debug_printOfOccurences(map<uint8_t,unsigned int>&);
};

#endif // HUFFMAN_H
