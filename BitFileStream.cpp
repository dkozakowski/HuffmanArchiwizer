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

void BitFileStream::forceSave() {
    if(countBit > 0) {
        //cout << "Force save!!! " << 8-countBit << "bits. " << endl;
        fstream::put(byte);
    }
}

void BitFileStream::forceFlush() {
    //cout << "Force flush!!!" << countBit << "bits flushed." << endl;
    countBit = 0;
}

void BitFileStream::close()
{
    if(countBit > 0) {
        //cout << "Zapis niepelny: " << endl;
        //debug_showByte(byte);
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
        //cout << endl << "Byte: " << +byte << endl;
        //debug_showByte(byte);
        countBit = 8;
    }
    return byte&(1<<((countBit--)-1));
}
/*bool BitFileStream::readBit() {
    if(countBit >= 8){
        fstream::get(*temp_byte);
        if(*temp_byte == EOF) return EOF;
        byte = *temp_byte;
        cout << endl << "Byte: " << +byte << endl;
        //debug_showByte(byte);
        countBit = 0;
    }
    return byte&(1<<(countBit++));
}*/

uint8_t BitFileStream::stringToChar(string byte) {
    uint8_t temp = 0;
    char podstawa = 2;
    //cout << "byte lenght: " << byte.length() << endl;
    for(int i = byte.length()-1 ; i >= 0 ; i--) {
            //cout << "Zmiana na pozycji: " << i << endl;
        if(byte.at(i) == '1') temp+=pow(podstawa,7-i);
    }
    return temp;
}

string BitFileStream::readAsynchronizedByteToString() {
    string temp = "";
    bool x = false;
    for(int i = 0 ; i < 8 ; i++) {
        x = readBit();
        if(x) temp+='1';
        else temp+='0';
    }
    //cout << "Wewnatrz fukncji: " << temp << endl;
    return temp;
}


char BitFileStream::readAsynchronizedByteToChar() {
    char temp = 0;
    bool x = false;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    x = readBit();
    if(x) temp++;
    temp = temp<<1;
    //cout << "asynchronized Byte: ";
    //debug_showByte(temp);
    return temp;
}

void BitFileStream::debug_showByte(uint8_t byte) {
    for(int i = 7 ; i >= 0 ; i--) {
        if(byte&(1<<i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
    return;
}
