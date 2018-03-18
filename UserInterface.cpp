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

int8_t UserInterface::compression()
{
    uint8_t retCode;
    string filePath;
    //string archiveName;
    Huffman huffman;
    do {
        system("CLS");
        cout << "Program Archiwizujacy algorytmem Huffnama - Damian Kozakowski" << endl << endl;
        cout << "KOMPRESJA" << endl << endl;
        cout << "Podaj plik do kompresji: ";
        cin >> filePath;

        uint8_t error = 0;
        error = huffman.compress(filePath);
        //cout << "Kod zamkniecia funkcji compreess: " << +error << endl;
        //getch();
        if(error != 0) retCode = errorMsg(error);
        else {
            cout << "SKOMPRESOWANO" << endl;
            getch();
            retCode = BACK;
        }

    }while(retCode != END && retCode != BACK);

    return retCode;
}

char UserInterface::decompression()
{
    char retCode;
    string archivePath;
    //string archiveName;
    Huffman huffman;
    do {
        system("CLS");
        cout << "Program Archiwizujacy algorytmem Huffnama - Damian Kozakowski" << endl << endl;
        cout << "DEKOMPRESJA" << endl << endl;
        cout << "Podaj plik archiwum: ";
        cin >> archivePath;

        uint8_t error = 0;
        error = huffman.decompress();

        cout << "ZDEKOMPRESOWANO" << endl;
        retCode = getch();
    }while(retCode != END && retCode != BACK);

    return retCode;
}

uint8_t UserInterface::errorMsg(uint8_t errorCode)
{
    //char retCode;
    int8_t temp;
    system("CLS");
    //cout << "Przechwycony nr bledu: " << errorCode << endl;
    switch (errorCode) {
        case 240: {
            cout << "Error Code: " << +errorCode << endl;
            cout << "Plik nie istnieje lub nie masz praw do jego odczytu" << endl << endl;
            cout << "\t1.\tPonow probe" << endl;
            cout << "\t0.\tKONIEC" << endl;
            do {
                temp = getch();
            } while(temp != '1' && temp != '0');
            break;
        }
        case 241: {
            cout << "Error Code: " << +errorCode << endl;
            cout << "Archiwum nie istnieje lub nie masz do niego dostepu" << endl << endl;
            cout << "\t1.\tPonow probe" << endl;
            cout << "\t0.\tKONIEC" << endl;
            do {
                temp = getch();
            } while(temp != '1' && temp != '0');
            break;
        }
        default: {
            cout << "Error Code: " << +errorCode << endl;
            cout << "Nieznany blad!!! Nie wiem co zrobiles/as zdecyduj co robic." << endl << endl;
            cout << "\t1.\tPonow probe" << endl;
            cout << "\t0.\tKONIEC" << endl;
            do {
                temp = getch();
            } while(temp != '1' && temp != '0');
            break;
        }
    }
    return temp;
}
