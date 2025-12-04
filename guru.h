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
typedef struct elmGuru *adrGuru;

struct elmGuru {
    infotype info;
    adrGuru next;
    adrGuru matKul; //untuk ke child matkul
};

struct ListGuru{
    adrGuru first;
};

void createListGuru(ListGuru &L);
adrGuru createElmGuru(infotype x);
void insertFirstGuru(ListGuru &L, adrGuru p);
void insertLastGuru(ListGuru &L, adrGuru p);
void insertAfterGuru(ListGuru &L, adrGuru prec, adrGuru p);
void insertBeforeGuru(ListGuru &L, adrGuru prec, adrGuru p);
void deleteFirstGuru(ListGuru &L, adrGuru p);
void deleteLastGuru(ListGuru &L, adrGuru p);
void deleteAfterGuru(ListGuru &L, adrGuru prec, adrGuru p);
void deleteBeforeGuru(ListGuru &L, adrGuru p);
void SearchGuru(ListGuru L, adrGuru p);
int hitungGuru(ListGuru L);
void showAllData(ListGuru L);
void showGuru(ListGuru L);

#endif // GURU_H_INCLUDED
