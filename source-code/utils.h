#ifndef UTILS_H
#define UTILS_H 

#include <string>
// #include <iostream>
// using namespace std;

int errorHandling(int pilihan); 
void clearScreen();
void toUpperString(std::string &str); 
void printHeader(std::string teks, int panjangTotal);
void printSeparator(std::string teks, int jumlahKarakter);

#endif