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
    vector<HuffNode*> nodeList;



    huffCode *huffCodeTab = new huffCode[nodeList.size()];
    HuffNode *huffRoot;

    fileToCompress.open(path, ios::in | ios::binary);
    if(!fileToCompress.good()) {
        return 240;
    }
    retCode = countWords(fileToCompress, counterOfOccurences);
    rewriteToListCounterOfOccurences(counterOfOccurences, nodeList);
    huffRoot = generateHuffTree(nodeList);
    huffCodeTab = generateHuffCodeTab(*huffRoot, nodeList.size());


    debug_printHuffCodeTab(huffCodeTab, nodeList.size());
    //debug_printOfOccurences(counterOfOccurences);
    return 0;
}

uint8_t Huffman::decompress(string patch)
{
    BitFileStream archive;
    string abc;
    archive << abc;
    std::cout << "Odczytalem: " << abc << std::endl;
    archive << abc;
    std::cout << "Odczytalem: " << abc << std::endl;
    archive << abc;
    std::cout << "Odczytalem: " << abc << std::endl;
    archive << abc;
    std::cout << "Odczytalem: " << abc << std::endl;
    archive << abc;
    std::cout << "Odczytalem: " << abc << std::endl;
    getch();


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

void Huffman::rewriteToListCounterOfOccurences(map<uint8_t, unsigned int>& counterOfOccurences, vector<HuffNode*>& nodeList) {
    for(map<uint8_t, unsigned int>::iterator it = counterOfOccurences.begin(); it!=counterOfOccurences.end(); ++it) {
        nodeList.push_back(new HuffNode(it->first, it->second));
    }
}

HuffNode* Huffman::generateHuffTree(vector<HuffNode*>& nodeList) {
    //szukaj mnajmniejszy - wyjnij
    //szukaj 2 najmniejszy - wyjmij
    //stwó¿ nowy node - dodaj
    HuffNode* min1;
    HuffNode* min2;
    HuffNode* newAddNode;

    while(nodeList.size() > 1) {
        //cout << "No i co" << endl;
        //nodeList.erase(nodeList.begin());
        min1 = findMinHuffNode(nodeList);
        min2 = findMinHuffNode(nodeList);
        nodeList.push_back(new HuffNode(0, min1->frequency + min2->frequency, min1, min2));
    }
}

HuffNode* Huffman::findMinHuffNode(vector<HuffNode*>& nodeList) {
    HuffNode* temp;
    uint8_t minIndex = 0;
    for(uint8_t i = 1; i < nodeList.size(); i++) {
        if(nodeList[minIndex] > nodeList[i]) minIndex = i;
    }
    temp = nodeList[minIndex];
    nodeList.erase(nodeList.begin()+minIndex);
    return temp;
}

Huffman::huffCode* Huffman::generateHuffCodeTab(HuffNode huffRoot, int listSize) {
    for(int i = 0 ; i <= listSize; i++) {

    }
}

Huffman::huffCode* Huffman::recursionHuffItem(HuffNode huffRoot) {
    huffCode *huffTemp;
    if(huffRoot.right1 != nullptr) {
        huffTemp = recursionHuffItem(*huffRoot.right1);
        if(huffTemp->child == false) {
            huffRoot.right1 = nullptr;
            huffTemp->code = '1'+huffTemp->code;
            huffTemp->child = true;
            return huffTemp;
        } else {
            //powrót z ga³êzi gdzie usuniety prawy ale zostal lewy

        }
    } else {
        huffTemp->symbol = huffRoot.symbol;
        huffTemp->code = "";
        return huffTemp;
    }
    if(huffRoot.left0 == nullptr);
}


void Huffman::debug_printHuffCodeTab(huffCode *huffCodeTab, int tabSize) {
    for(int i = 0 ; i < tabSize; i++) {
        cout << huffCodeTab[i].symbol << ":\t" << huffCodeTab[i].code << endl;
    }
}

void Huffman::debug_printOfOccurences(map<uint8_t,unsigned int>& counterOfOccurences)
{
    map<uint8_t,unsigned int>::iterator it;
    for(it = counterOfOccurences.begin();it!=counterOfOccurences.end();++it) {
        cout << +it->first << ": " << it->first << ": " << it->second << endl;
    }
    cout << "Pause" ;
    getch();
}
