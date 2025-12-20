#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

//Child DLL
struct mataKuliah {
    string idMatkul;
    string namaMatkul;
    int sks;
};

typedef mataKuliah infotypeMatkul;
typedef struct elmMataKuliah *adrMatkul;

struct elmMataKuliah {
    infotypeMatkul info;
    adrMatkul next;
    adrMatkul prev;
};

//Parent SLL
struct guru {
    string idGuru;
    string namaGuru;
    string kelas;
};

typedef guru infotypeGuru;
typedef struct elmGuru *adrGuru;

struct elmGuru {
    infotypeGuru info;
    adrGuru next;
    adrMatkul firstMatkul;
};

struct ListGuru{
    adrGuru first;
};

//Guru
void createListGuru(ListGuru &L);
adrGuru createElmGuru(infotypeGuru x);
void insertFirstGuru(ListGuru &L, adrGuru P);
void insertLastGuru(ListGuru &L, adrGuru P);
void insertAfterGuru(adrGuru Prec, adrGuru P);
void deleteFirstGuru(ListGuru &L, adrGuru &P);
void deleteLastGuru(ListGuru &L, adrGuru &P);
void deleteAfterGuru(adrGuru Prec, adrGuru &P);
adrGuru findGuru(ListGuru L, string nama);
int countGuru(ListGuru L);
void showAllGuru(ListGuru L);
void showGuru(adrGuru P);


//Matkul
adrMatkul createElmMatkul(infotypeMatkul x);
void insertFirstMatkul(adrGuru G, adrMatkul P);
void insertLastMatkul(adrGuru G, adrMatkul P);
void insertAfterMatkul(adrMatkul Prec, adrMatkul P);
void deleteFirstMatkul(adrGuru G, adrMatkul &P);
void deleteLastMatkul(adrGuru G, adrMatkul &P);
void deleteAfterMatkul(adrMatkul Prec, adrMatkul &P);
adrMatkul findMatkul(adrGuru G, string id);
int countMatkul(adrGuru G);
int totalSKS(adrGuru G);
void showMatkul(adrGuru G);


//Menu
void menuUtama(ListGuru &L);
void menuAdmin(ListGuru &L);
void menuGuru(ListGuru &L);
void menuMataKuliah(ListGuru &L);
void menuUser(ListGuru &L);
#endif // HEADER_H_INCLUDED
