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
        {1, "SIRIUS", "BINTANG", "CANIS MAJOR", 8.6, 0, "Selesai Pengamatan", -1.46}, 
        {2, "BETELGEUSE", "BINTANG", "ORION", 700, 0, "Dalam Pengamatan", 0.42}, 
        {3, "JUPITER", "PLANET", "TATA SURYA", 0.00008, 0, "Selesai Pengamatan", -2.94},
        {4, "ANDROMEDA", "GALAKSI", "ANDROMEDA", 2.537, 964, "Dalam Pengamatan", 3.44},
        {5, "CERES", "ASTEROID", "N/A", 0.00028, 1801, "Selesai Pengamatan", 6.64},
        {6, "CRAB NEBULA", "NEBULA", "TAURUS", 6.500, 1054, "Dalam Pengamatan", 8.4},
        {7, "PROXIMA CENTAURI", "BINTANG", "CENTAURUS", 4.24, 1915, "Selesai Pengamatan", 11.13},
        {8, "SATURNUS", "PLAENT", "TATA SURYA", 0.00015, 0, "Selesai Pengamatan", 0.46},
        {9, "PILLAR OF CREATION", "NEBULA", "SERPENS", 6.750, 1920, "Pengamatan Ditunda", 0},
        {10, "VEGA", "BINTANG", "LYRA", 25, 0, "Selesai Pengamatan", 0.03}
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