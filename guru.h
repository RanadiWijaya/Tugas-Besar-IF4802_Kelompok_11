#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED
#include <string>>

using namespace std;



//guru sebagai parent sll
struct guru{
    string namaGuru;
    string idGuru;
    string kelas;
};
typedef guru infoGuru;
typedef struct elmGuru *adrGuru;

typedef struct elmMataKuliah *adrMatkul;
struct elmMataKuliah;

struct elmGuru {
    infoGuru info;
    adrGuru next;
    adrMatkul firstMatKul; //untuk ke child matkul
};

struct ListGuru{
    adrGuru first;
};

void createListGuru(ListGuru &L);
adrGuru createElmGuru(infoGuru x);
void insertFirstGuru(ListGuru &L, adrGuru p);
void insertLastGuru(ListGuru &L, adrGuru p);
void insertAfterGuru(ListGuru &L, adrGuru prec, adrGuru p);
void deleteFirstGuru(ListGuru &L, adrGuru &p);
void deleteLastGuru(ListGuru &L, adrGuru &p);
void deleteAfterGuru(ListGuru &L, adrGuru prec, adrGuru &p);
void SearchGuru(ListGuru L, string nama, adrGuru p);
int hitungGuru(ListGuru L);
void showAllData(ListGuru L);
void showGuru(ListGuru L);

#endif // GURU_H_INCLUDED

