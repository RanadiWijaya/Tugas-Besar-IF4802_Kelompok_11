#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
using namespace std;
//sll
//mata kuliah sebagai child

struct mataKuliah{
    string namaMatkul;
    string idMatkul
};
typedef mataKuliah infotype;
typedef struct elmMataKuliahSLL *addrSll;
typedef struct elmMataKuliahDLL *addrDll;


//SLL

struct elmMataKuliahSLL {
    infotype info;
    addrSll next;
}

struct ListMatkulSLL{
    addrSll first;
};

//DLL

struct elmMataKuliahDLL {
    infotype info;
    addrDll next;
    addrDll prev;
}

struct ListMatkulDLL{
    addrDll first;
    addrDll Last;
};


#endif // MATAKULIAH_H_INCLUDED
