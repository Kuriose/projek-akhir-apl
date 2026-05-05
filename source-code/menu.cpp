#include "types.h"
#include "data.h"
#include "utils.h"
#include "crud_entri.h"
#include "crud_akun.h"
#include "sort_search.h"
#include "auth.h"
#include "menu.h"

#include <iostream>
using namespace std; 

// --- Menu Utama ---
void menuUtama() {
    int pilihan; 
    
    do {
        try {
            cout << "\n=== Menu Utama ===" << endl;
            cout << "1. Login" << endl; 
            cout << "2. Register" << endl; 
            cout << "0. Keluar" << endl;
            
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear();
                while (cin.peek() != '\n') {
                    cin.ignore();
                }

                pilihan = -1; 
                throw invalid_argument("Input Harus Angka!");
            }

            if (pilihan > 2 || pilihan < 0) {
                throw length_error("Pilihan Tidak Valid");
            }

            if (pilihan == 0) {
                cout << "=> Keluar Dari Program!" << endl;
                break; 
            }
            else if (pilihan == 1) {
                cout << "=> Mengarahkan ke 'Menu Login'" << endl;
                int indeksUser = login(akun, jumlahPengguna);
                
                if (indeksUser >= 0) {
                    cout << "=> Mengarahkan ke menu selanjutnya" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    if (akun[indeksUser].isAdmin) { 
                        menuAdmin(indeksUser);
                    } 
                    else {
                        menuUser(indeksUser);
                    }
                } 
                else {
                    cout << "=> Keluar dari program" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << "===               Kesempatan Login Habis              ===" << endl;
                    cout << "================= Silakan Ulang Program =================" << endl;
                    pilihan = 0; 

                    cout << endl;
                } 
            }
            else if (pilihan == 2) {
                cout << "=> Mengarahkan ke 'Menu Register'" << endl;
                regis(akun, jumlahPengguna); 
            }
            else {
                cout << "=> Pilihan Tidak Valid!" << endl;
            }
        }
    
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (pilihan != 0);
}

// --- Menu Admin & User
void menuAdmin(int indeksLogin) {
    int pilihan; 

    do {
        cout << "\n=== MENU ADMIN ===" << endl; 
        cout << "Selamat Datang Kembali Admin " << akun[indeksLogin].username << endl; 
        cout << "[ENTRI]" << endl; 
        cout << "1. Tambah Entri Baru" << endl; 
        cout << "2. Lihat Entri" << endl; 
        cout << "3. Perbarui Entri" << endl; 
        cout << "4. Hapus Entri" << endl; 
        cout << "5. Urutkan Entri" << endl; 
        cout << "6. Cari Entri" << endl;

        cout << "\n[AKUN]" << endl; 
        cout << "7. Tambah Akun" << endl; 
        cout << "8. Lihat Akun" << endl; 
        cout << "9. Perbarui Akun" << endl; 
        cout << "10. Hapus Akun" << endl; 

        cout << "-------------------------------------" << endl;
        cout << "0. Keluar" << endl; 
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan;
        
        pilihan = errorHandling(pilihan); 

        if (pilihan == 0) {
            cout << "=> Logout dari Akun" << endl; 
            break;  
        }
        else if (pilihan == 1) {
            cout << "=> Mengarahkan ke Menu 'Tambah Entri'" << endl;
            tambahEntri(entri, jumlahEntri); 
        }
        else if (pilihan == 2) {
            cout << "=> Mengarahkan ke Menu 'Lihat Entri'" << endl;
            menuRead(); 
        }
        else if (pilihan == 3) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Entri'" << endl;
            perbaruiEntri(entri, jumlahEntri);
        }
        else if (pilihan == 4) {
            cout << "=> Mengarahkan ke Menu 'Hapus Entri'" << endl;
            hapusEntri();
        }
        else if (pilihan == 5) {
            cout << "=> Mengarahkan ke Menu 'Urutkan Entri'" << endl;
            menuSort();
        }
        else if (pilihan == 6) {
            cout << "=> Mengarahkan ke Menu 'Cari Entri'" << endl;
            menuSearch();
        }
        else if (pilihan == 7) {
            cout << "=> Mengarahkan ke Menu 'Tambah Akun'" << endl;
            regis(akun, jumlahPengguna);
        }
        else if (pilihan == 8) {
            cout << "=> Mengarahkan ke Menu 'Lihat Akun'" << endl;
            menu_read_akun();
        }
        else if (pilihan == 9) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Akun'" << endl;
            ubahAkun(akun, jumlahPengguna);
        }
        else if (pilihan == 10) {
            cout << "=> Mengarahkan ke Menu 'Hapus Akun'" << endl;
            hapusAkun(akun, jumlahPengguna);
        }
        else {
            cout << "=> Pilihan Tidak Valid!" << endl;
        }
    
    } while (pilihan != 0);
}

void menuUser(int indeksLogin) {
    int pilihan; 
    
    do {
        cout << "\n=== MENU USER ===" << endl; 
        cout << "Selamat Datang Kembali " << akun[indeksLogin].username << endl; 
        cout << "[ENTRI]" << endl;
        cout << "1. Lihat Entri" << endl; 
        cout << "2. Urutkan Entri" << endl; 
        cout << "3. Cari Entri" << endl;
        
        cout << "\n[AKUN]" << endl; 
        cout << "4. Perbarui Data Pribadi" << endl;
        cout << "------------------------------------------" << endl; 
        cout << "0. Logout" << endl; 
        
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan; 
        
        pilihan = errorHandling(pilihan);

        if (pilihan == 0) {
            cout << "=> Logout dari Akun" << endl; 
            break; 
        }
        else if (pilihan == 1) {
            cout << "=> Mengarahkan ke Menu 'Lihat Entri'" << endl;
            menuRead(); 
        }
        else if (pilihan == 2) {
            cout << "=> Mengarahkan ke Menu 'Urutkan Entri'" << endl;
            menuSort();
        }
        else if (pilihan == 3) {
            cout << "=> Mengarahkan ke Menu 'Cari Entri'" << endl;
            menuSearch(); 
        }
        else if (pilihan == 4) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Data Pribadi'" << endl;
        }
        else {
            cout << "=> Pilihan Tidak Valid!" << endl;
        }
    } while (pilihan != 0); 
}

