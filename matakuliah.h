#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
using namespace std;
//sll
//mata kuliah sebagai child dll

struct mataKuliah{
    string namaMatkul;
    string idMatkul
};
typedef mataKuliah infotype;
typedef struct elmMataKuliah *address;


//DLL

struct elmMataKuliah {
    infotype info;
    address next;
    address prev;
}

struct ListMatkul{
    address first;
    address Last;
};


#endif // MATAKULIAH_H_INCLUDED
