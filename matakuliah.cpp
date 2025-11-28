#include "matakuliah.h"

adrMatkul createElmMatkul(infotype x) {
    adrMatkul p = new elmMataKuliah;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
};

