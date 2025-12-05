#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;
//mata kuliah sebagai child dll

struct mataKuliah{
    string namaMatkul;
    string idMatkul;
    string jam;
};


typedef mataKuliah infotype;
typedef struct elmMataKuliah *adrMatkul;

struct elmMataKuliah {
    infotype info;
    adrMatkul next;
    adrMatkul prev;
};

struct ListMatkul{
    adrMatkul first;
    adrMatkul last;
};

void createListMatkul(ListMatkul &L);
adrMatkul createElmMatkul(infotype x);
void insertFirstMatkul(ListMatkul &L, adrMatkul p);
void insertLastMatkul(ListMatkul &L, adrMatkul p);
void insertAfterMatkul(ListMatkul &L, adrMatkul prec, adrMatkul p);
void insertBeforeMatkul(ListMatkul &L, adrMatkul prec, adrMatkul p);
void deleteFirstMatkul(ListMatkul &L, adrMatkul p);
void deleteLastMatkul(ListMatkul &L, adrMatkul p);
void deleteAfterMatkul(ListMatkul &L, adrMatkul prec, adrMatkul p);
void deleteBeforeMatkul(ListMatkul &L, adrMatkul p);
void SearchMatkul(ListMatkul L, adrMatkul p);
int hitungMatkul(ListMatkul L);
void showMatkul(ListMatkul L);

#endif // MATAKULIAH_H_INCLUDED

