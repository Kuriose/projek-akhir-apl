#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_entri.h"

#include <iostream>
using namespace std;

// --- CREATE
void tambahEntri(BendaLangit newEntri[], int &ukuran) {
    int pilihan; 
     
    if (ukuran >= MAXENTRI) {
        cout << "=> Data Entri sudah Penuh!" << endl; 
        system("pause");
        return; 
    }

    cout << "\n=== BUAT ENTRI BARU ===" << endl; 
    string newObjek, newKlasifikasi, newKonstelasi, newJarak, newTahun, newStatus, newMagnitudo;

    cin.ignore(); 
    cout << "Masukkan Nama Objek: "; getline(cin, newObjek); 
    cout << "Masukkan Klasifikasi Objek: "; getline(cin, newKlasifikasi); 
    cout << "Masukkan Konstelasi: "; getline(cin, newKonstelasi); 
    cout << "Masukkan Jarak Dari Bumi: "; getline(cin, newJarak); 
    cout << "Masukkan Tahun Ditemukan: "; getline(cin, newJarak); 
    cout << "Masukkan Status Observasi: "; getline(cin, newStatus); 
    cout << "Masukkan Magnitudo Objek: "; getline(cin, newMagnitudo); 

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

    cout << "\n=> Entri Berhasil ditambahkan" << endl; 
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

    cout << "\n=== DAFTAR SINGKAT ENTRI ===" << endl; 
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

    // system("pause");
}

// [2] Read Entri Spesifik
void lihatSpesifik(BendaLangit entriTerdaftar[], int ukuran) {
    if (ukuran == 0) {
        cout << "\n=> Data Entri kosong!" << endl;
        system("pause");
        return;
    }

    lihatSeluruhEntri(entriTerdaftar, ukuran);

    int idSpesifik;
    cout << "\nMasukkan ID untuk detail lengkap: ";
    cin >> idSpesifik;

    bool ditemukan = false;
    for (int i = 0; i < ukuran; i++) {
        if (entriTerdaftar[i].entriID == idSpesifik) {
            cout << "\n==========================================" << endl;
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
            break;
        }
    }
    if (!ditemukan) {
        cout << "\n=> ID " << idSpesifik << " tidak ditemukan" << endl;
    }
    
    system("pause");
}

// --- UPDATE ---
void perbaruiEntri(BendaLangit arr[], int ukuran) {
    int idCari;
    cout << "\n=== PERBARUI ENTRI ===" << endl;
    lihatSeluruhEntri(arr, ukuran);
    cout << "Masukkan ID Entri yang ingin diperbarui: ";
    cin >> idCari;
    errorHandling(idCari);
    
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
        cout << "\nEntri ditemukan: " << (arr+indeks)->namaObjek << endl;
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
                cout << "Masukkan Jarak Dari Bumi baru: ";
                getline(cin, nilaiBaru);
                (arr+indeks)->jarakDariBumi = nilaiBaru;
                cout << "=> Entri berhasil diperbarui!" << endl;
                system("pause");
                
                break;
            case 5:
                cout << "Masukkan Tahun Penemuan baru: ";
                getline(cin, nilaiBaru);
                (arr+indeks)->tahunPenemuan = nilaiBaru;
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
                cout << "Masukkan Magnitudo baru: ";
                getline(cin, nilaiBaru);
                (arr+indeks)->magnitudo = nilaiBaru;
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
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada data" << endl;
        system("pause");
        return;
    }
    lihatSeluruhEntri(entri, jumlahEntri);
    int idHapus;
    cout << "Masukkan ID yang ingin dihapus: "; 
    cin >> idHapus;
    int idx = -1;
    for (int i = 0; i < jumlahEntri; i++) {
        if (entri[i].entriID == idHapus) { 
            idx = i;
            break; }
    }
    if (idx != -1) {
        char konfirmasi;
        cout << "Yakin hapus " << entri[idx].namaObjek << "? (y/n): "; 
        cin >> konfirmasi;
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            for (int j = idx; j < jumlahEntri - 1; j++) entri[j] = entri[j + 1];
            jumlahEntri--;
            cout << "=> " << entri[idx].namaObjek<< " Berhasil dihapus!" << endl;
        }
    } else cout << "=> ID tidak ditemukan!" << endl;
    system("pause");
}

