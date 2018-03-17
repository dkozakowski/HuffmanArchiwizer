#include "UserInterface.h"


UserInterface::UserInterface()
{
    //ctor
}

UserInterface::~UserInterface()
{
    //dtor
}

char UserInterface::start()
{
    char choice = '0';
    do {
        system("CLS");
        cout << "Program Archiwizujacy algorytmem Huffnama - Damian Kozakowski" << endl << endl;
        cout << "\t1.\tKompresja" << endl;
        cout << "\t2.\tDekompresja" << endl;
        cout << endl << "\t0.\tKONIEC" << endl;

        choice = getch();
        switch(choice) {
            case '1': {
                choice = compression();
                break;
            }
            case '2': {
                choice = decompression();
                break;
            }
            case '0': {
                choice = END;
                break;
            }
            default: choice = BACK;
        }

    } while(choice != END);
    system("CLS");
    return RET_CODE;
}

char UserInterface::compression()
{
    char choice;
    string filePath;
    //string archiveName;
    Huffman huffman;
    do {
        system("CLS");
        cout << "Program Archiwizujacy algorytmem Huffnama - Damian Kozakowski" << endl << endl;
        cout << "KOMPRESJA" << endl << endl;
        cout << "Podaj plik do kompresji: ";
        cin >> filePath;
        //cout << "Podaj nazwe tworzonego pliku archiwum: ";
        //cin >> archiveName;


        cout << "SKOMPRESOWANO" << endl;
        choice = getch();
    }while(choice != END && choice != BACK);

    return choice;
}

char UserInterface::decompression()
{
    char choice;
    string archivePath;
    //string archiveName;
    Huffman huffman;
    do {
        system("CLS");
        cout << "Program Archiwizujacy algorytmem Huffnama - Damian Kozakowski" << endl << endl;
        cout << "DEKOMPRESJA" << endl << endl;
        cout << "Podaj plik archiwum: ";
        cin >> archivePath;

        cout << "ZDEKOMPRESOWANO" << endl;
        choice = getch();
    }while(choice != END && choice != BACK);

    return choice;
}
