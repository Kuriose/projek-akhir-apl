#ifndef SORT_SEARCH_H
#define SORT_SEARCH_H

#include <iostream>
using namespace std;

void urutkanBerdasarkanJarak(BendaLangit arr[], int ukuran);
void urutkanBerdasarkanNama(BendaLangit arr[], int ukuran); 
void urutkanBerdasarkanTahun(BendaLangit arr[], int ukuran); 

int cariNama(BendaLangit arr[], int ukuran, string targetNama);
void cariKonstelasi(BendaLangit arr[], int ukuran);

#endif