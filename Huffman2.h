#ifndef HUFFMAN2_H
#define HUFFMAN2_H

#define END 48
#define BACK 57

#include <BitFileStream.h>
#include <HuffNode.h>

#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <map>
#include <vector>
#include <String>
#include <bitset>

using namespace std;

class Huffman2
{
    public:
        Huffman2();
        ~Huffman2();

        uint8_t compress(string);
        uint8_t decompress(string);

    protected:
    private:
        struct huffCode {
            char symbol;
            string code;
            bool child;
        };
        fstream fileToCompress;
        BitFileStream fileCompress;
        string archivePath;
        map<uint8_t,unsigned int> counterOfOccurences;
        vector<HuffNode*> nodeList;
        vector<huffCode> codeList;

        HuffNode *treeRoot;
        huffCode codeTMP;

        void countWord(fstream&, map<uint8_t, unsigned int>&);
        void rewriteToListCounterOfOccurences(map<uint8_t, unsigned int>, vector<HuffNode*>&);
        void generateHuffTree(vector<HuffNode*>&);
        HuffNode* findMinHuffNode(vector<HuffNode*>&);
        //void generateHuffCodeTab(vector<HuffNode>, vector<codeList>&);
        void generateHuffCodeTab(HuffNode, unsigned int, vector<huffCode>&);
        void recursionHuffItem(HuffNode*, huffCode*);
        void recursionHuffItem2(HuffNode*, huffCode*);
        //void recursionHuffItem2(HuffNode, unsigned int, vector<huffCode>&);
        void sortHuffCodeTab(vector<huffCode>&);
        void writeDictionaryToFile(vector<huffCode>,BitFileStream&);
        void writeDictionaryToFile2(vector<huffCode>,BitFileStream&);
        void codeFile(vector<huffCode>, fstream&, BitFileStream&);


        void debug_printHuffCodeTab(vector<huffCode>, unsigned int);
        void debug_printOfOccurences(map<uint8_t,unsigned int>);
        void debug_printNodeList(vector<HuffNode*>, unsigned int);
};

#endif // HUFFMAN2_H
