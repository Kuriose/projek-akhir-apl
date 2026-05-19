#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_akun.h"

#include <iostream>
#include <iomanip>
using namespace std;

void lihatSeluruhAkun(Pengguna *ptrAkun, int ukuran) {
    clearScreen();

    if (ukuran == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl;
        system("pause");
        return;
    }

    printHeader("DAFTAR SELURUH AKUN", 50);

    // Header tabel
    cout << left
         << setw(8)  << "ID"
         << setw(25) << "Username"
         << setw(15) << "Role"
         << endl;

    cout << string(48, '-') << endl;

    // Isi tabel
    for (int i = 0; i < ukuran; i++) {

        if (i % 5 == 0 && i != 0) {
            cout << string(48, '-') << endl;
        }

        cout << left
             << setw(8)  << (ptrAkun + i)->userID
             << setw(25) << (ptrAkun + i)->username
             << setw(15) << ((ptrAkun + i)->isAdmin ? "Admin" : "User")
             << endl;
    }

    cout << string(48, '-') << endl;
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
            printHeader("INFORMASI AKUN", 50);
            cout << FG_CYAN << "User ID        " << FG_PUTIH << ": " << FG_KUNING << (ptrAkun + i)->userID << endl;
            cout << FG_CYAN << "Username       " << FG_PUTIH << ": " << FG_KUNING << (ptrAkun + i)->username << endl;
            cout << FG_CYAN << "Password       " << FG_PUTIH << ": " << FG_KUNING << (ptrAkun + i)->password << endl;
            cout << FG_CYAN << "Role           " << FG_PUTIH << ": " << FG_KUNING << ((ptrAkun + i)->isAdmin ? "Admin" : "Member") << endl;
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
                    cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "] " << FG_CYAN << "Username       " << FG_PUTIH << ": " << FG_KUNING << (ptrAkun + i)->username << endl;
                    cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "] " << FG_CYAN << "Password       " << FG_PUTIH << ": " << FG_KUNING << (ptrAkun + i)->password << endl;
                    
                    printSeparator("-", 49);
                    cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Kembali" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    break;
                }
            }
            
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

            if (pilihan < 0 || pilihan > 2) {
                throw length_error("Input Angka Berada diluar Range Menu!"); 
            }

            if (pilihan == 0) {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
            }
            else if (pilihan == 1) {
                string newUsername;  
                
                cin.ignore();
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengganti Username" << RESET_WARNA << endl;
                
                printSeparator("-", 49); 
                cout << FG_CYAN << "Username Lama  " << FG_PUTIH << ": " << FG_HIJAU << ptrAkun[indeksAkun].username << endl; 
                cout << FG_CYAN << "Username Baru  " << FG_PUTIH << ": "; 
                cout << FG_KUNING; getline(cin, newUsername); cout << RESET_WARNA;

                if (newUsername.length() == 0) {
                    newUsername = ptrAkun[indeksAkun].username;
                }

                ptrAkun[indeksAkun].username = newUsername; 
            }
            else if (pilihan == 2) {
                string newPassword;  
                
                cin.ignore();
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Mengganti Password" << RESET_WARNA << endl;
                
                printSeparator("-", 49); 
                cout << FG_CYAN << "Password Lama  " << FG_PUTIH << ": " << FG_HIJAU << ptrAkun[indeksAkun].password << endl; 
                cout << FG_CYAN << "Password Baru  " << FG_PUTIH << ": "; 
                cout << FG_KUNING; getline(cin, newPassword); cout << RESET_WARNA; 

                if (newPassword.length() == 0) {
                    newPassword = ptrAkun[indeksAkun].password;
                }

                ptrAkun[indeksAkun].password = newPassword; 
            }
        }
        catch (const exception &e) {
            cout << FG_MERAH << "[!] " << e.what() << RESET_WARNA << endl; 
            printSeparator("-", 49);
            system("pause");
        }
    } while (pilihan != 0);
     
}