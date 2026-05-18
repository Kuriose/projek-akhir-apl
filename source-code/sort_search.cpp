#include "types.h"
#include "sort_search.h"
#include "utils.h"

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void urutkanBerdasarkanJarak(BendaLangit arr[], int ukuran) {    
    if (ukuran == 0) {
        cout << "=> Data kosong, tidak ada yang bisa diurutkan" << endl; 
        system("pause"); 
        return; 
    }
    
    string inputUser;
    char urutan;
    bool valid = false;

    do {
        clearScreen();
        printHeader("URUTKAN BERDASARKAN JARAK", 50);
        cout << "Pilih urutan pengurutan:" << endl;
        cout << "A. Ascending" << endl;
        cout << "D. Descending" << endl;

        printSeparator("-", 49);
        cout << "Masukkan pilihan (A/D): ";
        cin >> inputUser;
        
        if (inputUser.length() == 1) {
            urutan = toupper(inputUser[0]); 
            if (urutan == 'A' || urutan == 'D') {
                valid = true; 
            } else {
                cout << "=> Input tidak valid (A/D)" << endl; 
                system("pause");
            }
        } else {
            cout << "=> Input tidak valid (A/D)" << endl; 
            system("pause");
        }
        cin.clear();
        cin.ignore(1000, '\n');
    } while (!valid); 

    
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if (urutan == 'A') {
                if ((arr+j)->jarakDariBumi > (arr+j+1)->jarakDariBumi) {
                    perluTukar = true;
                }
            }
            else if (urutan == 'D') {
                if ((arr+j)->jarakDariBumi < (arr+j+1)->jarakDariBumi) {
                    perluTukar = true;
                }
            }
            
            if (perluTukar) {
                BendaLangit temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
    
    printSeparator("-", 49);
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void urutkanBerdasarkanNama(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << "=> Data kosong, tidak ada yang bisa diurutkan!" << endl;
        system("pause");
        return;
    }

    clearScreen();
    printHeader("URUTKAN BERDASARKAN NAMA", 50);
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (A-Z)" << endl;
    cout << "D. Descending (Z-A)" << endl;
    printSeparator("-", 49);

    cin.ignore();
    char urutan = inputKarakter("Masukkan pilihan (A/D): ", "AD");

    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if (urutan == 'A') {
                if ((arr+j)->namaObjek > (arr+j+1)->namaObjek) perluTukar = true;
            }
            else if (urutan == 'D') {
                if ((arr+j)->namaObjek < (arr+j+1)->namaObjek) perluTukar = true;
            }

            if (perluTukar) {
                BendaLangit temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }

    printSeparator("-", 49);
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void urutkanNama(BendaLangit arr[], int ukuran) {
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if ((arr+j)->namaObjek > (arr+j+1)->namaObjek) {
                perluTukar = true;
            }
            
            if (perluTukar) {
                BendaLangit temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}

void urutkanBerdasarkanTahun(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << "=> Data kosong, tidak ada yang bisa diurutkan" << endl;
        system("pause");
        return;
    }

    string inputUser;
    char urutan;
    bool valid = false;
    do {
        clearScreen();
        printHeader("URUTKAN BERDASARKAN TAHUN", 50);
        cout << "Pilih urutan pengurutan:" << endl;
        cout << "A. Ascending" << endl;
        cout << "D. Descending" << endl;
        
        printSeparator("-", 49);
        cout << "Masukkan pilihan (A/D): ";
        cin >> inputUser;

        if (inputUser.length() == 1) {
            urutan = toupper(inputUser[0]);
            if (urutan == 'A' || urutan == 'D') {
                valid = true;
            } else {
                cout << "=> Input tidak valid (A/D)" << endl;
                system("pause");
            }
        } else {
            cout << "=> Input tidak valid (A/D)" << endl;
            system("pause");
        }
        cin.clear();
        cin.ignore(1000, '\n');
    } while (!valid);

        for (int i = 0; i < ukuran - 1; i++) {
            for (int j = 0; j < ukuran - i - 1; j++) {
                bool perluTukar = false;
                if (urutan == 'A') {
                    if ((arr + j)->tahunPenemuan > (arr + j + 1)->tahunPenemuan) perluTukar = true;
                } else if (urutan == 'D') {
                    if ((arr + j)->tahunPenemuan < (arr + j + 1)->tahunPenemuan) perluTukar = true;
                }

                if (perluTukar) {
                    BendaLangit temp = *(arr + j);
                    *(arr + j) = *(arr + j + 1);
                    *(arr + j + 1) = temp;
                }
            }
        }
    printSeparator("-", 49);
    cout << "=> Data berhasil diurutkan berdasarkan tahun (" << (urutan == 'A' ? "Ascending" : "Descending") << ")" << endl;
    system("pause");
}

void urutkanBerdasarkanMagnitudo(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << "=> Data kosong, tidak ada yang bisa diurutkan!" << endl;
        system("pause");
        return;
    }

    clearScreen();
    printHeader("URUTKAN BERDASARKAN MAGNITUDO", 50);
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (Terkecil -> Terbesar)" << endl;
    cout << "D. Descending (Terbesar -> Terkecil)" << endl;
    printSeparator("-", 49);

    cin.ignore();
    char urutan = inputKarakter("Masukkan pilihan (A/D): ", "AD");

    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if (urutan == 'A') {
                if ((arr+j)->magnitudo > (arr+j+1)->magnitudo) perluTukar = true;
            }
            else if (urutan == 'D') {
                if ((arr+j)->magnitudo < (arr+j+1)->magnitudo) perluTukar = true;
            }

            if (perluTukar) {
                BendaLangit temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }

    printSeparator("-", 49);
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void cariKonstelasi(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << "=> Data Entri kosong" << endl;
        system("pause");
        return;
    }

    string cariK;
    string cariKupper;
    cin.ignore(1000, '\n');

    clearScreen();
    printHeader("CARI BERDASARKAN KONSTELASI", 50);
    cout << "Masukkan Nama Konstelasi: " << endl;
    cout << "> "; 
    getline(cin, cariK);

    if (cariK.empty()) {
        cout << "=> Input tidak boleh kosong!" << endl;
        system("pause");
        return;
    }

    toUpperString(cariK);
    bool spasi = true;
    for (int i = 0; i < cariK.length(); i++) {
        char c = cariK[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            cout << "=> Input nama konstelasi tidak valid!" << endl;
            system("pause");
            return;
        }
        if (c != ' ') spasi = false;
    }

    if (spasi) {
        cout << "=> Input tidak boleh kosong!" << endl;
        system("pause");
        return;
    }

    cariKupper = cariK;
    toUpperString(cariKupper);
    bool ditemukan = false;
    for (int i = 0; i < ukuran; i++) {
        string konSistem = (arr + i)->konstelasi;
        toUpperString(konSistem);
        if (konSistem == cariKupper) {
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "=> Belum ada objek astronomi pada konstelasi " << cariK << endl;
        system("pause");
        return;
    }

    clearScreen();
    int jmlKetemu = 0;
    printHeader("ENTRI YANG DITEMUKAN", 50);
    for (int i = 0; i < ukuran; i++) {
        string konstelasiSistem = (arr + i)->konstelasi;
        toUpperString(konstelasiSistem);
        
        if (konstelasiSistem == cariKupper) {
            jmlKetemu++;
            printSeparator("-", 49);
            cout << "ID Entri         : " << (arr + i)->entriID << endl;
            cout << "Nama Objek       : " << (arr + i)->namaObjek << endl;
            cout << "Klasifikasi      : " << (arr + i)->klasifikasi << endl;
            cout << "Konstelasi       : " << (arr + i)->konstelasi << endl;
            cout << "Jarak dari Bumi  : " << (arr + i)->jarakDariBumi << endl;
            cout << "Tahun Penemuan   : " << (arr + i)->tahunPenemuan << endl;
            cout << "Status Observasi : " << (arr + i)->statusObservasi << endl;
            cout << "Magnitudo        : " << (arr + i)->magnitudo << endl;
            printSeparator("-", 49);
            cout << endl;
        }
    }
    cout << "=> Berhasil menemukan " << jmlKetemu << " objek pada konstelasi " << cariK << endl;
    system("pause");
}

void cariKategori(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << "=> Data kosong, tidak ada yang bisa dicari!" << endl;
        system("pause");
        return;
    }

    string cariKat;
    clearScreen();
    printHeader("CARI BERDASARKAN KATEGORI", 50);

    cin.ignore();
    while (true) {
        cout << "Masukkan Kategori: " << endl;
        cout << "> ";
        getline(cin, cariKat);

        if (cariKat.empty()) {
            cout << "=> Input tidak boleh kosong!" << endl;
            continue;
        }

        toUpperString(cariKat);
        bool valid = true;
        for (char c : cariKat) {
            if (!isalpha(c) && c != ' ') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "=> Input tidak valid, hanya huruf yang diperbolehkan!" << endl;
            continue;
        }

        break;
    }

    clearScreen();
    int jmlKetemu = 0;
    printHeader("ENTRI YANG DITEMUKAN", 50);
    for (int i = 0; i < ukuran; i++) {
        if ((arr + i)->klasifikasi == cariKat) {
            jmlKetemu++;
            printSeparator("-", 49);
            cout << "ID Entri         : " << (arr + i)->entriID << endl;
            cout << "Nama Objek       : " << (arr + i)->namaObjek << endl;
            cout << "Klasifikasi      : " << (arr + i)->klasifikasi << endl;
            cout << "Konstelasi       : " << (arr + i)->konstelasi << endl;
            cout << "Jarak dari Bumi  : " << (arr + i)->jarakDariBumi << endl;
            cout << "Tahun Penemuan   : " << (arr + i)->tahunPenemuan << endl;
            cout << "Status Observasi : " << (arr + i)->statusObservasi << endl;
            cout << "Magnitudo        : " << (arr + i)->magnitudo << endl;
            printSeparator("-", 49);
            cout << endl;
        }
    }

    if (jmlKetemu == 0) {
        cout << "=> Belum ada objek astronomi pada kategori " << cariKat << endl;
    } else {
        cout << "=> Ditemukan " << jmlKetemu << " objek astronomi pada kategori " << cariKat << endl;
    }
    system("pause");
}

int cariNama(BendaLangit arr[], int ukuran, string targetNama) {
    urutkanNama(arr, ukuran);
    int left = 0; 
    int right = ukuran - 1; 

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid].namaObjek == targetNama) {
            return mid;
        }
        else if (arr[mid].namaObjek < targetNama) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }

    return -1;
}