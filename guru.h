#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED
using namespace std;

//guru sebagai parent

struct guru{
    string namaGuru;
    string idGuru;
};
typedef guru infotype;
typedef struct elmGuru *address;

//SLL

typedef elmGuruSLL {
    infotype info;
    address next;
    address matKul; //untuk ke child matkul
}

struct ListGuruSLL{
    address first;
};

//DLL

typedef elmGuruDLL {
    infotype info;
    address next;
    address prev;
}

struct ListGuruDLL{
    address first;
    address Last;
};


void createListGuruSll(ListGuruSLL &L);
void createListGuruDll(ListGuruDLL &L);
address createElmGuruSll(infotype x);
address createElmGuruDll(infotype x);
void insertFirstGuruSLL(ListGuruSLL &L, address p);

#endif // GURU_H_INCLUDED
