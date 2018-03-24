#include <iostream>
#include <cstring>

#include "UserInterface.h"

using namespace std;

int main(int argc, char *argv[]) {
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
    getch();
    return 0;
}
