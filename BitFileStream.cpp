#include "BitFileStream.h"

BitFileStream::BitFileStream()
{
    countBit = 0;
    byte = 0;
    //ctor
}

BitFileStream::~BitFileStream()
{
    //dtor
}


void BitFileStream::close()
{
    if(countBit > 0) {
        fstream::put(byte);
    }
    fstream::close();
    cout << "Zapisany bajt (zamkniecie): " << +byte << endl;
    byte = 0;
    countBit = 0;
}


void BitFileStream::saveBit(bool bit)
{
    cout << "saveBit countBit: " << +countBit << "\tbyte: " << +byte << endl;
    if(countBit > 7)
    {
        fstream::put((char)byte);
        //cout << "Bajt do zapisu (saveBit): " << +byte << endl;
        byte = 0;
        countBit = 0;
    }

    byte |= bit<<(countBit);
    cout << +countBit << endl;
    countBit++;
    //cout << "Aktualny bajt: " << +(uint8_t)byte << " counter: " << +countBit << endl;

    return;
}
