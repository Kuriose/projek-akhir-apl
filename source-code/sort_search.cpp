#include "types.h"
#include "sort_search.h"

#include <iostream>
using namespace std;

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
            for (char c : s1) if (isdigit(c)) temp1 += c; //setiap karakter tahun diperiksa, jika angka, disimpan di temp1
            if (temp1 != "") {
                thn1 = stoi(temp1); //ubah tipe data temp1 (string) menjadi int supaya bisa dibandingkan angka tahunnya
            } else {
                thn1 = 0; // kalau tahunnya "zaman kuno" (terlama) yg tidak menyimpan angka
            }

            int thn2; //elemen setelahnya juga diubah ke angka
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