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
            clearScreen();
            
            printHeader("MENU UTAMA", 50); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Login" << RESET_WARNA << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Register" << RESET_WARNA << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Keluar" << RESET_WARNA << endl;

            printSeparator("-", 49); 

            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan; 

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
                printSeparator("-", 49);
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Keluar dari Program!" << RESET_WARNA << endl;

                break; 
            }
            else if (pilihan == 1) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke 'Menu Login'!" << RESET_WARNA << endl;
                int indeksUser = login(akun, jumlahPengguna);
                
                if (indeksUser >= 0) {
                    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke Menu Selanjutnya!" << RESET_WARNA << endl;
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
                    cout << "--------------------------------------------------" << endl;
                    cout << "===           Kesempatan Login Habis           ===" << endl;
                    cout << "============= Silakan Ulang Program ==============" << endl;
                    pilihan = 0; 

                    cout << endl;
                } 
            }
            else if (pilihan == 2) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke 'Menu Register'!" << RESET_WARNA << endl;
                regis(akun, jumlahPengguna); 
            }
            else {
                cout << FG_MERAH << "[!] Pilihan Tidak Valid" << endl;
            }
        }
    
        catch (const exception& e) {
            cout << FG_MERAH << "[!] " << e.what() << RESET_WARNA << endl;
            
            printSeparator("-", 49);
            system("pause");
        }

    } while (pilihan != 0);
}

// --- Menu Admin & User
void menuAdmin(int indeksLogin) {
    int pilihan; 

    do {
        clearScreen();
        
        printHeader("MENU ADMIN", 50);
        cout << FG_CYAN << "Selamat Datang Kembali Admin " << FG_KUNING << akun[indeksLogin].username << RESET_WARNA << endl; 
        
        printSeparator("-", 49);
        cout << FG_KUNING << "[ENTRI]" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Tambah Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Lihat Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "03" << FG_HIJAU << "]" << FG_CYAN << " Perbarui Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "04" << FG_HIJAU << "]" << FG_CYAN << " Hapus Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "05" << FG_HIJAU << "]" << FG_CYAN << " Urutkan Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "06" << FG_HIJAU << "]" << FG_CYAN << " Cari Entri" << RESET_WARNA << endl;
        
        printSeparator("-", 49);
        cout << FG_KUNING << "[AKUN]" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "07" << FG_HIJAU << "]" << FG_CYAN << " Tambah Akun" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "08" << FG_HIJAU << "]" << FG_CYAN << " Lihat Akun" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "09" << FG_HIJAU << "]" << FG_CYAN << " Perbarui Akun" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "10" << FG_HIJAU << "]" << FG_CYAN << " Hapus Akun" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "11" << FG_HIJAU << "]" << FG_CYAN << " Lihat Informasi Akun" << endl;
        // cout << FG_HIJAU << "[" << FG_PUTIH << "12" << FG_HIJAU << "]" << FG_CYAN << " Lihat Kategori" << RESET_WARNA << endl;

        printSeparator("-", 49);
        cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Keluar" << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan;
        
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
        else if (pilihan == 11) {
            lihatAkunSendiri(akun, indeksLogin, jumlahPengguna);
        } 
        // else if (pilihan == 12) {
        //     string kategori[100]; 
        //     int jumlahKategori = 0;
            
        //     getKategori(entri, jumlahEntri, "KLASIFIKASI", kategori, jumlahKategori);
        //     cout << "Kategori terdaftar:\n";
        //     for(int i=0; i < jumlahKategori; i++) {
        //         cout << kategori[i] << endl;
        //     }
        //     system("pause");
        // }
        else {
            cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << RESET_WARNA << endl;
            printSeparator("-", 49);
            system("pause");
        }
    
    } while (pilihan != 0);
}

