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
typedef struct elmMataKuliah *address;

//SLL

typedef elmMataKuliahSLL {
    infotype info;
    address next;
}

struct ListMatkulSLL{
    address first;
};

//DLL

typedef elmMataKuliahDLL {
    infotype info;
    address next;
    address prev;
}

struct ListMatkulDLL{
    address first;
    address Last;
};


#endif // MATAKULIAH_H_INCLUDED
