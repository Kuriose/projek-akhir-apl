#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_akun.h"

#include <iostream>
using namespace std;

void lihatSeluruhAkun(Pengguna *ptrAkun, int ukuran) {
    clearScreen();
    if (ukuran == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl; 
        system("pause"); 
        return; 
    }
 
    printHeader("DAFTAR SELURUH AKUN", 50);
    cout << "ID | Username | Role" << endl; 
    for (int i = 0; i < ukuran; i++) {
        if (i % 5 == 0 && i != 0) {
            cout << "--------------------------------------------------------------------------" << endl;
        }

        cout << (ptrAkun + i)->userID
            << " | " << (ptrAkun + i)->username
            << " | " << ((ptrAkun + i)->isAdmin ? "Admin" : "User")
            << endl; 
    }
}

void lihatAkunSpesifik(Pengguna *ptrAkun, int ukuran) {
    if (ukuran == 0) {
        cout << "\n=> Data Akun kosong!" << endl;
        system("pause");
        return;
    }

    int idAkunSpesifik;
    do{
        lihatSeluruhAkun(ptrAkun, ukuran);
        printSeparator("-", 49);
        cout << "0. Kembali" << endl;
        printSeparator("-", 49);
        cout << "Masukkan User ID untuk detail lengkap: ";
        cin >> idAkunSpesifik;
        printSeparator("-", 49);

        if (cin.fail()) {
            cout << "\n=> Error: Input harus berupa angka (ID)!" << endl;
            idAkunSpesifik = errorHandling(-1); 
            system("pause");
            continue;
        }
        if (idAkunSpesifik == 0) {
            cout << "=> Kembali ke Menu Sebelumnya" << endl;
            system("pause");
            return; 
        }

        bool ditemukan = false;
        for (int i = 0; i < ukuran; i++) {
            if ((ptrAkun + i)->userID == idAkunSpesifik) {
                clearScreen();
                printHeader("DETAIL LENGKAP AKUN", 50);
                cout << "User ID        : " << (ptrAkun + i)->userID << endl;
                cout << "Username       : " << (ptrAkun + i)->username << endl;
                cout << "Password       : " << (ptrAkun + i)->password << endl;
                cout << "Role           : " << ((ptrAkun + i)->isAdmin ? "Admin" : "Member") << endl;
                printSeparator("-", 49);
                ditemukan = true;
                system("pause");
                break;
            }
        }
        if (!ditemukan) {
            cout << "=> User ID " << idAkunSpesifik << " tidak ditemukan!" << endl;
            system("pause");
        }
    } while (idAkunSpesifik != 0);
}

void ubahAkun(Pengguna *ptrAkun, int jumlahPengguna) {
    if (jumlahPengguna == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl;
        system("pause");
        return;
    }

    lihatSeluruhAkun(ptrAkun, jumlahPengguna);

    int idAkun;
    printSeparator("-", 49);
    while (true) {
        try {
            cout << "Masukkan User ID yang ingin diubah: ";
            cin >> idAkun;
            if (cin.fail()) throw "Input ID harus berupa angka!";
            cin.ignore();
            break;
        } catch (const char* msg) {
            cin.clear();
            cin.ignore();
            cout << "=> " << msg << endl;
        }
    }
    printSeparator("-", 49);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPengguna; i++) {
        if ((ptrAkun + i)->userID == idAkun) {
            printHeader("UBAH DATA AKUN", 50);
            
            string temp;
            cout << "Username baru   : ";
            getline(cin, temp);
            if (!temp.empty()) (ptrAkun + i)->username = temp;

            cout << "Password baru   : ";
            getline(cin, temp);
            if (!temp.empty()) (ptrAkun + i)->password = temp;

            char roleInput;
            while (true) {
                try {
                    cout << "Role baru (A/U) : ";
                    cin >> roleInput;
                    if (cin.fail()) throw "Input role gagal!";
                    cin.ignore(1000, '\n');
                    if (roleInput != 'A' && roleInput != 'a' && roleInput != 'U' && roleInput != 'u') {
                        throw "Role wajib diisi 'A' atau 'U'";
                    }
                    break;
                } catch (const char* msg) {
                    cin.clear();
                    cin.ignore();
                    cout << "=> " << msg << endl;
                }
            }
            (ptrAkun + i)->isAdmin = (roleInput == 'A' || roleInput == 'a');
            
            printSeparator("-", 49);
            cout << "=> Data akun berhasil diperbarui!" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "=> User ID " << idAkun << " tidak ditemukan!" << endl;
    }
    system("pause");
}

