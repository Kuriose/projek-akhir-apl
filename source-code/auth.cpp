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
        cout << FG_CYAN <<"Masukkan Username Anda" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; getline(cin, username); 
        printSeparator("-", 49); 

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_KUNING << FG_HIJAU << "Akun Ditemukan!" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                akunDitemukan = true; 
                indeksUser = i; 
                break;
            }
        }

        if (!akunDitemukan) {
            cout << FG_MERAH << "[!] Akun Tidak Ditemukan!" << RESET_WARNA << endl;
            system("pause");
            printSeparator("-", 49);
        }
    } while (!akunDitemukan);
    
    do {
        string warna = FG_HIJAU;
        if (kesempatan == 2) {
            warna = FG_KUNING;
        }
        else if (kesempatan < 2) {
            warna = FG_MERAH;
        }
        
        cout << FG_CYAN <<"Sisa Kesempatan: " << warna << kesempatan << endl;
        cout << FG_CYAN << "Masukkan Password Anda" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; getline(cin, password);
        printSeparator("-", 49);

        if (password == akun[indeksUser].password) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_KUNING << FG_HIJAU << "Password Benar!" << RESET_WARNA << endl;
            printSeparator("-", 49); 
            passwordBenar = true;
        }
        else {
            cout << FG_MERAH << "[!] Password Salah! Silahkan Coba Lagi!" << RESET_WARNA << endl;
            printSeparator("-", 49);
            kesempatan--;
        }

    } while (kesempatan != 0 && !passwordBenar);

    if (akunDitemukan && passwordBenar) {
        cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << "Login Berhasil!" << RESET_WARNA << endl;
        printSeparator("-", 49);
        system("pause");
        return indeksUser;
    } 
    else {
        cout << FG_MERAH << "[!] Login Gagal!" << RESET_WARNA << endl;
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
            cout << FG_MERAH << "[!] Data Pengguna Sudah Penuh!" << RESET_WARNA << endl; 
            printSeparator("-", 49);
            system("Pause");
            return 0;
        }
        
        printHeader("MENU REGISTER", 50);
        cout << FG_CYAN << "Masukkan Username" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; getline(cin, username);
        printSeparator("-", 49);

        if (username.length() == 0) {
            cout << FG_MERAH << "[!] Username Tidak Boleh Kosong!" << RESET_WARNA << endl; 
            printSeparator("-", 49);
            system("pause"); 
            usernameValid = false;
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) {
                cout << FG_MERAH << "[!] Username Sudah Digunakan!" << RESET_WARNA << endl;  
                printSeparator("-", 49);
                
                system("pause");
                usernameValid = false; 
                break;
            }
        }
    } while (!usernameValid);

    bool passwordValid = false;
    do {
        passwordValid = true;
        cout << FG_CYAN << "Masukkan Password" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; getline(cin, password);
        printSeparator("-", 49); 

        if (password.length() == 0) {
            cout << FG_MERAH << "[!] Password Tidak Boleh Kosong!" << RESET_WARNA << endl; 
            passwordValid = false;
            printSeparator("-", 49);
            system("pause");
            printSeparator("-", 49);
        }
    } while (!passwordValid);

    ptrAkun[jumlahPengguna].userID = uniqueUser + 1; 
    ptrAkun[jumlahPengguna].username = username; 
    ptrAkun[jumlahPengguna].password = password; 
    ptrAkun[jumlahPengguna].isAdmin = false;
    jumlahPengguna++; uniqueUser++;

    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] Register Berhasil!" << RESET_WARNA << endl;
    
    printSeparator("-", 49);
    system("pause");
    return jumlahPengguna;
}