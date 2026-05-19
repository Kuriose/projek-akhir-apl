#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_entri.h"

#include <iostream>
#include <iomanip> 
using namespace std;

// --- CREATE
void tambahEntri(BendaLangit newEntri[], int &ukuran) {
    bool lanjut = false;

    double newJarak;
    float newMagnitudo;
    int newTahun;
    string newObjek, newKlasifikasi, newKonstelasi, newStatus;

    cin.ignore();
    do {
        lanjut = false;
        
        clearScreen();
        if (ukuran >= MAXENTRI) {
            cout << FG_MERAH << "[!] Data Entri sudah Penuh!" << RESET_WARNA << endl; 
            printSeparator("-", 49);
            system("pause");
            return; 
        }

        int pilihanKlas; 
        bool selesaiKlas = false;
        
        do {
            clearScreen();

            printHeader("KLASIFIKASI OBJEK", 50); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Klasifikasi yang Sudah Ada" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Buat Klasifikasi Baru" << RESET_WARNA << endl;
            
            printSeparator("-", 49);
            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanKlas;

            pilihanKlas = errorHandling(pilihanKlas); 

            if (pilihanKlas == 1) {
                string kategori[100]; 
                int ukuranKategori = 0; 
                int pilih; 

                clearScreen();
                
                cout << FG_KUNING << "[KLASIFIKASI YANG SUDAH ADA]" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                getKategori(entri, ukuran, "KLASIFIKASI", kategori, ukuranKategori); 
                
                for (int i = 0; i < ukuranKategori; i++) {
                    cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
                }

                printSeparator("-", 49);
                cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
                
                pilih = errorHandling(pilih); 

                if (pilih > 0 && pilih <= ukuranKategori) {
                    newKlasifikasi = kategori[pilih - 1];
                    selesaiKlas = true;
                    cin.ignore();
                }
                else {
                    cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << endl;
                    printSeparator("-", 49);
                    system("pause"); 
                }
            }
            else if (pilihanKlas == 2) {
                clearScreen();
                cin.ignore();
                
                cout << FG_KUNING << "[BUAT KLASIFIKASI BARU]" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                cout << FG_CYAN <<"Masukkan Klasifikasi            " FG_PUTIH << ": "; 
                cout << FG_KUNING; getline(cin, newKlasifikasi); cout << RESET_WARNA;
                printSeparator("-", 49);

                if (newKlasifikasi.length() == 0) {
                    cout << FG_MERAH << "[!] Klasfikasi Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                    printSeparator("-", 49);
                    system("pause"); 
                    continue; 
                }     
                else {
                    selesaiKlas = true;
                    toUpperString(newKlasifikasi);
                    cout << FG_CYAN << "Klasifikasi Baru " << FG_KUNING << newKlasifikasi << FG_CYAN << " Berhasil Ditambahkan!" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    system("pause");
                }
            } 
            
        } while (!selesaiKlas);

        do {
            selesaiKlas = false;
            clearScreen();

            printHeader("ENTRI BARU", 50);
            cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << RESET_WARNA << endl;
            printSeparator("-", 49);
            
            printHeader("KONSTELASI", 50); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Konstelasi yang Sudah Ada" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Buat Konstelasi Baru" << RESET_WARNA << endl;
            
            printSeparator("-", 49);
            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanKlas;
            
            pilihanKlas = errorHandling(pilihanKlas); 

            if (pilihanKlas == 1) {
                string kategori[100]; 
                int ukuranKategori = 0; 
                int pilih; 

                clearScreen();

                cout << FG_KUNING << "[KONSTELASI YANG SUDAH ADA]" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                getKategori(entri, ukuran, "KONSTELASI", kategori, ukuranKategori); 
                
                for (int i = 0; i < ukuranKategori; i++) {
                    cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
                }

                printSeparator("-", 49);
                cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
                
                pilih = errorHandling(pilih); 

                if (pilih > 0 && pilih <= ukuranKategori) {
                    newKonstelasi = kategori[pilih - 1];
                    selesaiKlas = true;
                    cin.ignore();
                }
                else {
                    cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    system("pause"); 
                }
            }
            else if (pilihanKlas == 2) {
                cin.ignore(); 
                clearScreen();

                cout << FG_KUNING << "[BUAT KONSTELASI BARU]" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                cout << FG_CYAN <<"Masukkan Konstelasi            " FG_PUTIH << ": "; 
                cout << FG_KUNING; getline(cin, newKonstelasi); cout << RESET_WARNA;
                printSeparator("-", 49);

                if (newKonstelasi.length() == 0) {
                    cout << FG_MERAH << "[!] Konstelasi Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                    printSeparator("-", 49);
                    system("pause"); 
                    continue; 
                }     
                else {
                    selesaiKlas = true;
                    toUpperString(newKonstelasi);
                    cout << FG_CYAN << "Konstelasi Baru " << FG_KUNING << newKonstelasi << FG_CYAN << " Berhasil Ditambahkan!" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    system("pause");
                }     
            }
        } while (!selesaiKlas);
        
        do {
            selesaiKlas = false;
            clearScreen();

            printHeader("ENTRI BARU", 50);
            cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << endl;
            cout << FG_CYAN << "Konstelasi             " FG_PUTIH << ": " << FG_KUNING << newKonstelasi << RESET_WARNA << endl;
            printSeparator("-", 49);

            printHeader("STATUS OBSERVASI", 50); 
            cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Status yang Sudah Ada" << endl;
            cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Buat Status Baru" << RESET_WARNA << endl;
            
            printSeparator("-", 49);
            cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
            cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanKlas;
            
            pilihanKlas = errorHandling(pilihanKlas); 

            if (pilihanKlas == 1) {
                string kategori[100]; 
                int ukuranKategori = 0; 
                int pilih; 

                clearScreen();

                cout << FG_KUNING << "[STATUS YANG SUDAH ADA]" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                getKategori(entri, ukuran, "STATUS OBSERVASI", kategori, ukuranKategori); 
                
                for (int i = 0; i < ukuranKategori; i++) {
                    cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
                }

                printSeparator("-", 49);
                cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
                
                pilih = errorHandling(pilih); 

                if (pilih > 0 && pilih <= ukuranKategori) {
                    newStatus = kategori[pilih - 1];
                    selesaiKlas = true;
                    cin.ignore();
                }
                else {
                    cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << RESET_WARNA << endl;
                    printSeparator("-", 49); 
                    system("pause"); 
                }
            }
            else if (pilihanKlas == 2) {
                cin.ignore(); 
                clearScreen();

                cout << FG_KUNING << "[BUAT STATUS BARU]" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                cout << FG_CYAN <<"Masukkan Status Observasi            " FG_PUTIH << ": "; 
                cout << FG_KUNING; getline(cin, newStatus); cout << RESET_WARNA;
                printSeparator("-", 49);

                if (newStatus.length() == 0) {
                    cout << FG_MERAH << "[!] Status Observasi Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                    printSeparator("-", 49);
                    system("pause"); 
                    continue; 
                }     
                else {
                    selesaiKlas = true;
                    toUpperString(newStatus);
                    cout << FG_CYAN << "Status Baru " << FG_KUNING << newStatus << FG_CYAN << " Berhasil Ditambahkan!" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    system("pause");
                }
            } 
        } while (!selesaiKlas);

        while (true) {
            clearScreen();

            printHeader("ENTRI BARU", 50);
            cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << endl;
            cout << FG_CYAN << "Konstelasi             " FG_PUTIH << ": " << FG_KUNING << newKonstelasi << endl;
            cout << FG_CYAN << "Status Observasi       " FG_PUTIH << ": " << FG_KUNING << newStatus << RESET_WARNA << endl;
            printSeparator("-", 49);

            cout << FG_CYAN << "Masukkan Nama Objek    " FG_PUTIH << ": "; 
            cout << FG_KUNING; getline(cin, newObjek); cout << RESET_WARNA; 
            
            if (newObjek.length() == 0) {
                cout << FG_MERAH << "[!] Nama Objek Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                printSeparator("-", 49);
                system("pause");
                continue;
            }

            toUpperString(newObjek);
            break;
        }

        clearScreen();
        
        printHeader("ENTRI BARU", 50);
        cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << endl;
        cout << FG_CYAN << "Konstelasi             " FG_PUTIH << ": " << FG_KUNING << newKonstelasi << endl;
        cout << FG_CYAN << "Status Observasi       " FG_PUTIH << ": " << FG_KUNING << newStatus << endl;
        cout << FG_CYAN << "Nama Objek             " FG_PUTIH << ": " << FG_KUNING << newObjek << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Masukkan Jarak Dari Bumi       " FG_PUTIH << ": "; 
        cout << FG_KUNING; cin >> newJarak; cout << RESET_WARNA; 
        
        newJarak = errorHandling(newJarak); 
        if (newJarak == -1) {
            newJarak = 0;
        }

        clearScreen();

        printHeader("ENTRI BARU", 50);
        cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << endl;
        cout << FG_CYAN << "Konstelasi             " FG_PUTIH << ": " << FG_KUNING << newKonstelasi << endl;
        cout << FG_CYAN << "Status Observasi       " FG_PUTIH << ": " << FG_KUNING << newStatus << endl;
        cout << FG_CYAN << "Nama Objek             " FG_PUTIH << ": " << FG_KUNING << newObjek << endl;
        cout << FG_CYAN << "Jarak dari Bumi        " FG_PUTIH << ": " << FG_KUNING << newJarak << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Masukkan Tahun Ditemukan       " FG_PUTIH << ": "; 
        cout << FG_KUNING; cin >> newTahun; cout << RESET_WARNA;

        newTahun = errorHandling(newTahun);
        if (newTahun == -1) {
            newTahun = 0;
        }

        clearScreen();
        
        printHeader("ENTRI BARU", 50);
        cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << endl;
        cout << FG_CYAN << "Konstelasi             " FG_PUTIH << ": " << FG_KUNING << newKonstelasi << endl;
        cout << FG_CYAN << "Status Observasi       " FG_PUTIH << ": " << FG_KUNING << newStatus << endl;
        cout << FG_CYAN << "Nama Objek             " FG_PUTIH << ": " << FG_KUNING << newObjek << endl;
        cout << FG_CYAN << "Jarak dari Bumi        " FG_PUTIH << ": " << FG_KUNING << newJarak << endl;
        cout << FG_CYAN << "Tahun Ditemukan        " FG_PUTIH << ": " << FG_KUNING << newTahun << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Masukkan Magnitudo     " FG_PUTIH << ": "; 
        cout << FG_KUNING; cin >> newMagnitudo; cout << RESET_WARNA;
        
        newMagnitudo = errorHandling(newMagnitudo);
        if (newMagnitudo == -1) {
            newMagnitudo = 0;
        }

        clearScreen();
        printHeader("ENTRI BARU", 50);
        cout << FG_CYAN << "Klasifikasi Objek      " FG_PUTIH << ": " << FG_KUNING << newKlasifikasi << endl;
        cout << FG_CYAN << "Konstelasi             " FG_PUTIH << ": " << FG_KUNING << newKonstelasi << endl;
        cout << FG_CYAN << "Status Observasi       " FG_PUTIH << ": " << FG_KUNING << newStatus << endl;
        cout << FG_CYAN << "Nama Objek             " FG_PUTIH << ": " << FG_KUNING << newObjek << endl;
        cout << FG_CYAN << "Jarak dari Bumi        " FG_PUTIH << ": " << FG_KUNING << newJarak << endl;
        cout << FG_CYAN << "Tahun Ditemukan        " FG_PUTIH << ": " << FG_KUNING << newTahun << endl;
        cout << FG_CYAN << "Magnitudo              " FG_PUTIH << ": " << FG_KUNING << newMagnitudo << RESET_WARNA << endl;
        
        lanjut = true;

    } while (!lanjut); 

    toUpperString(newObjek);
    toUpperString(newKlasifikasi);
    toUpperString(newKonstelasi);
    toUpperString(newStatus);
    
    newEntri[jumlahEntri].entriID = uniqueEntri + 1;
    newEntri[jumlahEntri].namaObjek = newObjek;
    newEntri[jumlahEntri].klasifikasi = newKlasifikasi;
    newEntri[jumlahEntri].konstelasi = newKonstelasi;
    newEntri[jumlahEntri].jarakDariBumi = newJarak;
    newEntri[jumlahEntri].tahunPenemuan = newTahun;
    newEntri[jumlahEntri].statusObservasi = newStatus;
    newEntri[jumlahEntri].magnitudo = newMagnitudo;
    jumlahEntri++; uniqueEntri++; 
    
    printSeparator("-", 49);
    cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil ditambahkan" << RESET_WARNA << endl;
    printSeparator("-", 49);
    system("pause");
    return; 
}

