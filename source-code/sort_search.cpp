#include "types.h"
#include "sort_search.h"
#include "utils.h"

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void urutkanBerdasarkanJarak(BendaLangit arr[], int ukuran) {    
    if (ukuran == 0) {
        cout << FG_MERAH << "[!] Data kosong, tidak ada yang bisa diurutkan" << RESET_WARNA << endl; 
        printSeparator("-", 49);
        system("pause"); 
        return; 
    }
    
    string inputUser;
    char urutan;
    bool valid = false;

    do {
        clearScreen();
        printHeader("URUTKAN BERDASARKAN JARAK", 50);
        cout << FG_CYAN <<"Pilih urutan pengurutan:" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "A" << FG_HIJAU << "]" << FG_CYAN << " Ascending" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "D" << FG_HIJAU << "]" << FG_CYAN << " Descending" << RESET_WARNA << endl;

        printSeparator("-", 49);
        cout << FG_CYAN << "Masukkan pilihan (A/D): ";
        cout << FG_KUNING; cin >> inputUser; cout << RESET_WARNA;
        
        if (inputUser.length() == 1) {
            urutan = toupper(inputUser[0]); 
            if (urutan == 'A' || urutan == 'D') {
                valid = true; 
            } else {
                cout << FG_MERAH << "[!] Input tidak valid (A/D)" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                system("pause");
            }
        } else {
            cout << FG_MERAH << "[!] Input tidak valid (A/D)" << RESET_WARNA << endl; 
            printSeparator("-", 49);
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
    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Data Berhasil Diurutkan!" << RESET_WARNA << endl;
    printSeparator("-", 49);
    system("pause");
}

void urutkanBerdasarkanNama(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << FG_MERAH << "[!] Data kosong, tidak ada yang bisa diurutkan!" << RESET_WARNA << endl;
        printSeparator("-", 49);
        system("pause");
        return;
    }

    clearScreen();
    printHeader("URUTKAN BERDASARKAN NAMA", 50);
    cout << FG_CYAN <<"Pilih urutan pengurutan:" << endl;
    cout << FG_HIJAU << "[" << FG_PUTIH << "A" << FG_HIJAU << "]" << FG_CYAN << " Ascending (A-Z)" << endl;
    cout << FG_HIJAU << "[" << FG_PUTIH << "D" << FG_HIJAU << "]" << FG_CYAN << " Descending (Z-A)" << RESET_WARNA << endl;
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
    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Data Berhasil Diurutkan!" << RESET_WARNA << endl;
    printSeparator("-", 49);
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
        cout << FG_MERAH << "[!] Data kosong, tidak ada yang bisa diurutkan" << RESET_WARNA << endl;
        printSeparator("-", 49);
        system("pause");
        return;
    }

    string inputUser;
    char urutan;
    bool valid = false;
    do {
        clearScreen();
        printHeader("URUTKAN BERDASARKAN TAHUN", 50);
        
        cout << FG_CYAN <<"Pilih urutan pengurutan:" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "A" << FG_HIJAU << "]" << FG_CYAN << " Ascending" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "D" << FG_HIJAU << "]" << FG_CYAN << " Descending" << RESET_WARNA << endl;

        printSeparator("-", 49);
        cout << FG_CYAN << "Masukkan pilihan (A/D): ";
        cout << FG_KUNING; cin >> inputUser; cout << RESET_WARNA;

        if (inputUser.length() == 1) {
            urutan = toupper(inputUser[0]);
            if (urutan == 'A' || urutan == 'D') {
                valid = true;
            } else {
                cout << FG_MERAH << "=> Input tidak valid (A/D)" << RESET_WARNA << endl;
                printSeparator("-", 49);
                system("pause");
            }
        } else {
            cout << FG_MERAH << "[!] Input tidak valid (A/D)" << RESET_WARNA << endl;
            printSeparator("-", 49);
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
    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Data Berhasil diurutkan (" << FG_KUNING << (urutan == 'A' ? "Ascending" : "Descending") << FG_CYAN << ")" << RESET_WARNA << endl;
    printSeparator("-", 49);
    system("pause");
}

void urutkanBerdasarkanMagnitudo(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << FG_MERAH << "[!] Data kosong, tidak ada yang bisa diurutkan!" << RESET_WARNA << endl;
        printSeparator("-", 49);
        system("pause");
        return;
    }

    clearScreen();
    printHeader("URUTKAN BERDASARKAN MAGNITUDO", 50);
    cout << FG_CYAN <<"Pilih urutan pengurutan:" << endl;
    cout << FG_HIJAU << "[" << FG_PUTIH << "A" << FG_HIJAU << "]" << FG_CYAN << " Ascending (Terkecil -> Terbesar)" << endl;
    cout << FG_HIJAU << "[" << FG_PUTIH << "D" << FG_HIJAU << "]" << FG_CYAN << " Descending (Terbesar -> Terkecil)" << RESET_WARNA << endl;
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
    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Data Berhasil Diurutkan!" << RESET_WARNA << endl;
    printSeparator("-", 49);
    system("pause");
}

void cariKonstelasi(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << FG_MERAH << "[!] Data Entri kosong" << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return;
    }

    string cariK;
    string cariKupper;
    cin.ignore(1000, '\n');

    clearScreen();
    printHeader("CARI BERDASARKAN KONSTELASI", 80);
    
    int pilihan; 
    bool selesai = false;

    do {
        clearScreen();

        printHeader("KONSTELASI OBJEK", 80); 
        cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Konstelasi yang Ada" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Input Konstelasi Manual" << RESET_WARNA << endl;
        
        printSeparator("-", 79);
        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan;
        printSeparator("-", 79);

        pilihan = errorHandling(pilihan);
        
        if (pilihan == 1) {
            string kategori[100]; 
            int ukuranKategori = 0; 
            int pilih; 

            clearScreen();
            
            cout << FG_KUNING << "[DAFTAR KONSTELASI]" << RESET_WARNA << endl; 
            printSeparator("-", 79);
            getKategori(arr, ukuran, "KONSTELASI", kategori, ukuranKategori); 
            
            for (int i = 0; i < ukuranKategori; i++) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
            }

            printSeparator("-", 79);
            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
            
            pilih = errorHandling(pilih); 

            if (pilih > 0 && pilih <= ukuranKategori) {
                cariK = kategori[pilih - 1];
                selesai = true;
                cin.ignore();
            }
            else {
                cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << endl;
                printSeparator("-", 79);
                system("pause"); 
            }
        }
        else if (pilihan == 2) {
            cin.ignore();
            while (true) {
                cout << FG_CYAN << "Masukkan Nama Konstelasi" << RESET_WARNA << endl;
                cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; getline(cin, cariK);
                printSeparator("-", 79);

                if (cariK.empty()) {
                    cout << FG_MERAH << "[!] Input tidak boleh kosong!" << RESET_WARNA << endl;
                    printSeparator("-", 79);
                    system("pause");
                    printSeparator("-", 79);
                    continue;
                }

                selesai = true;
                break;
            }
        }
        else {
            cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << RESET_WARNA << endl; 
            printSeparator("-", 79);
            system("pause");
        }
        
    } while(!selesai);

    toUpperString(cariK);
    bool spasi = true;
    for (int i = 0; i < cariK.length(); i++) {
        char c = cariK[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            cout << FG_MERAH << "[!] Input nama konstelasi tidak valid!" << RESET_WARNA << endl;
            printSeparator("-", 79);
            system("pause");
            return;
        }
        if (c != ' ') spasi = false;
    }

    if (spasi) {
        cout << FG_MERAH << "[!] Input tidak boleh kosong!" << RESET_WARNA << endl;
        printSeparator("-", 79);
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
        cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Belum ada Objek Astronomi pada Konstelasi " << FG_KUNING << cariK << RESET_WARNA << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return;
    }

    clearScreen();
    int jmlKetemu = 0;
    printHeader("ENTRI YANG DITEMUKAN", 80);
    for (int i = 0; i < ukuran; i++) {
        string konstelasiSistem = (arr + i)->konstelasi;
        toUpperString(konstelasiSistem);
        
        if (konstelasiSistem == cariKupper) {
            jmlKetemu++;
            printSeparator("-", 79);
            cout << FG_CYAN << "ID Entri         " << FG_PUTIH << ": " << (arr + i)->entriID << endl;
            cout << FG_CYAN << "Nama Objek       " << FG_PUTIH << ": " << (arr + i)->namaObjek << endl;
            cout << FG_CYAN << "Klasifikasi      " << FG_PUTIH << ": " << (arr + i)->klasifikasi << endl;
            cout << FG_CYAN << "Konstelasi       " << FG_PUTIH << ": " << FG_KUNING << (arr + i)->konstelasi << endl;
            cout << FG_CYAN << "Jarak dari Bumi  " << FG_PUTIH << ": " << (arr + i)->jarakDariBumi << endl;
            cout << FG_CYAN << "Tahun Penemuan   " << FG_PUTIH << ": " << (arr + i)->tahunPenemuan << endl;
            cout << FG_CYAN << "Status Observasi " << FG_PUTIH << ": " << (arr + i)->statusObservasi << endl;
            cout << FG_CYAN << "Magnitudo        " << FG_PUTIH << ": " << (arr + i)->magnitudo << endl;
            printSeparator("-", 79);
        }
    }
    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Berhasil Menemukan " << FG_KUNING << jmlKetemu << FG_CYAN << " Objek pada Konstelasi " << FG_KUNING << cariKupper << RESET_WARNA << endl;
    printSeparator("-", 79);
    system("pause");
}

