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

void printHeader(string teks, int panjangTotal) {
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

int inputAngka(const string &prompt) {
    int nilai;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "=> Input tidak boleh kosong!" << endl;
            continue;
        }

        bool angka = true;
        for (int i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                angka = false;
                break;
            }
        }

        if (!angka) {
            cout << "=> Input tidak valid, masukkan angka!" << endl;
            continue;
        }

        nilai = stoi(input);
        break;
    }
    return nilai;
}

string inputString(const string &prompt, int minLength) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        if (input.empty()) {
            cout << "=> Input tidak boleh kosong!" << endl;
            continue;
        }

        if (input.length() < minLength) {
            cout << "=> Input minimal " << minLength << " karakter!" << endl;
            continue;
        }

        break;
    }
    return input;
}

char inputKarakter(const string &prompt, const string &validKarakter) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "=> Input tidak boleh kosong!" << endl;
            continue;
        }

        char karakter = toupper(input[0]);
        bool valid = false;
        for (int i = 0; i < validKarakter.length(); i++) {
            if (karakter == validKarakter[i]) {
                valid = true;
                break;
            }
        }

        if (!valid) {
            cout << "=> Input tidak valid, masukkan " << validKarakter << "!" << endl;
            continue;
        }

        return karakter;
    }
}