// --- READ ---
// [1] Read Seluruh Entri
void lihatSeluruhEntri(BendaLangit entriTerdaftar[], int ukuran) {
    if (jumlahEntri == 0) {
        cout << FG_MERAH << "[!] Tidak ada Entri yang Tersimpan!" << RESET_WARNA << endl;
        printSeparator("-", 80);
        system("pause");
        return;
    }

    printHeader("DAFTAR SINGKAT ENTRI", 80);

    // Header tabel
    cout << FG_KUNING << left
         << setw(5)  << "ID"
         << setw(25) << "Nama Objek"
         << setw(15) << "Jarak"
         << setw(20) << "Tahun Penemuan"
         << setw(15) << "Magnitudo"
         << RESET_WARNA << endl;

    cout << FG_MAGENTA << string(80, '-') << RESET_WARNA << endl;

    // Isi tabel
    for (int i = 0; i < ukuran; i++) {
        if (i % 5 == 0 && i != 0) {
            cout << FG_MAGENTA << string(80, '-') << RESET_WARNA << endl;
        }

        cout << FG_CYAN << left
             << setw(5)  << entriTerdaftar[i].entriID
             << setw(25) << entriTerdaftar[i].namaObjek
             << setw(15) << entriTerdaftar[i].jarakDariBumi
             << setw(20) << entriTerdaftar[i].tahunPenemuan
             << setw(15) << entriTerdaftar[i].magnitudo
             << RESET_WARNA << endl;
    }
}