void menuUser(int indeksLogin) {
    int pilihan; 
    
    do {
        clearScreen(); 
        
        printHeader("MENU USER", 50);
        cout << FG_CYAN << "Selamat Datang Kembali " << FG_KUNING << akun[indeksLogin].username << RESET_WARNA << endl; 
        
        printSeparator("-", 49);
        cout << FG_KUNING << "[ENTRI]" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Lihat Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Urutkan Entri" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "03" << FG_HIJAU << "]" << FG_CYAN << " Cari Entri" << RESET_WARNA << endl;
        
        printSeparator("-", 49);
        cout << FG_KUNING << "[AKUN]" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "04" << FG_HIJAU << "]" << FG_CYAN << " Lihat Informasi Akun" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "05" << FG_HIJAU << "]" << FG_CYAN << " Perbarui Informasi Akun" << RESET_WARNA << endl;
        
        printSeparator("-", 49); 
        cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Logout" << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan; 
        
        pilihan = errorHandling(pilihan);

        if (pilihan == 0) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Logout dari Akun" << RESET_WARNA << endl;
            break; 
        }
        else if (pilihan == 1) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke Menu 'Lihat Entri'!" << RESET_WARNA << endl;
            menuRead(); 
        }
        else if (pilihan == 2) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke Menu 'Urutkan Entri'!" << RESET_WARNA << endl;
            menuSort();
        }
        else if (pilihan == 3) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke Menu 'Cari Entri'!" << RESET_WARNA << endl;
            menuSearch(); 
        }
        else if (pilihan == 4) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke Menu 'Lihat Informasi Akun'!" << RESET_WARNA << endl;
            lihatAkunSendiri(akun, indeksLogin, uniqueUser);
        }
        else if (pilihan == 5) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengarahkan ke Menu 'Perbarui Informasi Akun'!" << RESET_WARNA << endl;
            updateProfile(akun, indeksLogin, uniqueUser); 
        } 
        else {
            cout << FG_MERAH << "[!] Pilihan Tidak Valid" << RESET_WARNA << endl;
            printSeparator("-", 49);
            system("pause");
        }
    } while (pilihan != 0); 
}

// --- Menu Read ---
void menuRead () {
    int pilihan; 
    
    do {
        try {
            clearScreen();
            printHeader("LIHAT ENTRI", 50); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Lihat Seluruh Entri" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Lihat Entri Spesifik" << RESET_WARNA << endl;
            
            printSeparator("-", 49); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Kembali" << RESET_WARNA << endl;
            printSeparator("-", 49); 

            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan;

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
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
            }
            else if (pilihan == 1) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Menampilkan Seluruh Entri" << RESET_WARNA << endl;
                clearScreen();
                lihatSeluruhEntri(entri, jumlahEntri);
                
                printSeparator("-", 79);
                system("pause");
            }
            else if (pilihan == 2) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Menampilkan Entri Spesifik" << RESET_WARNA << endl;
                lihatSpesifik(entri, jumlahEntri);
            }
        }

        catch (const exception& e) {
            cout << FG_MERAH <<"[!] " << e.what() << RESET_WARNA << endl;
            printSeparator("-", 49); 
            system("pause"); 
        }

    } while (pilihan != 0);
}

void menu_read_akun() {
    int pilihan; 
    
    do {
        try { 
            clearScreen();
            printHeader("LIHAT AKUN", 50);
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Lihat Seluruh Akun" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Lihat Akun Spesifik" << RESET_WARNA << endl;
            
            printSeparator("-", 49); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Kembali" << RESET_WARNA << endl;
            printSeparator("-", 49); 

            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan;

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
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
            }
            else if (pilihan == 1) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Menampilkan Seluruh Akun" << RESET_WARNA << endl;
                lihatSeluruhAkun(akun, jumlahPengguna);
                
                system("pause");
            }
            else if (pilihan == 2) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Menampilkan Detail Akun Spesifik" << RESET_WARNA << endl;
                lihatAkunSpesifik(akun, jumlahPengguna);
            }
        }

        catch (const exception& e) {
            cout << FG_MERAH << "[!] " << e.what() << endl; 
            printSeparator("-", 49);
            system("pause");
        }

    } while (pilihan != 0);
}

