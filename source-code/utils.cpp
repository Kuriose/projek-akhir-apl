#include "utils.h"

#include <iostream>
using namespace std;

void clearScreen() {
    system("clear"); 
    system("cls");
}

int errorHandling(int pilihan) {
    if (cin.fail()) {
        cin.clear();
        while (cin.peek() != '\n') {
            cin.ignore();
        }
        return pilihan = -1;
    } 
    else {
        cin.clear();
        while (cin.peek() != '\n') {
            cin.ignore();
        }
    }
    return pilihan;
}

void toUpperString(string &str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
}

void printHeader(string teks, int panjangTotal = 50) {
    toUpperString(teks);
    const string borderKiri = "==="; 
    string bagianTengah = " " + teks + " "; 

    int panjangSekarang = borderKiri.length() + bagianTengah.length(); 
    int panjangKiri = panjangTotal - panjangSekarang;

    if (panjangKiri < 0) {
        panjangKiri = 0;
    }

    string borderKanan(panjangKiri, '=');
    cout << borderKiri << bagianTengah << borderKanan << endl;
}

void printSeparator(string teks, int jumlahKarakter) {
    for (int i = 0; i <= jumlahKarakter; i++) {
        cout << teks;
    }
    cout << endl;
}