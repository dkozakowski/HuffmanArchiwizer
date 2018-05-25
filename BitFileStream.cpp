#include "BitFileStream.h"

BitFileStream::BitFileStream()
{

    countBit = 0;
    byte = 0;
    //cout << "Inicjaliacja" << endl;
    *temp_byte = '0';
    //cout << "Po inicjalizacji" << endl;

}

BitFileStream::~BitFileStream()
{

}


void BitFileStream::close()
{
    if(countBit > 0) {
        cout << "Zapis niepelny: " << endl;
        debug_showByte(byte);
        fstream::put(byte);
    }
    fstream::close();
    byte = 0;
    countBit = 0;
}

void BitFileStream::saveBit(bool bit) {
    byte |= bit<<(7-countBit++);
    if(countBit > 7) {
        fstream::put((char)byte);
        byte = 0;
        countBit = 0;
    }
}

void BitFileStream::saveBit(string word) {
    for(int i = 0 ; i < word.length() ; i++) {
        if(word[i] == '0') saveBit(false);
        else saveBit(true);
    }
}

bool BitFileStream::readBit() {
    if(countBit == 0){
        fstream::get(*temp_byte);
        if(*temp_byte == EOF) return EOF;
        byte = *temp_byte;
        cout << endl << "Byte: " << +byte << endl;
        countBit = 8;
    }
    return byte&1<<(7-countBit--);
}

void BitFileStream::debug_showByte(uint8_t byte) {
    for(int i = 7 ; i >= 0 ; i--) {
        if(byte&(1<<i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
    return;
}
