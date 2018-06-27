#include "Huffman2.h"

// compress
uint8_t Huffman2::compress(string path)
{
    fileToCompress.open(path, ios::in | ios::binary);
    if(!fileToCompress.good()) {
        return 240;
    }
    countWord(fileToCompress, counterOfOccurences);
    rewriteToListCounterOfOccurences(counterOfOccurences, nodeList);
    generateHuffTree(nodeList);
    treeRoot = nodeList[0];
    generateHuffCodeTab(*treeRoot, counterOfOccurences.size(), codeList);
    sortHuffCodeTab(codeList);
    debug_printHuffCodeTab(codeList,counterOfOccurences.size());

    fileToCompress.close();
    fileToCompress.open(path, ios::in | ios::binary);

    size_t found = path.find_last_of(".");
    archivePath = path.substr(0,found);
    archivePath.append(".dkh");
    fileCompress.open(archivePath, ios::out | ios::binary);

    char magicByte = 0;
    magicByte=(((((magicByte+1)<<2)+1)<<4)+3)<<1;
    fileCompress << magicByte;
    writeDictionaryToFile(codeList,  fileCompress);
    codeFile(codeList, fileToCompress, fileCompress);
    fileCompress.close();
    fileToCompress.close();

    return 0;
}

void Huffman2::countWord(fstream& fileToCount, map<uint8_t, unsigned int>& counterOfOccurences) {
    uint8_t simpleWord;
    char simpleWord1[2];
    while(!fileToCount.eof()) {
        fileToCount.read(simpleWord1,1);
        simpleWord = simpleWord1[0];
        if(counterOfOccurences.find(simpleWord)==counterOfOccurences.end()) counterOfOccurences.insert(pair<uint8_t,unsigned int>(simpleWord,1));
        else counterOfOccurences.find(simpleWord)->second++;
    }
}

void Huffman2::rewriteToListCounterOfOccurences(map<uint8_t, unsigned int> counterOfOccurences, vector<HuffNode*>& nodeList) {
    for(map<uint8_t, unsigned int>::iterator it = counterOfOccurences.begin(); it!=counterOfOccurences.end(); ++it) {
        nodeList.push_back(new HuffNode(it->first, it->second));
    }
}

void Huffman2::generateHuffTree(vector<HuffNode*>& nodeList) {
    HuffNode* min1;
    HuffNode* min2;

    while(nodeList.size() > 1) {
        min1 = findMinHuffNode(nodeList);
        min2 = findMinHuffNode(nodeList);
        nodeList.push_back(new HuffNode(0, min1->frequency + min2->frequency, min1, min2));
    }
}

HuffNode* Huffman2::findMinHuffNode(vector<HuffNode*>& nodeList) {
    HuffNode* temp;
    uint8_t minIndex = 0;
    for(uint8_t i = 1; i < nodeList.size(); i++) {
        if(nodeList[minIndex]->frequency > nodeList[i]->frequency) minIndex = i;
    }
    temp = nodeList[minIndex];
    nodeList.erase(nodeList.begin()+minIndex);
    return temp;
}

void Huffman2::generateHuffCodeTab(HuffNode huffRoot, unsigned int listSize, vector<huffCode>& codeList) {
    huffCode *tmp;
    for(unsigned int i = 0 ; i < listSize; i++) {
        recursionHuffItem2(&huffRoot, tmp);
        codeList.push_back(codeTMP);
    }
}

void Huffman2::recursionHuffItem2(HuffNode* huffRoot, huffCode* tmp) {

    huffCode *huffTemp = new huffCode;

    if(huffRoot->right1 == nullptr) {
        // czy istnieje lewe
        if(huffRoot->left0 == nullptr) {
            codeTMP.symbol = huffRoot->symbol;
            codeTMP.code = "";
            huffRoot->child = false;
            return;
        }
        // lewe dziecko
        recursionHuffItem2(huffRoot->left0, huffTemp);
        codeTMP.code = '0'+codeTMP.code;

        if(huffRoot->left0->child == false) {
            // lewe dziecko nie ma dzieci
            huffRoot->left0 = nullptr;
            huffRoot->child = false;
            return;
        } else {
            // lewe dziecko ma dzieci
            tmp = huffTemp;
            return;
        }
    } else {
        // prawe dziecko
        recursionHuffItem2(huffRoot->right1, huffTemp);
        codeTMP.code = '1'+codeTMP.code;

        if(huffRoot->right1->child == false) {
            //prawe dziecko nie ma dzici
            huffRoot->right1 = nullptr;
            huffRoot->child = true;
            tmp = huffTemp;
            return;
        } else {
            //lewe dzienko nie ma dzieci
            huffTemp->child = true;
            tmp = huffTemp;
            return;
        }
    }
    return;

}

