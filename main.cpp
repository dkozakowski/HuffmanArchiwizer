#include <iostream>
#include <cstring>

#include "UserInterface.h"

using namespace std;

int main(int argc, char *argv[]) {

    BitFileStream plik;

    plik.open("test.txt", fstream::out);
    plik.saveBit(true);
    plik.saveBit(true);
    plik.saveBit(true);
    plik.saveBit(false); //7

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false); // 10100111 a7
    plik.saveBit(true);  //a
    cout << "Pierwszy bajt" << endl;

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(true); //a

    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(false);
    plik.saveBit(false);//0
    cout << "Drugi bajt" << endl;

    plik.saveBit(true);
    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(true);//b

    plik.saveBit(false);
    plik.saveBit(true);
    plik.saveBit(false);
    plik.saveBit(false);//2
    plik.close();


/*
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

    */

    return 0;
}
