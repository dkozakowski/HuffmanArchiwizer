#ifndef BITFILESTREAM_H
#define BITFILESTREAM_H

#include <fstream>
#include <iostream>

using namespace std;

class BitFileStream : public fstream
{
    public:
        BitFileStream();
        ~BitFileStream();
        void close(); //trzeba zabezpieczyæ przypadek gdy niepelny bit bedzie w buforze "bits" i powinien zostaæ zapisany do pliku przed zamknieciem
        void saveBit(bool);
        void saveBit(string);
        bool readBit();
        void debug_showByte(uint8_t);

    protected:
        uint8_t byte;
        uint8_t countBit;
        char t = 0;
        char *temp_byte = &t;

    private:
};

#endif // BITFILESTREAM_H
