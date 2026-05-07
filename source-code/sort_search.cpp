#include "types.h"
#include "sort_search.h"
#include "utils.h"

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void urutkanBerdasarkanJarak(BendaLangit arr[], int ukuran) {
    char urutan;
    clearScreen();
    
    printHeader("URUTKAN BERDASARKAN JARAK", 50);
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending" << endl;
    cout << "D. Descending" << endl;
    
    printSeparator("-", 49);
    cout << "Masukkan pilihan (A/D): ";
    cin >> urutan;
    cin.ignore();
    urutan = toupper(urutan);

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
    char urutan;

    clearScreen();
    printHeader("URUTKAN BERDASARKAN NAMA", 50);
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (A-Z)" << endl;
    cout << "D. Descending (Z-A)" << endl;
    
    printSeparator("-", 49);
    cout << "Masukkan pilihan (A/D): ";
    cin >> urutan;
    cin.ignore();
    urutan = toupper(urutan);
    
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if (urutan == 'A') {
                if ((arr+j)->namaObjek > (arr+j+1)->namaObjek) {
                    perluTukar = true;
                }
            }
            else if (urutan == 'D') {
                if ((arr+j)->namaObjek < (arr+j+1)->namaObjek) {
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
    char urutan;
    
    clearScreen();
    printHeader("URUTKAN BERDASARKAN TAHUN", 50);
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending" << endl;
    cout << "D. Descending" << endl;
    
    printSeparator("-", 49);
    cout << "Masukkan pilihan (A/D): ";
    cin >> urutan;
    cin.ignore();
    urutan = toupper(urutan);
    
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
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void urutkanBerdasarkanMagnitudo(BendaLangit arr[], int ukuran) {
    char urutan;
    
    clearScreen();
    printHeader("URUTKAN BERDASARKAN MAGNITUDO", 50);
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (Terkecil -> Terbesar)" << endl;
    cout << "D. Descending (Terbesar -> Terkecil)" << endl;
    
    printSeparator("-", 49);
    cout << "Masukkan pilihan (A/D): ";
    cin >> urutan;
    cin.ignore();
    urutan = toupper(urutan);
    
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if (urutan == 'A') {
                if ((arr+j)->magnitudo > (arr+j+1)->magnitudo) {
                    perluTukar = true;
                }
            }
            else if (urutan == 'D') {
                if ((arr+j)->magnitudo < (arr+j+1)->magnitudo) {
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

void cariKonstelasi(BendaLangit arr[], int ukuran) {
    string cariK;
    
    clearScreen();
    printHeader("CARI BERDASARKAN KONSTELASI", 50);
    cout << "Masukkan Konstelasi : " << endl;
    cout << "> "; 
    cin.ignore();
    getline(cin, cariK);

    clearScreen();
    int jmlKetemu = 0;
    printHeader("ENTRI YANG DITEMUKAN", 50);
    for (int i = 0; i < ukuran; i++) {
        if ((arr + i)->konstelasi == cariK) {
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
        cout << "Belum ada objek astronomi pada konstelasi " << cariK << endl;
    } else {
        cout << "=> Ditemukan " << jmlKetemu << " objek astronomi pada konstelasi " << cariK << endl;
    }
    system("pause");
}

void cariKategori(BendaLangit arr[], int ukuran) {
    string cariKat;
    
    // cout << "\n=== CARI BERDASARKAN KATEGORI ===" << endl;
    
    clearScreen();
    printHeader("CARI BERDASARKAN KATEGORI", 50);
    cout << "Masukkan Kategori : " << endl;
    cout << "> "; 
    cin.ignore();
    getline(cin, cariKat);

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
        cout << "Belum ada objek astronomi pada kategori " << cariKat << endl;
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