void cariKategori(BendaLangit arr[], int ukuran) {
    if (ukuran == 0) {
        cout << FG_MERAH << "[!] Data kosong, tidak ada yang bisa dicari!" << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return;
    }

    string cariKat;
    clearScreen();
    printHeader("CARI BERDASARKAN KLASIFIKASI", 80);

    int pilihan; 
    bool selesai = false;

    do {
        clearScreen();

        printHeader("KLASIFIKASI OBJEK", 80); 
        cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Klasifikasi yang Ada" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Input Klasifikasi Manual" << RESET_WARNA << endl;
        
        printSeparator("-", 79);
        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan;
        printSeparator("-", 79);

        pilihan = errorHandling(pilihan);

        if (pilihan == 1) {
            string kategori[100]; 
            int ukuranKategori = 0; 
            int pilih; 

            clearScreen();
            
            cout << FG_KUNING << "[DAFTAR KLASIFIKASI]" << RESET_WARNA << endl; 
            printSeparator("-", 79);
            getKategori(arr, ukuran, "KLASIFIKASI", kategori, ukuranKategori); 
            
            for (int i = 0; i < ukuranKategori; i++) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
            }

            printSeparator("-", 79);
            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
            
            pilih = errorHandling(pilih); 

            if (pilih > 0 && pilih <= ukuranKategori) {
                cariKat = kategori[pilih - 1];
                selesai = true;
                cin.ignore();
            }
            else {
                cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << endl;
                printSeparator("-", 79);
                system("pause"); 
            }
        }

        else if (pilihan == 2) {
            cin.ignore();
            while (true) {
                cout << FG_CYAN << "Masukkan Kategori" << RESET_WARNA << endl;
                cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; getline(cin, cariKat);
                printSeparator("-", 79);

                if (cariKat.empty()) {
                    cout << FG_MERAH << "[!] Input tidak boleh kosong!" << RESET_WARNA << endl;
                    printSeparator("-", 79);
                    system("pause");
                    printSeparator("-", 79);
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
                    cout << FG_MERAH << "[!] Input tidak valid, hanya huruf yang diperbolehkan!" << RESET_WARNA << endl;
                    printSeparator("-", 79);
                    system("pause");
                    printSeparator("-", 79);
                    continue;
                }

                selesai = true;
                break;
            }
        }

    } while (!selesai);

    clearScreen();
    int jmlKetemu = 0;
    printHeader("ENTRI YANG DITEMUKAN", 80);
    for (int i = 0; i < ukuran; i++) {
        if ((arr + i)->klasifikasi == cariKat) {
            jmlKetemu++;
            printSeparator("-", 79);
            cout << FG_CYAN << "ID Entri         " << FG_PUTIH << ": " << (arr + i)->entriID << endl;
            cout << FG_CYAN << "Nama Objek       " << FG_PUTIH << ": " << (arr + i)->namaObjek << endl;
            cout << FG_CYAN << "Klasifikasi      " << FG_PUTIH << ": " << FG_KUNING << (arr + i)->klasifikasi << endl;
            cout << FG_CYAN << "Konstelasi       " << FG_PUTIH << ": " << (arr + i)->konstelasi << endl;
            cout << FG_CYAN << "Jarak dari Bumi  " << FG_PUTIH << ": " << (arr + i)->jarakDariBumi << endl;
            cout << FG_CYAN << "Tahun Penemuan   " << FG_PUTIH << ": " << (arr + i)->tahunPenemuan << endl;
            cout << FG_CYAN << "Status Observasi " << FG_PUTIH << ": " << (arr + i)->statusObservasi << endl;
            cout << FG_CYAN << "Magnitudo        " << FG_PUTIH << ": " << (arr + i)->magnitudo << RESET_WARNA << endl;
            printSeparator("-", 79);
        }
    }

    if (jmlKetemu == 0) {
        cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Belum ada Objek Astronomi pada Kategori " << FG_KUNING << cariKat << RESET_WARNA << endl;
    } else {
        cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Ditemukan " << FG_KUNING << jmlKetemu << FG_CYAN << " Objek Astronomi pada Kategori " << FG_KUNING << cariKat << RESET_WARNA << endl;
    }
    printSeparator("-", 79);
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