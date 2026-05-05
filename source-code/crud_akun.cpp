#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_akun.h"

#include <iostream>
using namespace std;

void lihatSeluruhAkun(Pengguna *ptrAkun, int ukuran) {
    if (ukuran == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl; 
        system("pause"); 
        return; 
    }

    cout << "\n=== DAFTAR SELURUH AKUN ===" << endl; 
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

    lihatSeluruhAkun(ptrAkun, ukuran);

    int idAkunSpesifik;
    cout << "\nMasukkan User ID untuk detail lengkap: ";
    cin >> idAkunSpesifik;

    bool ditemukan = false;
    for (int i = 0; i < ukuran; i++) {
        if ((ptrAkun + i)->userID == idAkunSpesifik) {
            cout << "\n==========================================" << endl;
            cout << "            DETAIL LENGKAP AKUN           " << endl;
            cout << "==========================================" << endl;
            cout << "User ID        : " << (ptrAkun + i)->userID << endl;
            cout << "Username       : " << (ptrAkun + i)->username << endl;
            cout << "Password       : " << (ptrAkun + i)->password << endl;
            cout << "Role           : " << ((ptrAkun + i)->isAdmin ? "Admin" : "Member") << endl;
            cout << "==========================================" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\n=> User ID " << idAkunSpesifik << " tidak ditemukan!" << endl;
    }
    system("pause");
}

void ubahAkun(Pengguna *ptrAkun, int jumlahPengguna) {
    if (jumlahPengguna == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl;
        system("pause");
        return;
    }

    lihatSeluruhAkun(ptrAkun, jumlahPengguna);

    int idAkun;
    cout << "\nMasukkan User ID yang ingin diubah: ";
    cin >> idAkun;

    bool ditemukan = false;
    for (int i = 0; i < jumlahPengguna; i++) {
        if ((ptrAkun + i)->userID == idAkun) {
            cout << "\n--- Ubah Data Akun ---" << endl;
            cout << "Username baru   : "; cin >> (ptrAkun + i)->username;
            cout << "Password baru   : "; cin >> (ptrAkun + i)->password;
            char roleInput;
            cout << "Role baru (A/U) : "; cin >> roleInput;
            (ptrAkun + i)->isAdmin = (roleInput == 'A' || roleInput == 'a');
            cout << "=> Data akun berhasil diperbarui!" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\n=> User ID " << idAkun << " tidak ditemukan!" << endl;
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
    cout << "\nMasukkan User ID yang ingin dihapus: ";
    cin >> idAkun;

    bool ditemukan = false;
    for (int i = 0; i < jumlahPengguna; i++) {
        if ((ptrAkun + i)->userID == idAkun) {
            for (int j = i; j < jumlahPengguna - 1; j++) {
                *(ptrAkun + j) = *(ptrAkun + j + 1);
            }
            jumlahPengguna--;
            cout << "=> Akun dengan ID " << idAkun << " berhasil dihapus!" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\n=> User ID " << idAkun << " tidak ditemukan!" << endl;
    }
    system("pause");
}

void lihatAkunSendiri(Pengguna *ptrAkun, int indeksAkun, int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        if ((ptrAkun + i)->userID == indeksAkun) {
            cout << "\n==========================================" << endl;
            cout << "            DETAIL LENGKAP AKUN           " << endl;
            cout << "==========================================" << endl;
            cout << "User ID        : " << (ptrAkun + i)->userID << endl;
            cout << "Username       : " << (ptrAkun + i)->username << endl;
            cout << "Password       : " << (ptrAkun + i)->password << endl;
            cout << "Role           : " << ((ptrAkun + i)->isAdmin ? "Admin" : "Member") << endl;
            cout << "==========================================" << endl;
            break;
        }
    }
    system("pause");
}