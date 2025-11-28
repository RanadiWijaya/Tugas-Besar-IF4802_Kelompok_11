#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED
#include <string>>

using namespace std;



//guru sebagai parent sll
struct guru{
    string namaGuru;
    string idGuru;
};
typedef guru infotype;
typedef struct elmGuru *address;

struct elmGuru {
    infotype info;
    address next;
    address matKul; //untuk ke child matkul
};

struct ListGuru{
    address first;
};

void createListGuru(ListGuru &L);
address createElmGuru(infotype x);
void insertFirstGuru(ListGuru &L, address p);
void insertLastGuru(ListGuru &L, address p);
void insertAfterGuru(ListGuru &L, address prec, address p);
void insertBeforeGuru(ListGuru &L, address prec, address p);
void deleteFirstGuru(ListGuru &L, address p);
void deleteLastGuru(ListGuru &L, address p);
void deleteAfterGuru(ListGuru &L, address prec, address p);
void deleteBeforeGuru(ListGuru &L, address p);
void SearchGuru(ListGuru L, address p);
int hitungGuru(ListGuru L);
void showAllData(ListGuru L);
void showGuru(ListGuru L);

#endif // GURU_H_INCLUDED