// [2] Read Entri Spesifik
void lihatSpesifik(BendaLangit entriTerdaftar[], int ukuran) {
    if (ukuran == 0) {
        cout << FG_MERAH << "[!] Data Entri kosong!" << RESET_WARNA << endl;
        printSeparator("-", 49);
        system("pause");
        return;
    }

    int idSpesifik;

    do {
        clearScreen();
        lihatSeluruhEntri(entriTerdaftar, ukuran);

        printSeparator("-", 79);
        cout << FG_CYAN << left
             << setw(5) << "0"
             << setw(25) << "Kembali"
             << RESET_WARNA << endl;

        printSeparator("-", 79);
        cout << FG_CYAN << "Masukkan ID untuk detail lengkap: "; 
        cout << FG_KUNING; cin >> idSpesifik; cout << RESET_WARNA;
        printSeparator("-", 79);

        if (cin.fail()) {
            cout << FG_MERAH << "[!] Input harus berupa angka (ID)!" << RESET_WARNA << endl;
            idSpesifik = errorHandling(-1);
            printSeparator("-", 79);
            system("pause");
            continue;
        }

        if (idSpesifik == 0) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
            printSeparator("-", 79);
            system("pause");
            return;
        }

        bool ditemukan = false;
        for (int i = 0; i < ukuran; i++) {
            if (entriTerdaftar[i].entriID == idSpesifik) {
                clearScreen();
                cout << FG_MAGENTA << "==========================================" << endl;
                cout << FG_KUNING << "      DETAIL LENGKAP OBJEK ASTRONOMI      " << endl;
                cout << FG_MAGENTA << "==========================================" << endl;
                cout << FG_CYAN << "ID Entri       " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].entriID << endl;
                cout << FG_CYAN << "Nama Objek     " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].namaObjek << endl;
                cout << FG_CYAN << "Klasifikasi    " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].klasifikasi << endl;
                cout << FG_CYAN << "Konstelasi     " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].konstelasi << endl;
                cout << FG_CYAN << "Jarak          " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].jarakDariBumi << endl;
                cout << FG_CYAN << "Tahun Temu     " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].tahunPenemuan << endl;
                cout << FG_CYAN << "Status         " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].statusObservasi << endl;
                cout << FG_CYAN << "Magnitudo      " FG_PUTIH << ": " << FG_KUNING << entriTerdaftar[i].magnitudo << endl;
                cout << FG_MAGENTA << "==========================================" << RESET_WARNA << endl;
                ditemukan = true;
                system("pause");
                break;
            }
        }
        if (!ditemukan) {
            cout << FG_MERAH << "[!] ID " << FG_KUNING << idSpesifik << FG_MERAH << " tidak ditemukan" << RESET_WARNA << endl;
            printSeparator("-", 79);
            system("pause");
        }
    
    } while (idSpesifik != 0);
}