void Huffman2::recursionHuffItem(HuffNode* huffRoot, huffCode* tmp) {

    huffCode *huffTemp = new huffCode;

    if(huffRoot->right1 == nullptr) {
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

void Huffman2::sortHuffCodeTab(vector<huffCode>& codeList) {
    vector<huffCode> sortedCodeList;
    uint8_t imin;
    while(codeList.size() != 0) {
        imin = 0;
        for(unsigned int i = 1; i < codeList.size(); i++) {
            if((codeList.at(imin)).code.length() > (codeList.at(i)).code.length()) {
                imin = i;
            }
        }
        sortedCodeList.push_back((codeList.at(imin)));
        codeList.erase((codeList.begin()+imin));
    }
    codeList = sortedCodeList;
}

/*void Huffman2::writeDictionaryToFile2(vector<huffCode> codeList, BitFileStream& fileCompress) {
    //cout << "Ilosc kodowanych znakow: " << codeList.size() << endl;
    unsigned char lengthOfCurrentCode;
    bitset<8> temp;
    string codesSameLength = "";
    unsigned int amountSameLength = 0;
    string currentCodes = "";
    cout << "Ilosc wszystkich kodow: " << codeList.size() << endl;
    fileCompress << (unsigned char)codeList.size();


    while(codeList.size() != 0) {
            cout << "Obrót petli" << endl;
        lengthOfCurrentCode = codeList.front().code.length();
        temp = lengthOfCurrentCode;
        //cout << "Aktualny rozmiar kodu: " << +lengthOfCurrentCode << endl;
        currentCodes += temp.to_string();
        amountSameLength = 0;
        //while(codeList.size() != 0 || codeList.front().code.length() == lengthOfCurrentCode) {
        while(codeList.front().code.length() == lengthOfCurrentCode) {
            amountSameLength++;
            codesSameLength+=codeList.front().code;
            temp = codeList.front().symbol;
            codesSameLength+=temp.to_string();
            codeList.erase(codeList.begin());
            if(codeList.size() == 0 ) break;
        }
        //cout << "D³ugoœc kolejki tego typu: " << amountSameLength << endl;
        temp = amountSameLength;
        currentCodes+=temp.to_string();
        //cout << "CurrentCodes: " << currentCodes << endl;
        fileCompress.saveBit(currentCodes);
        fileCompress.saveBit(codesSameLength);
        currentCodes = "";
    }
    fileCompress.forceSave();
}*/

void Huffman2::writeDictionaryToFile(vector<huffCode> codeList, BitFileStream& fileCompress) {
    bitset<8> temp;
    unsigned int oneTypeCodesCounter = 0;
    string oneTypeCodes = "";
    unsigned int currentOneTypeWidth = 0;
    fileCompress << (unsigned char)codeList.size();

    while(codeList.size() != 0) {
        // policzyæ ile jest kodów 1 typu
        currentOneTypeWidth = codeList.front().code.length();
        oneTypeCodesCounter = 1;
        oneTypeCodes = "";
        temp = currentOneTypeWidth;
        cout << "currentOneTypeWidth: " << temp.to_string() << endl;
        fileCompress.saveBit(temp.to_string());
        for(int i = 1; i < codeList.size(); i++) {
            if(codeList.at(i).code.length() == currentOneTypeWidth) {
                oneTypeCodesCounter++;
            }
        }
        temp = oneTypeCodesCounter;
        cout << oneTypeCodesCounter << ": " << temp.to_string() << " tyle jest wystapien tego typu" << endl;

        for(int i = 0 ; i < oneTypeCodesCounter; i++) {
            oneTypeCodes+=codeList.front().code;
            temp = codeList.front().symbol;
            oneTypeCodes+=temp.to_string();
            codeList.erase(codeList.begin());
        }
        temp = oneTypeCodesCounter;
        cout << "OneTypeCodesCounter: " << oneTypeCodesCounter << endl;
        cout << "oneTypeCodes: " << oneTypeCodes << endl;
        fileCompress.saveBit(temp.to_string());
        fileCompress.saveBit(oneTypeCodes);
        // spisaæ kody i znaki 1 typu

        // dopisaæ najpierw ilosc kodów 1 typu a potem kody ze znakami
    }

}


void Huffman2::codeFile(vector<huffCode> codeList, fstream& fileToCompress, BitFileStream& fileCompress) {
    char temp[2];
    temp[0] = NULL;
    char i;
    cout << "Dlugosc codeList: " << codeList.size() << endl;
    getch();
    while(!fileToCompress.eof() ) {
        fileToCompress.read(temp,1);
        for(i = 0; i < codeList.size(); i++) {
            if(codeList.at(i).symbol == temp[0]) {
               fileCompress.saveBit(codeList.at(i).code);
            }
        }
    }
    fileCompress.forceSave();
}

// compress - debug
void Huffman2::debug_printOfOccurences(map<uint8_t,unsigned int> counterOfOccurences) {
    map<uint8_t,unsigned int>::iterator it;
    for(it = counterOfOccurences.begin();it!=counterOfOccurences.end();++it) {
        cout << +it->first << ": " << it->first << ": " << it->second << endl;
    }
    cout << "Pause" ;
    getch();
}

void Huffman2::debug_printNodeList(vector<HuffNode*> nodeList, unsigned int tabSize) {
    for(unsigned int i = 0 ; i < tabSize; i++) {
        cout << nodeList[i]->symbol << " : " << nodeList[i]->frequency << endl;
    }
}

void Huffman2::debug_printHuffCodeTab(vector<huffCode> huffCodeTab, unsigned int tabSize) {
    for(unsigned int i = 0 ; i < tabSize; i++) {
        cout << +huffCodeTab[i].symbol << ":\t" << huffCodeTab[i].symbol << ":\t" << huffCodeTab[i].code << endl;
    }
}


// decompress
uint8_t Huffman2::decompress(string path)
{
    BitFileStream archive;
    BitFileStream resultFile;
    char temp[1];
    //char magicByte = 0;
    unsigned char globalAmountOfChar = 0;
    unsigned char countedAmountOfChar = 0;
    unsigned char currentCodeSize = 0;
    unsigned char currentCodeAmount = 0;
    unsigned char currentCodeCounter = 0;
    huffCode tmp;
    bitset<8> temp1;
    string code = "";
    string temporary;
    char symbol;
    bool bit = false;
    string magicbyte = "10100110";
    //string

    archive.open(path, ios::in | ios::binary);
    if(!archive.good()) {
        return 241;
    }
    cout << "Otworzono poprawnie" << endl;

    temporary = archive.readAsynchronizedByteToString();
    getch();
    if(temporary != magicbyte) {
        archive.close();
        return 242;
    }
    temporary = archive.readAsynchronizedByteToString();
    globalAmountOfChar = archive.stringToChar(temporary);
    //cout << "GlobalAmountOfChar: " << temporary << " => " << +globalAmountOfChar << endl;
    while(countedAmountOfChar < globalAmountOfChar) {
        //cout << +countedAmountOfChar << " x:x " << +globalAmountOfChar << endl;
        currentCodeSize = temp[0];
        currentCodeSize = archive.stringToChar(archive.readAsynchronizedByteToString());

        //cout << "currentCodeSize: " << +currentCodeSize << endl; //temp1.to_string() << endl;
        //getch();
        currentCodeAmount = archive.stringToChar(archive.readAsynchronizedByteToString());
        //cout << "currentCodeAmount: " << +currentCodeAmount << endl;// temp1.to_string() << endl;

        for(int i = currentCodeAmount; i > 0; i--) {
                //cout << "Wejscie do petli danego rodzaju " << +currentCodeAmount << endl;
            for(int j = currentCodeSize; j > 0; j--) {
                bit = archive.readBit();
                if(bit) code+="1";
                else code +="0";
            }
            symbol = archive.stringToChar(archive.readAsynchronizedByteToString());

            tmp.code = code;
            code = "";
            tmp.symbol = symbol;
            symbol = 0;
            codeList.push_back(tmp);
        }
        countedAmountOfChar+=currentCodeAmount;
    }
    //getch();
    debug_printHuffCodeTab(codeList,codeList.size());

    resultFile.open("outputFile",ios::out | ios::binary);
    //dekompresowanie
    temporary = "";
    while(!archive.eof()) {
            //cout << "Obrot" << endl;
        bit = archive.readBit();
        if(bit) temporary += '1';
        else temporary +='0';
        //cout << "Temporary: " << temporary << endl;
        for(int i = 0; i < codeList.size(); i++) {
            //cout << "i: " << i << endl;
            if(codeList.at(i).code == temporary) {
                //cout << "Symbol: " << codeList.at(i).symbol;
                resultFile << codeList.at(i).symbol;
                temporary = "";
                break;
            }
        }

    }


    archive.close();
    return 0;
}

Huffman2::Huffman2()
{
    //ctor
}

Huffman2::~Huffman2()
{
    //dtor
}
