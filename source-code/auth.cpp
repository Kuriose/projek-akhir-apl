#include "types.h"
#include "data.h"
#include "auth.h"
#include "utils.h"

#include <iostream> 
using namespace std; 

int login(Pengguna *ptrAkun, int jumlahPengguna) {
    string username, password;
    bool akunDitemukan, passwordBenar = false;
    int indeksUser;
    int kesempatan = 3;

    cin.ignore();
    do {
        indeksUser = -1;
        akunDitemukan = false;
        clearScreen();
        
        printHeader("MENU LOGIN", 50);
        cout << "Masukkan Username Anda" << endl; 
        cout << "> "; getline(cin, username); 
        printSeparator("-", 49); 

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
                cout << "=> Akun ditemukan" << endl;
                printSeparator("-", 49);
                akunDitemukan = true; 
                indeksUser = i; 
                break;
            }
        }

        if (!akunDitemukan) {
            cout << "=> Akun tidak ditemukan. Coba lagi" << endl;
            system("pause");
            printSeparator("-", 49);
        }
    } while (!akunDitemukan);
    
    do {
        cout << "Sisa Kesempatan: " << kesempatan << endl;
        cout << "Masukkan Password Anda" << endl;
        cout << "> "; getline(cin, password);
        printSeparator("-", 49);

        if (password == akun[indeksUser].password) {
            cout << "=> Password benar" << endl;
            printSeparator("-", 49); 
            passwordBenar = true;
        }
        else {
            cout << "=> Password salah! Silakan coba lagi" << endl;
            printSeparator("-", 49);
            kesempatan--;
        }

    } while (kesempatan != 0 && !passwordBenar);

    if (akunDitemukan && passwordBenar) {
        cout << "=> Login berhasil" << endl;
        system("pause");
        printSeparator("-", 49);
        return indeksUser;
    } 
    else {
        cout << "=> Login gagal" << endl;
        printSeparator("-", 49);
        return -1;
    }
}

// --- Register ---
int regis(Pengguna *ptrAkun, int &jumlahPengguna) {
    string username, password;
    bool usernameValid = true;

    cin.ignore();
    do {
        clearScreen();
        usernameValid = true;
        if (jumlahPengguna >= MAXPENGGUNA) {
            cout << "=> Data Pengguna Sudah Penuh!" << endl; 
            printSeparator("-", 49);
            system("Pause");
            printSeparator("-", 49);
            return 0;
        }
        
        // cout << "=== MENU REGISTER =======================================" << endl;
        printHeader("MENU REGISTER", 50);

        cout << "Masukkan Username" << endl;
        cout << "> "; getline(cin, username);
        printSeparator("-", 49);

        if (username.length() == 0) {
            cout << "=> Username Tidak Boleh Kosong!" << endl;
            system("pause"); 
            usernameValid = false;
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
                cout << "=> Username sudah digunakan. Silakan masukkan username lain" << endl;
                system("pause");
                printSeparator("-", 49);
                usernameValid = false; 
                break;
            }
        }
    } while (!usernameValid);

    bool passwordValid = false;
    do {
        passwordValid = true;
        cout << "Masukkan Password" << endl; 
        cout << "> "; getline(cin, password); 
        printSeparator("-", 49);

        if (password.length() == 0) {
            cout << "=> Password Tidak Boleh Kosong!" << endl; 
            passwordValid = false;
            system("pause");
            printSeparator("-", 49);
        }
    } while (!passwordValid);

    ptrAkun[jumlahPengguna].userID = uniqueUser + 1; 
    ptrAkun[jumlahPengguna].username = username; 
    ptrAkun[jumlahPengguna].password = password; 
    ptrAkun[jumlahPengguna].isAdmin = false;
    jumlahPengguna++; uniqueUser++;

    cout << "=> Register berhasil" << endl;
    system("pause");
    printSeparator("-", 49);
    return jumlahPengguna;
}