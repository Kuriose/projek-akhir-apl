#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_entri.h"

#include <iostream>
// #include <iomanip> // Untuk std::fixed dan std::setprecision
using namespace std;

// --- CREATE
void tambahEntri(BendaLangit newEntri[], int &ukuran) {
    int pilihan; 
     
    if (ukuran >= MAXENTRI) {
        cout << "=> Data Entri sudah Penuh!" << endl; 
        system("pause");
        return; 
    }

    clearScreen();
    printHeader("BUAT ENTRI", 50);
    
    double newJarak;
    float newMagnitudo;
    int newTahun;
    string newObjek, newKlasifikasi, newKonstelasi, newStatus;

    cin.ignore(); 
    cout << "Masukkan Nama Objek            : "; getline(cin, newObjek); 
    cout << "Masukkan Klasifikasi Objek     : "; getline(cin, newKlasifikasi); 
    cout << "Masukkan Konstelasi            : "; getline(cin, newKonstelasi); 
    cout << "Masukkan Jarak Dari Bumi       : "; cin >> newJarak; 
    
    cin.ignore(); 
    cout << "Masukkan Tahun Ditemukan       : "; cin >> newTahun; 
    
    cin.ignore();
    cout << "Masukkan Status Observasi      : "; getline(cin, newStatus); 
    cout << "Masukkan Magnitudo Objek       : "; cin >> newMagnitudo; 

    toUpperString(newObjek);

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
    cout << "=> Entri Berhasil ditambahkan" << endl; 
    system("pause");
    return; 
}

// --- READ ---
// [1] Read Seluruh Entri
void lihatSeluruhEntri(BendaLangit entriTerdaftar[], int ukuran) {
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada Entri yang Tersimpan!" << endl; 
        system("pause"); 
        return; 
    }

    // clearScreen();
    // std::cout << std::fixed << std::setprecision(5);
    // cout << "\n=== DAFTAR SINGKAT ENTRI ===" << endl; 
    
    printHeader("DAFTAR SINGKAT ENTRI", 50);
    cout << "ID | Nama Objek | Jarak | Tahun Penemuan | Magnitudo" << endl; 
    for (int i = 0; i < ukuran; i++) {
        if (i % 5 == 0 && i != 0) {
            cout << "--------------------------------------------------------------------------" << endl;
        }

        cout << entri[i].entriID
            << " | " << entri[i].namaObjek
            << " | " << entri[i].jarakDariBumi
            << " | " << entri[i].tahunPenemuan
            << " | " << entri[i].magnitudo
            << endl; 
    }
}

// [2] Read Entri Spesifik
void lihatSpesifik(BendaLangit entriTerdaftar[], int ukuran) {
    if (ukuran == 0) {
        cout << "=> Data Entri kosong!" << endl;
        system("pause");
        return;
    }

    int idSpesifik;

    do {
        clearScreen();
        lihatSeluruhEntri(entriTerdaftar, ukuran);

        printSeparator("-", 49);
        cout << "0. Kembali" << endl;
        printSeparator("-", 49);
        cout << "Masukkan ID untuk detail lengkap: ";
        cin >> idSpesifik;
        printSeparator("-", 49);

        if (cin.fail()) {
            cout << "\n=> Input harus berupa angka (ID)!" << endl;
            idSpesifik = errorHandling(-1);
            system("pause");
            continue;
        }

        if (idSpesifik == 0) {
            cout << "=> Kembali ke Menu Sebelumnya" << endl;
            system("pause");
            return;
        }

        bool ditemukan = false;
        for (int i = 0; i < ukuran; i++) {
            if (entriTerdaftar[i].entriID == idSpesifik) {
                clearScreen();
                cout << "==========================================" << endl;
                cout << "      DETAIL LENGKAP OBJEK ASTRONOMI      " << endl;
                cout << "==========================================" << endl;
                cout << "ID Entri       : " << entriTerdaftar[i].entriID << endl;
                cout << "Nama Objek     : " << entriTerdaftar[i].namaObjek << endl;
                cout << "Klasifikasi    : " << entriTerdaftar[i].klasifikasi << endl;
                cout << "Konstelasi     : " << entriTerdaftar[i].konstelasi << endl;
                cout << "Jarak          : " << entriTerdaftar[i].jarakDariBumi << endl;
                cout << "Tahun Temu     : " << entriTerdaftar[i].tahunPenemuan << endl;
                cout << "Status         : " << entriTerdaftar[i].statusObservasi << endl;
                cout << "Magnitudo      : " << entriTerdaftar[i].magnitudo << endl;
                cout << "==========================================" << endl;
                ditemukan = true;
                system("pause");
                break;
            }
        }
        if (!ditemukan) {
            cout << "=> ID " << idSpesifik << " tidak ditemukan" << endl;
            system("pause");
        }
    
    } while (idSpesifik != 0);
}

