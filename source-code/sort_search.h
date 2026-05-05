#ifndef SORT_SEARCH_H
#define SORT_SEARCH_H

#include "types.h"
#include <string>

void urutkanBerdasarkanJarak(BendaLangit arr[], int ukuran);
void urutkanBerdasarkanNama(BendaLangit arr[], int ukuran);
void urutkanBerdasarkanTahun(BendaLangit arr[], int ukuran);
void urutkanBerdasarkanMagnitudo(BendaLangit arr[], int ukuran);
void urutkanNama(BendaLangit arr[], int ukuran);

void cariKonstelasi(BendaLangit arr[], int ukuran);
void cariKategori(BendaLangit arr[], int ukuran);
int cariNama(BendaLangit arr[], int ukuran, std::string targetNama);

#endif