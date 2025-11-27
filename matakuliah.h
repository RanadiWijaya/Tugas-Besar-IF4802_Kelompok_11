#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
using namespace std;
//mata kuliah sebagai child dll

struct mataKuliah{
    string namaMatkul;
    string idMatkul
};
typedef mataKuliah infotype;
typedef struct elmMataKuliah *address;

struct elmMataKuliah {
    infotype info;
    address next;
    address prev;
}

struct ListMatkul{
    address first;
    address Last;
};

void createListMatkul(ListMatkul &L);
address createElmMatkul(infotype x);
void insertFirstMatkul(ListMatkul &L, address p);
void insertLastMatkul(ListMatkul &L, address p);
void insertAfterMatkul(ListMatkul &L, address prec, address p);
void insertBeforeMatkul(ListMatkul &L, address prec, address p);
void deleteFirstMatkul(ListMatkul &L, address p);
void deleteLastMatkul(ListMatkul &L, address p);
void deleteAfterMatkul(ListMatkul &L, address prec, address p);
void deleteBeforeMatkul(ListMatkul &L, address p);
void SearchMatkul(ListMatkul L, address p);
int hitungMatkul(ListMatkul L);
void showMatkul(ListMatkul L);

#endif // MATAKULIAH_H_INCLUDED
