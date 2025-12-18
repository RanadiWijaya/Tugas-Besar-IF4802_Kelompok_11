#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;
//mata kuliah sebagai child dll

struct mataKuliah{
    string namaMatkul;
    string idMatkul;
    int jam; //berapa jam matakuliah tersebut(sks)
};


typedef mataKuliah infotype;
typedef struct elmMataKuliah *adrMatkul;

typedef struct elmGuru *adrGuru;
struct elmGuru;


struct elmMataKuliah {
    infotype info;
    adrMatkul next;
    adrMatkul prev;
};

struct ListMatkul{
    adrMatkul first;
    adrMatkul last;
};


adrMatkul createElmMatkul(infotype x);
void insertFirstMatkul(adrGuru &g, adrMatkul p);
void insertLastMatkul(adrGuru &g, adrMatkul p);
void insertAfterMatkul(adrGuru &g, adrMatkul prec, adrMatkul p);
void deleteFirstMatkul(adrGuru &g, adrMatkul &p);
void deleteLastMatkul(adrGuru &g, adrMatkul &p);
void deleteAfterMatkul(adrGuru &g, adrMatkul prec, adrMatkul &p);
adrMatkul SearchMatkul(adrGuru g, string idMatkul);
int hitungMatkul(adrGuru g);
void showMatkul(adrGuru g);

#endif // MATAKULIAH_H_INCLUDED


