#ifndef UTILS_H
#define UTILS_H 

#include <string>
// #include <iostream>
// using namespace std;

#define RESET_WARNA "\033[0m"
#define FG_HITAM "\033[38;2;0;0;0m"
#define FG_MERAH "\033[31m"
#define FG_HIJAU "\033[32m"
#define FG_KUNING "\033[33m"
#define FG_PUTIH "\033[37m"
#define FG_BIRU "\033[34m"
#define FG_CYAN "\033[96m"
#define FG_MAGENTA "\033[95m"

int errorHandling(int pilihan); 
void clearScreen();
void toUpperString(std::string &str); 
void printHeader(std::string teks, int panjangTotal);
void printSeparator(std::string teks, int jumlahKarakter);

int inputAngka(const std::string &prompt);
std::string inputString(const std::string &prompt, int minLength = 1);
char inputKarakter(const std::string &prompt, const std::string &validKarakter);
void getKategori(BendaLangit arr[], int &ukuran, std::string kunci, std::string kategori[], int &ukuranKategori);

#endif