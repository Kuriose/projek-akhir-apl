#include "types.h"
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
    cout << FG_MAGENTA << borderKiri << FG_KUNING << bagianTengah << FG_MAGENTA << borderKanan << RESET_WARNA << endl;
}

void printSeparator(string teks, int jumlahKarakter) {
    for (int i = 0; i <= jumlahKarakter; i++) {
        cout << FG_MAGENTA << teks;
    }
    cout << RESET_WARNA << endl;
}

int inputAngka(const string &prompt) {
    int nilai;
    while (true) {
        cout << FG_CYAN << prompt << RESET_WARNA;
        string input;
        cout << FG_KUNING; getline(cin, input); cout << RESET_WARNA;

        if (input.empty()) {
            cout << FG_MERAH << "[!] Input tidak boleh kosong!" << RESET_WARNA << endl;
            printSeparator("-", 49);
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
            cout << FG_MERAH << "[!] Input tidak valid, masukkan angka!" << RESET_WARNA << endl;
            printSeparator("-", 49);
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
        cout << FG_CYAN << prompt << RESET_WARNA;
        cout << FG_KUNING; getline(cin, input); cout << RESET_WARNA;

        if (input.empty()) {
            cout << FG_MERAH << "[!] Input tidak boleh kosong!" << RESET_WARNA << endl;
            printSeparator("-", 49);
            continue;
        }

        if (input.length() < minLength) {
            cout << FG_MERAH << "[!] Input minimal " << FG_KUNING << minLength << FG_MERAH << " karakter!" << RESET_WARNA << endl;
            continue;
        }

        break;
    }
    return input;
}

char inputKarakter(const string &prompt, const string &validKarakter) {
    while (true) {
        cout << FG_CYAN << prompt << RESET_WARNA;
        string input;
        cout << FG_KUNING; getline(cin, input); cout << RESET_WARNA;

        if (input.empty()) {
            cout << FG_MERAH << "[!] Input tidak boleh kosong!" << RESET_WARNA << endl;
            printSeparator("-", 49);
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
            cout << FG_MERAH << "[!] Input tidak valid, masukkan " << FG_KUNING << validKarakter << FG_MERAH << "!" << RESET_WARNA << endl;
            printSeparator("-", 49);
            continue;
        }

        return karakter;
    }
}

void getKategori(BendaLangit arr[], int &ukuran, string kunci, string kategori[], int &ukuranKategori) {
    string kategoriUnik[100];
    int jumlahKategori = 0;

    for(int i=0; i<ukuran; i++) {
        bool ditemukan = false;

        if (kunci == "KLASIFIKASI") {
            // Cek apakah kategori sudah tersimpan
            for(int j=0; j<jumlahKategori; j++) {
                if(arr[i].klasifikasi == kategoriUnik[j]) {
                    ditemukan = true;
                    break;
                }
            }

            // Jika belum ada
            if(!ditemukan) {
                kategoriUnik[jumlahKategori] =
                arr[i].klasifikasi;

                jumlahKategori++;
            }
        }
        else if (kunci == "KONSTELASI") {
            // Cek apakah kategori sudah tersimpan
            for(int j=0; j<jumlahKategori; j++) {
                if(arr[i].konstelasi == kategoriUnik[j]) {
                    ditemukan = true;
                    break;
                }
            }

            // Jika belum ada
            if(!ditemukan) {
                kategoriUnik[jumlahKategori] =
                arr[i].konstelasi;

                jumlahKategori++;
            }
        }
        else if (kunci == "STATUS OBSERVASI") {
            // Cek apakah kategori sudah tersimpan
            for(int j=0; j<jumlahKategori; j++) {
                if(arr[i].statusObservasi == kategoriUnik[j]) {
                    ditemukan = true;
                    break;
                }
            }

            // Jika belum ada
            if(!ditemukan) {
                kategoriUnik[jumlahKategori] =
                arr[i].statusObservasi;

                jumlahKategori++;
            }
        }
    }

    for (int i = 0; i < jumlahKategori; i++) {
        kategori[i] = kategoriUnik[i]; 
    }

    ukuranKategori = jumlahKategori;
}