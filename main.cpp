#include <iostream>
#include <cstring>
#include <fstream>

#include "UserInterface.h"

using namespace std;

int main(int argc, char *argv[]) {

    BitFileStream plik;
    /*cout << "Uruchamiam" << endl;
    plik.open("Dorota.txt", fstream::in);
    while(!plik.eof()){
        if(plik.readBit()) cout << '1';
            else cout << '0';

    }*/

    /*plik.open("test.txt", fstream::out);
    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(true);

    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false);
    //cout << "Pierwszy bajt za nami" << endl;

    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(true);

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(false);
    //cout << "Drugi bajtv za nami" << endl;

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(true);

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(true);
    plik.saveBit(false);
    //cout << "Trzeci bajt za nami" << endl;

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(true);
    plik.saveBit(true);

    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(false);
    //cout << "Czwarty bajt za nami" << endl;

    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(true);

    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false);
    //cout << "Pi¹ty bajt za nami" << endl;

    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(true);

    plik.saveBit(true);
    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(false);
    //cout << "Szusty bajt za nami" << endl;

    //plik.saveBit(true);
    //plik.saveBit(true);
    //plik.saveBit(false);
    //plik.saveBit(true);

    //plik.saveBit(false);
    //plik.saveBit(true);

    plik.close();
*/

///*
    switch (argc) {
        case 1: {
            UserInterface interface;
            interface.start();
            break;
        }
        case 2: {
            char *p = strrchr(argv[1],'.txt');
            if(p) {
                Huffman huffman;
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
    //getch();

    //*/

    return 0;
}