// --- UPDATE ---
void perbaruiEntri(BendaLangit arr[], int ukuran) {
    int idCari;
    
    clearScreen();
    printHeader("PERBARUI ENTRI", 50);
    cout << "Menampilkan Daftar Singkat Entri" << endl;
    lihatSeluruhEntri(arr, ukuran);
    
    printSeparator("-", 49);
    cout << "0. Kembali" << endl;
    printSeparator("-", 49);

    cout << "Masukkan ID Entri yang ingin diperbarui: ";
    cin >> idCari;
    errorHandling(idCari);
    printSeparator("-", 49);

    if (idCari == 0) {
        cout << "=> Kembali ke Menu Sebelumnya" << endl;
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
        cout << "=> Entri dengan ID tersebut tidak ditemukan!" << endl;
        system("pause");
        return;
    }
    
    int pilihanField;
    do {
        clearScreen();
        cout << "Entri ditemukan: " << (arr+indeks)->namaObjek << endl;
        cout << "Pilih field yang ingin diperbarui:" << endl;
        cout << "1. Nama Objek" << endl;
        cout << "2. Klasifikasi" << endl;
        cout << "3. Konstelasi" << endl;
        cout << "4. Jarak Dari Bumi" << endl;
        cout << "5. Tahun Penemuan" << endl;
        cout << "6. Status Observasi" << endl;
        cout << "7. Magnitudo" << endl;
        cout << endl; 

        cout << "0. Kembali" << endl; 

        cout << "Masukkan pilihan: ";
        cin >> pilihanField;
        errorHandling(pilihanField);
        cin.ignore();
        
        string nilaiBaru;
        switch(pilihanField) {
            case 0: 
                cout << "=> Kembali" << endl;
                break;
            case 1:
                cout << "Masukkan Nama Objek baru: ";
                getline(cin, nilaiBaru);

                toUpperString(nilaiBaru);

                (arr+indeks)->namaObjek = nilaiBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");

                break;
            case 2:
                cout << "Masukkan Klasifikasi baru: ";
                getline(cin, nilaiBaru);
                (arr+indeks)->klasifikasi = nilaiBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");
                
                break;
            case 3:
                cout << "Masukkan Konstelasi baru: ";
                getline(cin, nilaiBaru);
                (arr+indeks)->konstelasi = nilaiBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");
                
                break;
            case 4:
                double jarakBaru;
                cout << "Masukkan Jarak Dari Bumi baru: "; cin >> jarakBaru;
                (arr+indeks)->jarakDariBumi = jarakBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");
                
                break;
            case 5:
                int newTahun;
                cout << "Masukkan Tahun Penemuan baru: ";
                cin >> newTahun;
                (arr+indeks)->tahunPenemuan = newTahun;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");
                
                break;
            case 6:
                cout << "Masukkan Status Observasi baru: ";
                getline(cin, nilaiBaru);
                (arr+indeks)->statusObservasi = nilaiBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");

                break;
            case 7:
                float magnitudoBaru;
                cout << "Masukkan Magnitudo baru: "; cin >> magnitudoBaru;
                (arr+indeks)->magnitudo = magnitudoBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");

                break;
            default:
                cout << "=> Pilihan tidak valid!" << endl;
                system("pause");
        }
        
    } while (pilihanField != 0); 

}

// --- DELETE ---
void hapusEntri() {
    clearScreen();
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada data untuk dihapus" << endl;
        system("pause");
        return;
    }
    
    int idHapus;
    bool selesai = false;

    do {
        printHeader("HAPUS ENTRI", 50);
        cout << "Menghapus Entri" << endl;  
        lihatSeluruhEntri(entri, jumlahEntri);
        
        printSeparator("-", 49);
        cout << "0. Kembali" << endl;
        printSeparator("-", 49);

        cout << "Masukkan ID yang ingin dihapus: "; 
        cin >> idHapus;
        printSeparator("-", 49);
        
        if (cin.fail()) {
            cout << "\n=> Input harus berupa angka (ID)!" << endl;
            idHapus = errorHandling(-1);
            system("pause");
            continue;
        }
        
        if (idHapus == 0) {
            cout << "=> Kembali ke Menu Sebelumnya" << endl;
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
            cout << "Yakin hapus " << entri[idx].namaObjek << "? (y/n): "; 
            cin >> konfirmasi;
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                cout << "=> " << entri[idx].namaObjek<< " Berhasil dihapus!" << endl;
                for (int j = idx; j < jumlahEntri - 1; j++) entri[j] = entri[j + 1];
                jumlahEntri--;
                selesai = true;
                system("pause");
            } 
            else if (konfirmasi == 'n' || konfirmasi == 'N') {
                cout << "=> Tidak Jadi Menghapus " << entri[idx].namaObjek << endl; 
                system("pause");
            }
            else {
                cout << "=> Pilihan Tidak Valid! Tidak Jadi Menghapus " << entri[idx].namaObjek << endl;
                cin.clear();
                while (cin.get() != '\n');
                system("pause");
            }
        }
        
        else { 
            cout << "=> ID " << idHapus << "tidak ditemukan!" << endl;
            system("pause");
        }
    } while (!selesai);
}