void hapusAkun(Pengguna *ptrAkun, int &jumlahPengguna) {
    if (jumlahPengguna == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl;
        system("pause");
        return;
    }

    lihatSeluruhAkun(ptrAkun, jumlahPengguna);

    int idAkun;
    printSeparator("-", 49);
    while (true) {
        try {
            cout << "Masukkan User ID yang ingin dihapus: ";
            cin >> idAkun;
            if (cin.fail()) throw "Input ID harus berupa angka!";
            cin.ignore();
            break;
        } catch (const char* msg) {
            cin.clear();
            cin.ignore();
            cout << "=> " << msg << endl;
        }
    }
    printSeparator("-", 49);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPengguna; i++) {
        if ((ptrAkun + i)->userID == idAkun) {
            char konfirmasi;
            while (true) {
                try {
                    cout << "Yakin ingin menghapus akun ini? (y/n): ";
                    cin >> konfirmasi;
                    if (cin.fail()) throw "Input konfirmasi gagal!";
                    cin.ignore();
                    if (konfirmasi != 'y' && konfirmasi != 'Y' && konfirmasi != 'n' && konfirmasi != 'N') {
                        throw "Masukkan 'y' atau 'n'";
                    }
                    break;
                } catch (const char* msg) {
                    cin.clear();
                    cin.ignore();
                    cout << "=> " << msg << endl;
                }
            }

            if (konfirmasi != 'y' && konfirmasi != 'Y') {
                cout << "=> Penghapusan dibatalkan." << endl;
                system("pause");
                return;
            }

            for (int j = i; j < jumlahPengguna - 1; j++) {
                *(ptrAkun + j) = *(ptrAkun + j + 1);
            }
            jumlahPengguna--;
            printSeparator("-", 49);
            cout << "=> Akun dengan ID " << idAkun << " berhasil dihapus!" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "=> User ID " << idAkun << " tidak ditemukan!" << endl;
    }
    system("pause");
}

void lihatAkunSendiri(Pengguna *ptrAkun, int indeksAkun, int ukuran) {
    clearScreen();
    for (int i = 0; i < ukuran; i++) {
        if ((ptrAkun + i)->userID == indeksAkun + 1) {
            printHeader("UBAH DATA AKUN", 50);
            cout << "User ID        : " << (ptrAkun + i)->userID << endl;
            cout << "Username       : " << (ptrAkun + i)->username << endl;
            cout << "Password       : " << (ptrAkun + i)->password << endl;
            cout << "Role           : " << ((ptrAkun + i)->isAdmin ? "Admin" : "Member") << endl;
            printSeparator("-", 49);
            break;
        }
    }
    system("pause");
}

void updateProfile(Pengguna *ptrAkun, int indeksAkun, int ukuran) {
    int pilihan;
    do {
        try {
            clearScreen();
            for (int i = 0; i < ukuran; i++) {
                if ((ptrAkun + i)->userID == indeksAkun + 1) {
                    printHeader("UBAH DATA AKUN", 50);
                    cout << "[1] Username       : " << (ptrAkun + i)->username << endl;
                    cout << "[2] Password       : " << (ptrAkun + i)->password << endl;
                    printSeparator("-", 49);
                    cout << "[0] Keluar" << endl; 
                    printSeparator("-", 49);
                    break;
                }
            }
            
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

            if (pilihan < 0 || pilihan > 2) {
                throw length_error("Input Angka Berada diluar Range Menu!"); 
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya!" << endl; 
            }
            else if (pilihan == 1) {
                string newUsername;  
                
                cin.ignore();
                cout << "=> Mengganti Username" << endl; 
                printSeparator("-", 49); 
                cout << "Username Lama  : " << ptrAkun[indeksAkun].username << endl; 
                cout << "Username Baru  : "; getline(cin, newUsername); 

                if (newUsername.length() == 0) {
                    newUsername = ptrAkun[indeksAkun].username;
                }

                ptrAkun[indeksAkun].username = newUsername; 
            }
            else if (pilihan == 2) {
                string newPassword;  
                
                cin.ignore();
                cout << "=> Mengganti Password" << endl; 
                printSeparator("-", 49); 
                cout << "Password Lama  : " << ptrAkun[indeksAkun].password << endl; 
                cout << "Password Baru  : "; getline(cin, newPassword); 

                if (newPassword.length() == 0) {
                    newPassword = ptrAkun[indeksAkun].password;
                }

                ptrAkun[indeksAkun].password = newPassword; 
            }
        }
        catch (const exception &e) {
            cout << "=> Error: " << e.what() << endl; 
        }
    } while (pilihan != 0);
     
}