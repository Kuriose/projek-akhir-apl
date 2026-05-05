#include "types.h"
#include "data.h"

BendaLangit entri[MAXENTRI]; 
Pengguna akun[MAXPENGGUNA]; 
int jumlahEntri = 10; 
int jumlahPengguna = 3; 
int uniqueEntri = jumlahEntri; 
int uniqueUser = jumlahPengguna; 

void entriAwal(BendaLangit arr[], int &ukuran) {
    BendaLangit temp[] {
        {1, "SIRIUS", "Bintang", "Canis Major", "8.6 LY", "Zaman Kuno", "Selesai Pengamatan", "-1.46"}, 
        {2, "BETELGEUSE", "Bintang", "Orion", "700 LY", "Zaman Kuno", "Dalam Pengamatan", "0.42"}, 
        {3, "JUPITER", "Planet", "N/A (Tata Surya)", "0.00008 LY", "Zaman Kuno", "Selesai Pengamatan", "-2.94"},
        {4, "ANDROMEDA", "Galaksi", "Andromeda", "2.537 Juta LY", "964 M", "Dalam Pengamatan", "3.44"},
        {5, "CERES", "Asteroid", "N/A (Sabuk Asteroid)", "0.00028 LY", "1801", "Selesai Pengamatan", "6.64"},
        {6, "CRAB NEBULA", "Nebula", "Taurus", "6,500 LY", "1054", "Dalam Pengamatan", "8.4"},
        {7, "PROXIMA CENTAURI", "Bintang", "Centaurus", "4.24 LY", "1915", "Selesai Pengamatan", "11.13"},
        {8, "SATURNUS", "Planet", "N/A (Tata Surya)", "0.00015 LY", "Zaman Kuno", "Selesai Pengamatan", "0.46"},
        {9, "PILLAR OF CREATION", "Nebula", "Serpens", "6,500 - 7,000 LY", "1920", "Pengamatan Ditunda", "N/A"},
        {10, "VEGA", "Bintang", "Lyra", "25 LY", "Zaman Kuno", "Selesai Pengamatan", "0.03"}
    }; 

    int n = sizeof(temp) / sizeof(temp[0]); 

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    ukuran = n; 
}

void penggunaAwal(Pengguna arr[], int &ukuran) {
    Pengguna temp[] = {
        {1, "Yoga", "017", true}, 
        {2, "Pirlo", "008", false}, 
        {3, "Nur", "018", false}
    };

    int n = sizeof(temp) / sizeof(temp[0]); 

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i]; 
    }

    ukuran = n; 
}