// --- UPDATE ---
void perbaruiEntri(BendaLangit arr[], int ukuran) {
    int idCari;
    
    clearScreen();
    printHeader("PERBARUI ENTRI", 80);
    cout << "Entri-Entri yang terdaftar:" << endl;
    printSeparator("-", 79);
    lihatSeluruhEntri(arr, ukuran);
    
    printSeparator("-", 79);
    cout << FG_CYAN << left
             << setw(5) << "0"
             << setw(25) << "Kembali"
             << RESET_WARNA << endl;
    
    
    printSeparator("-", 79);
    cout << FG_CYAN << "Masukkan ID Entri yang ingin diperbarui: "; 
    cout << FG_KUNING; cin >> idCari; cout << RESET_WARNA;

    idCari = errorHandling(idCari);
    printSeparator("-", 79);

    if (idCari == -1 || idCari < 0) {
        cout << FG_MERAH << "[!] Input ID tidak valid!" << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return; 
    }

    if (idCari == 0) {
        cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return; 
    }

    int indeks = -1;
    for (int i = 0; i < ukuran; i++) {
        if ((arr+i)->entriID == idCari) {
            indeks = i;
            break;
        }
    }
    
    if (indeks == -1) {
        cout << FG_MERAH << "[!] Entri dengan ID tersebut tidak ditemukan!" << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return;
    }
    
    int pilihanField;
    do {
        clearScreen();
        cout << FG_CYAN << "Entri ditemukan: " << FG_KUNING <<(arr+indeks)->namaObjek << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Pilih field yang ingin diperbarui" << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Nama Objek       " << FG_PUTIH << ": " << (arr+indeks)->namaObjek << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Klasifikasi      " << FG_PUTIH << ": " << (arr+indeks)->klasifikasi << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "03" << FG_HIJAU << "]" << FG_CYAN << " Konstelasi       " << FG_PUTIH << ": " << (arr+indeks)->konstelasi << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "04" << FG_HIJAU << "]" << FG_CYAN << " Jarak dari Bumi  " << FG_PUTIH << ": " << (arr+indeks)->jarakDariBumi << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "05" << FG_HIJAU << "]" << FG_CYAN << " Tahun Penemuan   " << FG_PUTIH << ": " << (arr+indeks)->tahunPenemuan << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "06" << FG_HIJAU << "]" << FG_CYAN << " Status Observasi " << FG_PUTIH << ": " << (arr+indeks)->statusObservasi << endl;
        cout << FG_HIJAU << "[" << FG_PUTIH << "07" << FG_HIJAU << "]" << FG_CYAN << " Magnitudo        " << FG_PUTIH << ": " << (arr+indeks)->magnitudo << RESET_WARNA << endl;
        
        printSeparator("-", 49);
        cout << FG_HIJAU << "[" << FG_PUTIH << "00" << FG_HIJAU << "]" << FG_CYAN << " Kembali" << RESET_WARNA << endl;
        printSeparator("-", 49);

        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanField;
        printSeparator("-", 49);

        pilihanField = errorHandling(pilihanField);
        cin.ignore();
        
        if (pilihanField == -1) {
            cout << "=> Pilihan tidak valid!" << endl;
            system("pause");
            continue;
        }
        
        string nilaiBaru;
        switch(pilihanField) {
            case 0: 
                cout << "=> Kembali" << endl;
                break;
            case 1: {
                cout << FG_CYAN << "Masukkan Nama Objek baru: " << RESET_WARNA;
                cout << FG_KUNING; getline(cin, nilaiBaru); cout << RESET_WARNA;
                printSeparator("-", 49);

                if (nilaiBaru.empty()) {
                    cout << FG_MERAH << "[!] Nama objek tidak boleh kosong!" << RESET_WARNA << endl;
                    
                    printSeparator("-", 49);
                    system("pause");
                    break;
                }
                toUpperString(nilaiBaru);
                (arr+indeks)->namaObjek = nilaiBaru;
                
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                printSeparator("-", 49);
                system("pause");
                break;
            }
                
            case 2: {
                int pilihanUpdate; 
                bool selesaiUpdate = false;

                do {
                    clearScreen();
                    string updateKlasifikasi;

                    printHeader("KLASIFIKASI OBJEK", 50); 
                    cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Klasifikasi yang Sudah Ada" << endl;
                    cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Buat Klasifikasi Baru" << RESET_WARNA << endl;
                    
                    printSeparator("-", 49);
                    cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                    cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanUpdate;

                    pilihanUpdate = errorHandling(pilihanUpdate);

                    if (pilihanUpdate == 1) {
                        string kategori[100]; 
                        int ukuranKategori = 0; 
                        int pilih; 

                        clearScreen();

                        cout << FG_KUNING << "[KLASIFIKASI YANG SUDAH ADA]" << RESET_WARNA << endl; 
                        printSeparator("-", 49);
                        getKategori(entri, ukuran, "KLASIFIKASI", kategori, ukuranKategori); 
                        
                        for (int i = 0; i < ukuranKategori; i++) {
                            cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
                        }

                        printSeparator("-", 49);
                        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
                        printSeparator("-", 49);

                        pilih = errorHandling(pilih); 

                        if (pilih > 0 && pilih <= ukuranKategori) {
                            arr[indeks].klasifikasi = kategori[pilih - 1];
                            selesaiUpdate = true;
                            cin.ignore();
                        }
                        else {
                            cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << endl;
                            printSeparator("-", 49);
                            system("pause"); 
                        }
                    }
                    else if (pilihanUpdate == 2) {
                        clearScreen();
                        cin.ignore(); 

                        cout << FG_KUNING << "[BUAT KLASIFIKASI BARU]" << RESET_WARNA << endl; 
                        printSeparator("-", 49);
                        cout << FG_CYAN <<"Masukkan Klasifikasi            " FG_PUTIH << ": "; 
                        cout << FG_KUNING; getline(cin, updateKlasifikasi); cout << RESET_WARNA;
                        printSeparator("-", 49);

                        if (updateKlasifikasi.length() == 0) {
                            cout << FG_MERAH << "[!] Klasfikasi Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                            printSeparator("-", 49);
                            system("pause"); 
                            continue; 
                        }     
                        else {
                            selesaiUpdate = true;
                            toUpperString(updateKlasifikasi);
                            cout << FG_CYAN << "Klasifikasi Baru " << FG_KUNING << updateKlasifikasi << FG_CYAN << " Berhasil Ditambahkan!" << RESET_WARNA << endl;
                            arr[indeks].klasifikasi = updateKlasifikasi;

                            printSeparator("-", 49);
                            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                            printSeparator("-", 49);
                            system("pause");
                        }     
                    }

                } while (!selesaiUpdate);

                break;
            }
            case 3: {
                int pilihanUpdate; 
                bool selesaiUpdate = false;

                do {
                    clearScreen();
                    string update;

                    printHeader("KONSTELASI", 50); 
                    cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Konstelasi yang Sudah Ada" << endl;
                    cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Buat Konstelasi Baru" << RESET_WARNA << endl;

                    printSeparator("-", 49); 
                    cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                    cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanUpdate;
                    
                    pilihanUpdate = errorHandling(pilihanUpdate);

                    if (pilihanUpdate == 1) {
                        string kategori[100]; 
                        int ukuranKategori = 0; 
                        int pilih; 

                        clearScreen();

                        cout << FG_KUNING << "[KONSTELASI YANG SUDAH ADA]" << RESET_WARNA << endl; 
                        printSeparator("-", 49);
                        getKategori(entri, ukuran, "KONSTELASI", kategori, ukuranKategori); 
                        
                        for (int i = 0; i < ukuranKategori; i++) {
                            cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
                        }

                        printSeparator("-", 49);
                        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
                        printSeparator("-", 49);

                        pilih = errorHandling(pilih); 

                        if (pilih > 0 && pilih <= ukuranKategori) {
                            arr[indeks].konstelasi = kategori[pilih - 1];
                            selesaiUpdate = true;
                            cin.ignore();
                        }
                        else {
                            cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << RESET_WARNA << endl;
                            printSeparator("-", 49);
                            system("pause"); 
                        }
                    }
                    else if (pilihanUpdate == 2) {
                        cin.ignore(); 
                        clearScreen();

                        cout << FG_KUNING << "[BUAT KONSTELASI BARU]" << RESET_WARNA << endl; 
                        printSeparator("-", 49);
                        cout << FG_CYAN <<"Masukkan Konstelasi            " FG_PUTIH << ": "; 
                        cout << FG_KUNING; getline(cin, update); cout << RESET_WARNA;
                        printSeparator("-", 49);

                        if (update.length() == 0) {
                            cout << FG_MERAH << "[!] Konstelasi Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                            printSeparator("-", 49);
                            system("pause"); 
                            continue; 
                        }     
                        else {
                            selesaiUpdate = true;
                            toUpperString(update);
                            cout << FG_CYAN << "Konstelasi Baru " << FG_KUNING << update << FG_CYAN << " Berhasil Ditambahkan!" << RESET_WARNA << endl;
                            arr[indeks].konstelasi = update;

                            printSeparator("-", 49);
                            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                            printSeparator("-", 49);
                            system("pause");
                        }     
                    }

                } while (!selesaiUpdate);

                break;
            }
                
            case 4: {
                double jarakBaru;
                
                cout << FG_CYAN << "Masukkan Jarak Dari Bumi baru: ";
                cout << FG_KUNING; cin >> jarakBaru; cout << RESET_WARNA;
                printSeparator("-", 49);

                if (cin.fail() || jarakBaru < 0) {
                    cout << FG_MERAH << "[!] Input jarak tidak valid!" << RESET_WARNA << endl;
                    cout << FG_MERAH << "[!] Masukkan Angka Positif!" << RESET_WARNA << endl;
                    cin.clear();
                    while (cin.peek() != '\n') cin.ignore();
                    printSeparator("-", 49);
                    system("pause");
                    break;
                }
                
                while (cin.peek() != '\n') cin.ignore();
                
                (arr+indeks)->jarakDariBumi = jarakBaru;
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                printSeparator("-", 49);
                system("pause");
                break;
            }
            case 5: {
                int newTahun;

                cout << FG_CYAN << "Masukkan Tahun Penemuan baru: " << RESET_WARNA;
                cout << FG_KUNING; cin >> newTahun; cout << RESET_WARNA;
                newTahun = errorHandling(newTahun);
                
                if (newTahun == -1 || newTahun < -10000 || newTahun > 2100) {
                    cout << FG_MERAH << "[!] Tahun tidak valid!" << RESET_WARNA << endl;
                    printSeparator("-", 49);
                    system("pause");
                    break;
                }
                
                (arr+indeks)->tahunPenemuan = newTahun;
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                printSeparator("-", 49);
                system("pause");
                break;
            }

            case 6: {
                int pilihanUpdate; 
                bool selesaiUpdate = false;

                do {
                    clearScreen();
                    string update;

                    printHeader("STATUS OBSERVASI", 50); 
                    cout << FG_HIJAU << "[" << FG_PUTIH << "01" << FG_HIJAU << "]" << FG_CYAN << " Pilih Status yang Sudah Ada" << endl;
                    cout << FG_HIJAU << "[" << FG_PUTIH << "02" << FG_HIJAU << "]" << FG_CYAN << " Buat Status Baru" << RESET_WARNA << endl; 

                    printSeparator("-", 49); 
                    cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                    cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilihanUpdate;

                    pilihanUpdate = errorHandling(pilihanUpdate);

                    if (pilihanUpdate == 1) {
                        string kategori[100]; 
                        int ukuranKategori = 0; 
                        int pilih; 

                        clearScreen();

                        cout << FG_KUNING << "[STATUS YANG SUDAH ADA]" << RESET_WARNA << endl; 
                        printSeparator("-", 49);
                        getKategori(entri, ukuran, "STATUS OBSERVASI", kategori, ukuranKategori); 
                        
                        for (int i = 0; i < ukuranKategori; i++) {
                            cout << FG_HIJAU << "[" << FG_PUTIH << "0" << i + 1 << FG_HIJAU << "] " << FG_CYAN << kategori[i] << endl;
                        }

                        printSeparator("-", 49);
                        cout << FG_CYAN << "Masukkan Pilihan Anda" << RESET_WARNA << endl; 
                        cout << FG_HIJAU << "[" << FG_PUTIH << ">" << FG_HIJAU << "] " << FG_KUNING << RESET_WARNA; cin >> pilih;
                        printSeparator("-", 49);

                        pilih = errorHandling(pilih); 

                        if (pilih > 0 && pilih <= ukuranKategori) {
                            arr[indeks].statusObservasi = kategori[pilih - 1];
                            selesaiUpdate = true;
                            cin.ignore();
                        }
                        else {
                            cout << FG_MERAH << "[!] Pilihan Tidak Valid!" << RESET_WARNA << endl;
                            printSeparator("-", 49); 
                            system("pause");
                        }
                    }
                    else if (pilihanUpdate == 2) {
                        cin.ignore(); 
                        clearScreen();

                        cout << FG_KUNING << "[BUAT STATUS BARU]" << RESET_WARNA << endl; 
                        printSeparator("-", 49);
                        cout << FG_CYAN <<"Masukkan Status Observasi            " FG_PUTIH << ": "; 
                        cout << FG_KUNING; getline(cin, update); cout << RESET_WARNA;
                        printSeparator("-", 49);

                        if (update.length() == 0) {
                            cout << FG_MERAH << "[!] Status Observasi Tidak Boleh Kosong!" << RESET_WARNA << endl; 
                            printSeparator("-", 49);
                            system("pause"); 
                            continue; 
                        }     
                        else {
                            selesaiUpdate = true;
                            toUpperString(update);
                            cout << FG_CYAN << "Status Baru " << FG_KUNING << update << FG_CYAN << " Berhasil Ditambahkan!" << RESET_WARNA << endl;
                            arr[indeks].statusObservasi = update;
                            
                            printSeparator("-", 49);
                            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                            printSeparator("-", 49);
                            system("pause");
                        }     
                    }

                } while (!selesaiUpdate);

                break;
            }
                
            case 7: {
                float magnitudoBaru;
                
                cout << FG_CYAN << "Masukkan Magnitudo baru: " << RESET_WARNA;
                cout << FG_KUNING; cin >> magnitudoBaru; cout << RESET_WARNA;
                
                if (cin.fail()) {
                    cout << FG_MERAH << "[!] Input Magnitudo Tidak Valid! Masukkan Angka!" << RESET_WARNA << endl;
                    
                    cin.clear();
                    while (cin.peek() != '\n') cin.ignore();
                    
                    printSeparator("-", 49);
                    system("pause");
                    break;
                }
                
                while (cin.peek() != '\n') cin.ignore();
                (arr+indeks)->magnitudo = magnitudoBaru;
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Entri Berhasil Diperbarui" << RESET_WARNA << endl;
                printSeparator("-", 49); 
                system("pause");
                break;
            }
                
            default:
                cout << FG_MERAH << "[!] Pilihan tidak valid!" << RESET_WARNA << endl;
                printSeparator("-", 49);
                system("pause");
        }
        
    } while (pilihanField != 0); 
}

