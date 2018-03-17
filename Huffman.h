#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>

using namespace std;


class Huffman
{
    public:
        Huffman();
        virtual ~Huffman();

        char compress(string path, string archiveName);
        char decompress(string path);

    protected:
    private:
};

#endif // HUFFMAN_H
