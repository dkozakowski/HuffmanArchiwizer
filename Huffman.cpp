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
    uint8_t retCode;

    fstream fileToCompress;
    map<uint8_t,unsigned int> counterOfOccurences;
    vector<HuffNode*> nodeList;

    huffCode *huffCodeTab = new huffCode[counterOfOccurences.size()];
    HuffNode *huffRoot;

    fileToCompress.open(path, ios::in | ios::binary);
    if(!fileToCompress.good()) {
        return 240;
    }

    generateHuffTree(nodeList, huffRoot);
    generateHuffCodeTab(huffRoot, counterOfOccurences.size(), huffCodeTab);
    //cout << "GenerateHuffCodeTab" << endl;


    debug_printHuffCodeTab(huffCodeTab, counterOfOccurences.size());
    //cout << "Debug print " << endl;
    //debug_printOfOccurences(counterOfOccurences);
    fileToCompress.seekg(0);

    //writeDictionary()


    fileToCompress.close();


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

/*void Huffman::countWords(fstream& fileToCount, map<uint8_t,unsigned int>& counterOfOccurences)
{
    uint8_t simpleWord;
    while(!fileToCount.eof()) {
        fileToCount >> simpleWord;
        if(counterOfOccurences.find(simpleWord)==counterOfOccurences.end()) counterOfOccurences.insert(pair<uint8_t,unsigned int>(simpleWord,1));
        else counterOfOccurences.find(simpleWord)->second++;
    }
    return;
}*/

/*
void Huffman::rewriteToListCounterOfOccurences(map<uint8_t, unsigned int>& counterOfOccurences, vector<HuffNode*>& nodeList) {
    for(map<uint8_t, unsigned int>::iterator it = counterOfOccurences.begin(); it!=counterOfOccurences.end(); ++it) {
        nodeList.push_back(new HuffNode(it->first, it->second));
    }
}
*/

void Huffman::generateHuffTree(vector<HuffNode*>& nodeList, HuffNode* huffNode) {
    //szukaj mnajmniejszy - wyjnij
    //szukaj 2 najmniejszy - wyjmij
    //stwó¿ nowy node - dodaj
    HuffNode* min1;
    HuffNode* min2;
    //HuffNode* newAddNode;

    while(nodeList.size() > 1) {
        cout << "No i co" << endl;
        //nodeList.erase(nodeList.begin());
        min1 = findMinHuffNode(nodeList);
        min2 = findMinHuffNode(nodeList);
        nodeList.push_back(new HuffNode(0, min1->frequency + min2->frequency, min1, min2));
    }
    huffNode = nodeList[0];
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

void Huffman::generateHuffCodeTab(HuffNode* huffRoot, int listSize, huffCode* huffCodeTab) {

    huffCode *huffTmpCodeTab;// = new huffCode[listSize];
    huffCode *tmp;
    for(int i = 0 ; i <= listSize; i++) {
        cout << "Petla: " << i << " generateHuffCodeTab" << endl;
        recursionHuffItem(huffRoot, tmp);
        huffTmpCodeTab[i] = *tmp;
    }
    cout << "Po petli" << endl;
}

void Huffman::recursionHuffItem(HuffNode* huffRoot, huffCode* tmp) {

    huffCode *huffTemp = new huffCode;

    if(huffRoot->right1 == nullptr) {
            cout << "recursionHuffItem R" << endl;
        // lewe dziecko
        recursionHuffItem(huffRoot->left0, huffTemp);
        huffTemp->code = '0'+huffTemp->code;
        if(huffRoot->left0->child == false) {
            // lewe dziecko nie ma dzieci
            huffRoot->left0 = nullptr;
            huffRoot->child = false;
            tmp = huffTemp;
        } else {
            // lewe dziecko ma dzieci
            huffTemp->child = true;
            tmp = huffTemp;
        }
    } else {
        cout << "recursionHuffItem L" << endl;
        // prawe dziecko
        recursionHuffItem(huffRoot->right1, huffTemp);
        huffTemp->code = '1'+huffTemp->code;
        if(huffRoot->right1->child == false) {
            //prawe dziecko nie ma dzici
            huffRoot->right1 = nullptr;
            huffRoot->child = true;
            tmp = huffTemp;
        } else {
            //lewe dzienko nie ma dzieci
            huffTemp->child = true;
            tmp = huffTemp;
        }
    }
    tmp = huffTemp;
}

void Huffman::debug_printHuffCodeTab(huffCode *huffCodeTab, int tabSize) {
    cout << "F debug print" << endl;
    for(int i = 0 ; i < tabSize; i++) {
        cout << huffCodeTab[i].symbol << ":\t" << huffCodeTab[i].code << endl;
    }
}

/*
void Huffman::debug_printOfOccurences(map<uint8_t,unsigned int>& counterOfOccurences)
{
    map<uint8_t,unsigned int>::iterator it;
    for(it = counterOfOccurences.begin();it!=counterOfOccurences.end();++it) {
        cout << +it->first << ": " << it->first << ": " << it->second << endl;
    }
    cout << "Pause" ;
    getch();
}
*/