// --- DELETE ---
void hapusEntri() {
    clearScreen();
    if (jumlahEntri == 0) {
        cout << FG_MERAH << "[!] Tidak ada data untuk dihapus" << RESET_WARNA << endl;
        printSeparator("-", 79);
        system("pause");
        return;
    }
    
    int idHapus;
    bool selesai = false;

    do {
        clearScreen();
        printHeader("HAPUS ENTRI", 80);
        cout << FG_CYAN << "Entri-Entri yang Terdaftar" << RESET_WARNA << endl;  
        printSeparator("-", 79);
        lihatSeluruhEntri(entri, jumlahEntri);
        
        printSeparator("-", 79);
        cout << FG_CYAN << left
             << setw(5) << "0"
             << setw(25) << "Kembali"
             << RESET_WARNA << endl;

        printSeparator("-", 79);

        cout << FG_CYAN << "Masukkan ID Entri yang ingin dihapus: "; 
        cout << FG_KUNING; cin >> idHapus; cout << RESET_WARNA;
        printSeparator("-", 79);
        
        if (cin.fail()) {
            cout << FG_MERAH << "[!] Input harus berupa angka (ID)!" << RESET_WARNA << endl;
            idHapus = errorHandling(-1);
            printSeparator("-", 79);
            system("pause");
            continue;
        }
        
        if (idHapus == 0) {
            cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Kembali ke Menu Sebelumnya" << RESET_WARNA << endl;
            printSeparator("-", 79);
            system("pause");
            return; 
        }

        int idx = -1;
        for (int i = 0; i < jumlahEntri; i++) {
            if (entri[i].entriID == idHapus) { 
                idx = i;
                break; 
            }
        }
        if (idx != -1) {
        char konfirmasi;
            cout << FG_CYAN << "Yakin hapus " << FG_KUNING << entri[idx].namaObjek << FG_CYAN << " ? (y/n): "; 
            cin >> konfirmasi;
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_KUNING << entri[idx].namaObjek << FG_CYAN << " Berhasil Dihapus!" << RESET_WARNA << endl;
                for (int j = idx; j < jumlahEntri - 1; j++) entri[j] = entri[j + 1];
                jumlahEntri--;
                selesai = true;

                printSeparator("-", 79);
                system("pause");
            } 
            else if (konfirmasi == 'n' || konfirmasi == 'N') {
                cout << FG_HIJAU << "[" << FG_PUTIH << "~" << FG_HIJAU << "] " << FG_CYAN << "Tidak Jadi Menghapus " <<  FG_KUNING << entri[idx].namaObjek << RESET_WARNA << endl;

                printSeparator("-", 79);
                system("pause");
            }
            else {
                cout << FG_MERAH << "[!] Pilihan Tidak Valid! Tidak Jadi Menghapus " << FG_KUNING << entri[idx].namaObjek << RESET_WARNA << endl;
                cin.clear();
                while (cin.get() != '\n');
                
                printSeparator("-", 79);
                system("pause");
            }
        }
        
        else { 
            cout << FG_MERAH << "[!] ID " << FG_KUNING << idHapus << FG_MERAH << " tidak ditemukan!" << endl;
            printSeparator("-", 79);
            system("pause");
        }
    } while (!selesai);
}