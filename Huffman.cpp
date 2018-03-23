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
    uint8_t retCode;
    map<uint8_t,unsigned int> counterOfOccurences;
    fileToCompress.open(path, ios::in | ios::binary);
    if(!fileToCompress.good()) {
        return 240;
    }
    retCode = countWords(fileToCompress, counterOfOccurences);
    debug_printOfOccurences(counterOfOccurences);
    return 0;
}

uint8_t Huffman::decompress(string patch)
{

    return 241;
}

uint8_t Huffman::countWords(fstream& fileToCount, map<uint8_t,unsigned int>& counterOfOccurences)
{
    uint8_t simpleWord;
    while(!fileToCount.eof()) {
        fileToCount >> simpleWord;
        if(counterOfOccurences.find(simpleWord)==counterOfOccurences.end()) counterOfOccurences.insert(pair<uint8_t,unsigned int>(simpleWord,1));
        else counterOfOccurences.find(simpleWord)->second++;
    }
    return 0;
}

void Huffman::debug_printOfOccurences(map<uint8_t,unsigned int>& counterOfOccurences)
{
    map<uint8_t,unsigned int>::iterator it;
    for(it = counterOfOccurences.begin();it!=counterOfOccurences.end();++it) {
        cout << +it->first << ": " << it->first << ": " << it->second << endl;
    }

}
