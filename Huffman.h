#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <BitFileStream.h>
#include <HuffNode.h>

#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <map>
#include <vector>

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

        struct huffCode {
            char symbol;
            string code;
            bool child;
        };


        void countWords(fstream&, map<uint8_t,unsigned int>&);
        void rewriteToListCounterOfOccurences(map<uint8_t,unsigned int>&, vector<HuffNode*>&);
        void generateHuffTree(vector<HuffNode*>&, HuffNode*);

        HuffNode* findMinHuffNode(vector<HuffNode*>&);
        void generateHuffCodeTab(HuffNode*, int, huffCode*);
        void recursionHuffItem(HuffNode*, huffCode*);

        void debug_printHuffCodeTab(huffCode*, int);
        void debug_printOfOccurences(map<uint8_t,unsigned int>&);
        void debug_printNodeList();
};

#endif // HUFFMAN_H