// --- Menu Read ---
void menuRead () {
    int pilihan; 
    
    do {
        try {
            cout << "\n=== MENU READ ===" << endl; 
            cout << "1. Lihat Seluruh Entri" << endl; 
            cout << "2. Lihat Entri Spesifik" << endl; 
            cout << "-------------------------------------------" << endl; 
            
            cout << "0. Kembali" << endl; 
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear(); 
                while (cin.peek() != '\n') {
                    cin.ignore();
                }
                pilihan = -1; 
                throw invalid_argument("Input Harus Berupa Angka!"); 
            }

            if (pilihan > 2 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan Melebihi Range Menu!"); 
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl; 
            }
            else if (pilihan == 1) {
                cout << "=> Menampilkan Seluruh Entri" << endl; 
                lihatSeluruhEntri(entri, jumlahEntri);
                system("pause");
            }
            else if (pilihan == 2) {
                cout << "=> Menampilkan Entri Spesifik" << endl; 
                lihatSpesifik(entri, jumlahEntri);
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl; 
        }

    } while (pilihan != 0);
}

void menu_read_akun() {
    int pilihan; 
    
    do {
        try {
            cout << "\n=== MENU READ AKUN ===" << endl; 
            cout << "1. Lihat Seluruh Akun" << endl; 
            cout << "2. Lihat Akun Spesifik" << endl; 
            cout << "-------------------------------------------" << endl; 
            
            cout << "0. Kembali" << endl; 
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> ";
            cin >> pilihan;

            if (cin.fail()) {
                cin.clear(); 
                while (cin.peek() != '\n') {
                    cin.ignore();
                }
                pilihan = -1; 
                throw invalid_argument("Input Harus Berupa Angka!"); 
            }

            if (pilihan > 2 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan Melebihi Range Menu!"); 
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl; 
            }
            else if (pilihan == 1) {
                cout << "=> Menampilkan Seluruh Akun" << endl; 
                lihatSeluruhAkun(akun, jumlahPengguna);
                system("pause");
            }
            else if (pilihan == 2) {
                cout << "=> Menampilkan Detail Akun Spesifik" << endl; 
                lihatAkunSpesifik(akun, jumlahPengguna);
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl; 
            system("pause");
        }

    } while (pilihan != 0);
}

// --- Menu Sort & Sort ---
void menuSort() {
    int pilihan;

    do {
        try {
            cout << "\n=== MENU SORT ===" << endl; 
            cout << "1. Urutkan Berdasarkan Jarak" << endl; 
            cout << "2. Urutkan Berdasarkan Nama" << endl; 
            cout << "3. Urutkan Berdasarkan Tahun Penemuan" << endl; 
            cout << "4. Urutkan Berdasarkan Magnitudo" << endl; 
            cout << "--------------------------------------" << endl; 
            cout << "0. Kembali" << endl; 

            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear(); 
                while (cin.peek() != '\n') {
                    cin.ignore();
                }

                pilihan = -1; 
                throw invalid_argument("Input Harus Berupa Angka!");
            }

            if (pilihan > 4 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan diluar Range Menu!");
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl;
            }
            else if (pilihan == 1) {
                cout << "=> Mengurutkan Berdasarkan Jarak" << endl;
            }
            else if (pilihan == 2) {
                cout << "=> Mengurutkan Berdasarkan Nama" << endl;
                urutkanBerdasarkanNama(entri, jumlahEntri); 
            }
            else if (pilihan == 3) {
                cout << "=> Mengurutkan Berdasarkan Tahun Penemuan" << endl;
                urutkanBerdasarkanTahun(entri, jumlahEntri);
                cout << "=> Data setelah diurutkan berdasarkan Tahun" << endl;
                lihatSeluruhEntri(entri, jumlahEntri);
                system("pause");
            }
            else if (pilihan == 4) {
                cout << "=> Mengurutkan Berdasarkan Magnitudo" << endl;
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (pilihan != 0);
}

void menuSearch() {
    int pilihan;

    do {
        try {
            cout << "\n=== MENU SORT ===" << endl; 
            cout << "1. Cari Berdasarkan Nama" << endl;
            cout << "2. Cari Berdasarkan Kategori" << endl; 
            cout << "3. Cari Berdasarkan Konstelasi" << endl; 
            cout << "---------------------------------------------" << endl; 
            cout << "0. Kembali" << endl; 
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear(); 
                while (cin.peek() != '\n') {
                    cin.ignore();
                }
                pilihan = -1;
                throw invalid_argument("Input Harus Berupa Angka!");
            }

            if (pilihan > 3 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan Melebihi Range Menu!");
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl; 
            }
            else if (pilihan == 1) {
                cout << "=> Mencari Entri Berdasarkan Nama" << endl;
            }
            else if (pilihan == 2) {
                cout << "=> Mencari Entri Berdasarkan Kategori" << endl;
            }   
            else if (pilihan == 3) {
                cout << "=> Mencari Entri Berdasarkan Konstelasi" << endl;
                cariKonstelasi(entri, jumlahEntri);
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl; 
        }

    } while (pilihan != 0);
}