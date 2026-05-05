#include "types.h"
#include "sort_search.h"

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void urutkanBerdasarkanJarak(BendaLangit arr[], int ukuran) {
    char urutan;
    cout << "\n=== URUTKAN BERDASARKAN TAHUN ===" << endl;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending" << endl;
    cout << "D. Descending" << endl;
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
    
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void urutkanBerdasarkanNama(BendaLangit arr[], int ukuran) {
    char urutan;
    cout << "\n=== URUTKAN BERDASARKAN NAMA ===" << endl;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (A-Z)" << endl;
    cout << "D. Descending (Z-A)" << endl;
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
    cout << "\n=== URUTKAN BERDASARKAN TAHUN ===" << endl;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending" << endl;
    cout << "D. Descending" << endl;
    cout << "Masukkan pilihan (A/D): ";
    cin >> urutan;
    cin.ignore();
    urutan = toupper(urutan);
    
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            
            int thn1;
            string s1 = (arr + j)->tahunPenemuan;
            string temp1 = "";
            for (char c : s1) if (isdigit(c)) temp1 += c;
            if (temp1 != "") {
                thn1 = stoi(temp1);
            } else {
                thn1 = 0;
            }

            int thn2;
            string s2 = (arr + j + 1)->tahunPenemuan;
            string temp2 = "";
            for (char c : s2) if (isdigit(c)) temp2 += c;
            if (temp2 != "") {
                thn2 = stoi(temp2);
            } else {
                thn2 = 0;
            }

            bool perluTukar = false;
            if (urutan == 'A') {
                if (thn1 > thn2) perluTukar = true;
            } else if (urutan == 'D') {
                if (thn1 < thn2) perluTukar = true;
            }

            if (perluTukar) {
                BendaLangit temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void urutkanBerdasarkanMagnitudo(BendaLangit arr[], int ukuran) {
    char urutan;
    cout << "\n=== URUTKAN BERDASARKAN MAGNITUDO ===" << endl;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (Terkecil -> Terbesar)" << endl;
    cout << "D. Descending (Terbesar -> Terkecil)" << endl;
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
    
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}

void cariKonstelasi(BendaLangit arr[], int ukuran) {
    string cariK;
    
    cout << "=== CARI BERDASARKAN KONSTELASI ===" << endl;
    cout << "Masukkan Konstelasi : " << endl;
    cout << "> "; 
    cin.ignore();
    getline(cin, cariK);

    int jmlKetemu = 0;
    for (int i = 0; i < ukuran; i++) {
        if ((arr + i)->konstelasi == cariK) {
            jmlKetemu++;
            cout << "---------------------------------------------------------" << endl;
            cout << "ID Entri         : " << (arr + i)->entriID << endl;
            cout << "Nama Objek       : " << (arr + i)->namaObjek << endl;
            cout << "Klasifikasi      : " << (arr + i)->klasifikasi << endl;
            cout << "Konstelasi       : " << (arr + i)->konstelasi << endl;
            cout << "Jarak dari Bumi  : " << (arr + i)->jarakDariBumi << endl;
            cout << "Tahun Penemuan   : " << (arr + i)->tahunPenemuan << endl;
            cout << "Status Observasi : " << (arr + i)->statusObservasi << endl;
            cout << "Magnitudo        : " << (arr + i)->magnitudo << endl;
            cout << "---------------------------------------------------------" << endl;
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
    
    cout << "\n=== CARI BERDASARKAN KATEGORI ===" << endl;
    cout << "Masukkan Kategori : " << endl;
    cout << "> "; 
    cin.ignore();
    getline(cin, cariKat);

    int jmlKetemu = 0;
    for (int i = 0; i < ukuran; i++) {
        if ((arr + i)->klasifikasi == cariKat) {
            jmlKetemu++;
            cout << "---------------------------------------------------------" << endl;
            cout << "ID Entri         : " << (arr + i)->entriID << endl;
            cout << "Nama Objek       : " << (arr + i)->namaObjek << endl;
            cout << "Klasifikasi      : " << (arr + i)->klasifikasi << endl;
            cout << "Konstelasi       : " << (arr + i)->konstelasi << endl;
            cout << "Jarak dari Bumi  : " << (arr + i)->jarakDariBumi << endl;
            cout << "Tahun Penemuan   : " << (arr + i)->tahunPenemuan << endl;
            cout << "Status Observasi : " << (arr + i)->statusObservasi << endl;
            cout << "Magnitudo        : " << (arr + i)->magnitudo << endl;
            cout << "---------------------------------------------------------" << endl;
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