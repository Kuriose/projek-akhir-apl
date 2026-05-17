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

int inputAngka(const std::string &prompt);
std::string inputString(const std::string &prompt, int minLength = 1);
char inputKarakter(const std::string &prompt, const std::string &validKarakter);

#endif