#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED
using namespace std;

//guru sebagai parent sll

struct guru{
    string namaGuru;
    string idGuru;
};
typedef guru infotype;
typedef struct elmGuru *address;

//SLL

struct elmGuru {
    infotype info;
    address next;
    address matKul; //untuk ke child matkul
}

struct ListGuru{
    address first;
};

void createListGuruSll(ListGuru &L);
address createElmGuruSll(infotype x);
void insertFirstGuruSLL(ListGuru &L, address p);

#endif // GURU_H_INCLUDED