// --- Menu Sort & Sort ---
void menuSort() {
    int pilihan;

    do {
        try {
            clearScreen();
            printHeader("URUTKAN ENTRI", 50);
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Urutkan Berdasarkan Jarak" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Urutkan Berdasarkan Nama" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "03" << FG_HIJAU << "]" << FG_CYAN << " Urutkan Berdasarkan Tahun Penemuan" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "04" << FG_HIJAU << "]" << FG_CYAN << " Urutkan Berdasarkan Magnitudo" << RESET_WARNA << endl;
            
            printSeparator("-", 49); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Kembali" << RESET_WARNA << endl;
            printSeparator("-", 49); 

            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan; 

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
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengurutkan Berdasarkan Jarak" << RESET_WARNA << endl;
                urutkanBerdasarkanJarak(entri, jumlahEntri);

                clearScreen();
                lihatSeluruhEntri(entri, jumlahEntri);
                printSeparator("-", 79);
                system("pause");
            }
            else if (pilihan == 2) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengurutkan Berdasarkan Nama" << RESET_WARNA << endl;
                urutkanBerdasarkanNama(entri, jumlahEntri);
                
                clearScreen();
                lihatSeluruhEntri(entri, jumlahEntri);
                printSeparator("-", 79);
                system("pause");
            }
            else if (pilihan == 3) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengurutkan Berdasarkan Tahun Penemuan" << RESET_WARNA << endl;
                urutkanBerdasarkanTahun(entri, jumlahEntri);
                
                clearScreen();
                lihatSeluruhEntri(entri, jumlahEntri);
                printSeparator("-", 79);
                system("pause");
            }
            else if (pilihan == 4) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengurutkan Berdasarkan Magnitudo" << RESET_WARNA << endl;
                urutkanBerdasarkanMagnitudo(entri, jumlahEntri);

                clearScreen();
                lihatSeluruhEntri(entri, jumlahEntri);
                printSeparator("-", 79);
                system("pause");
            }
        }

        catch (const exception& e) {
            cout << FG_MERAH << "[!] " << e.what() << RESET_WARNA << endl;
            printSeparator("-", 49);
            system("pause");
        }
    } while (pilihan != 0);
}

void menuSearch() {
    int pilihan;

    do {
        try {
            clearScreen(); 
            printHeader("CARI ENTRI", 50);
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Cari Berdasarkan Nama" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Cari Berdasarkan Klasifikasi" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "03" << FG_HIJAU << "]" << FG_CYAN << " Cari Berdasarkan Konstelasi" << RESET_WARNA << endl; 
            
            printSeparator("-", 49); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Kembali" << RESET_WARNA << endl;
            printSeparator("-", 49);

            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihan;

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
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
            }
            else if (pilihan == 1) {
                clearScreen();
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mencari Entri Berdasarkan Nama" << RESET_WARNA << endl;
                
                string targetNama; 
                cin.ignore();
                cout << FG_CYAN << "Masukkan Nama Objek yang Ingin Dicari: "; 
                cout << FG_KUNING; getline(cin, targetNama); cout << RESET_WARNA; 
                printSeparator("-", 49);

                toUpperString(targetNama);
                int indeksObjek = cariNama(entri, jumlahEntri, targetNama);

                if (indeksObjek != -1) {
                    clearScreen();
                    cout << FG_KUNING << "[ENTRI DITEMUKAN]" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    cout << FG_CYAN << "ID Entri         " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].entriID << endl;
                    cout << FG_CYAN << "Nama Objek       " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].namaObjek << endl;
                    cout << FG_CYAN << "Klasifikasi      " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].klasifikasi << endl;
                    cout << FG_CYAN << "Konstelasi       " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].konstelasi << endl;
                    cout << FG_CYAN << "Jarak dari Bumi  " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].jarakDariBumi << endl;
                    cout << FG_CYAN << "Tahun Penemuan   " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].tahunPenemuan << endl;
                    cout << FG_CYAN << "Status Observasi " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].statusObservasi << endl;
                    cout << FG_CYAN << "Magnitudo        " << FG_PUTIH << ": " << FG_KUNING << entri[indeksObjek].magnitudo << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    system("pause");
                }
                else {
                    cout << FG_MERAH << "[!] Entri Tidak Ditemukan" << RESET_WARNA << endl; 
                    printSeparator("-", 49);
                    system("pause");
                }
            }
            else if (pilihan == 2) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mencari Entri Berdasarkan Kategori" << RESET_WARNA << endl;
                cariKategori(entri, jumlahEntri);
            }   
            else if (pilihan == 3) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mencari Entri Berdasarkan Konstelasi" << RESET_WARNA << endl;
                cariKonstelasi(entri, jumlahEntri);
            }
        }

        catch (const exception& e) {
            cout << FG_MERAH << "[!] " << e.what() << RESET_WARNA << endl; 
            printSeparator("-", 49);
            system("pause");
        }

    } while (pilihan != 0);
}