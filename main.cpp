#include <iostream>
#include <cstring>
#include <fstream>

#include "UserInterface.h"
#include "Huffman2.h"

using namespace std;

int main(int argc, char *argv[]) {

    BitFileStream plik;
    switch (argc) {
        case 1: {
            UserInterface interface;
            interface.start();
            break;
        }
        case 2: {
            char *p = strrchr(argv[1],'.dkh');
            if(p) {
                    cout << "Dobry format" << endl;
                Huffman2 huffman;
                huffman.decompress(argv[1]);
                break;
            }
            p = strrchr(argv[1],'.txt');
            if(p) {
                Huffman2 huffman;
                huffman.compress(argv[1]);
            } else {
                cout << "Zly format " << endl;
            }

            break;
        }
        default: {
            cout << "Program da sie uruchomic tylko z 1 parametrem (sciezka do pliku do kompresji lub do rozpakowywania) albo bez parametru." << endl;
            cout << "argc: " << argc << endl;

        }
    }
    return 0;
}
