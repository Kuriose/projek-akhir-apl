#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>

struct BendaLangit {
    int entriID; 
    std::string namaObjek; 
    std::string klasifikasi; // Bintang, Planet, Asteroid, Nebula
    std::string konstelasi; // Objek berada di konstelasi mana
    double jarakDariBumi; // Jarak dari Bumi (dalam Light-Year)
    int tahunPenemuan; // Tahun Penemuan Benda Langit
    std::string statusObservasi; // "Dalam Pengamatan", "Selesai Pengamatan", "Pengamatan Ditunda"
    float magnitudo; // Cahaya yang dipancarkan oleh Benda Langit
};

struct Pengguna {
    int userID; 
    std::string username; 
    std::string password; 
    bool isAdmin;
};

const int MAXENTRI = 100; 
const int MAXPENGGUNA = 100;

#endif