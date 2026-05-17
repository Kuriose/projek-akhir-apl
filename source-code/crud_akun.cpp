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

    int indexDitemukan = -1;
    printSeparator("-", 49);
    cin.ignore();
    do {
        int idAkun = inputAngka("Masukkan User ID yang ingin diubah: ");
        for (int i = 0; i < jumlahPengguna; i++) {
            if ((ptrAkun + i)->userID == idAkun) {
                indexDitemukan = i;
                break;
            }
        }
        if (indexDitemukan == -1) {
            cout << "=> User ID " << idAkun << " tidak ditemukan!" << endl;
        }
    } while (indexDitemukan == -1);

    printHeader("UBAH DATA AKUN", 50);

    string usernameBaru;
    bool usernameValid = false;
    do {
        usernameBaru = inputString("Username baru   : ");
        bool duplikat = false;
        for (int j = 0; j < jumlahPengguna; j++) {
            if ((ptrAkun + j)->username == usernameBaru) {
                duplikat = true;
                break;
            }
        }
        if (duplikat) {
            cout << "=> Username sudah digunakan akun lain!" << endl;
        } else {
            usernameValid = true;
        }
    } while (!usernameValid);

    string passwordBaru = inputString("Password baru   : ", 3);
    char roleInput = inputKarakter("Role baru (A/U) : ", "AU");

    (ptrAkun + indexDitemukan)->username = usernameBaru;
    (ptrAkun + indexDitemukan)->password = passwordBaru;
    (ptrAkun + indexDitemukan)->isAdmin = (roleInput == 'A');

    printSeparator("-", 49);
    cout << "=> Data akun berhasil diperbarui!" << endl;
    system("pause");
}

void hapusAkun(Pengguna *ptrAkun, int &jumlahPengguna) {
    if (jumlahPengguna == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl;
        system("pause");
        return;
    }

    lihatSeluruhAkun(ptrAkun, jumlahPengguna);

    int indexDitemukan = -1;
    printSeparator("-", 49);
    cin.ignore();
    do {
        int idAkun = inputAngka("Masukkan User ID yang ingin dihapus: ");
        for (int i = 0; i < jumlahPengguna; i++) {
            if ((ptrAkun + i)->userID == idAkun) {
                indexDitemukan = i;
                break;
            }
        }
        if (indexDitemukan == -1) {
            cout << "=> User ID " << idAkun << " tidak ditemukan!" << endl;
        }
    } while (indexDitemukan == -1);

    if ((ptrAkun + indexDitemukan)->isAdmin) {
        int jumlahAdmin = 0;
        for (int k = 0; k < jumlahPengguna; k++) {
            if ((ptrAkun + k)->isAdmin) jumlahAdmin++;
        }
        if (jumlahAdmin <= 1) {
            printSeparator("-", 49);
            cout << "=> Tidak dapat menghapus admin terakhir!" << endl;
            system("pause");
            return;
        }
    }

    printSeparator("-", 49);
    char konfirmasi = inputKarakter("Yakin ingin menghapus akun ini? (Y/N): ", "YN");
    if (konfirmasi != 'Y') {
        printSeparator("-", 49);
        cout << "=> Penghapusan dibatalkan!" << endl;
        system("pause");
        return;
    }

    int idTerhapus = (ptrAkun + indexDitemukan)->userID;
    for (int j = indexDitemukan; j < jumlahPengguna - 1; j++) {
        *(ptrAkun + j) = *(ptrAkun + j + 1);
    }
    jumlahPengguna--;
    printSeparator("-", 49);
    cout << "=> Akun dengan ID " << idTerhapus << " berhasil dihapus!" << endl;
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