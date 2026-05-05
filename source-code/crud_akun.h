#ifndef CRUD_AKUN_H
#define CRUD_AKUN_H

void lihatSeluruhAkun(Pengguna *ptrAkun, int jumlahPengguna);
void lihatAkunSpesifik(Pengguna *ptrAkun, int jumlahPengguna);

void ubahAkun(Pengguna *ptrAkun, int jumlahPengguna);
void hapusAkun(Pengguna *ptrAkun, int &jumlahPengguna);

void lihatAkunSendiri(Pengguna *ptrAkun, int indeksAkun, int ukuran);
void updateProfile(Pengguna *ptrAkun, int indeksAkun, int ukuran);

#endif
