#include "header.h"
void createListGuru(ListGuru &L) {
    L.first = nullptr;
}

adrGuru createElmGuru(infotypeGuru x) {
    adrGuru P = new elmGuru;
    P->info = x;
    P->next = nullptr;
    P->firstMatkul = nullptr;
    return P;
}

void insertFirstGuru(ListGuru &L, adrGuru P) {
    P->next = L.first;
    L.first = P;
}

void insertLastGuru(ListGuru &L, adrGuru P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrGuru Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterGuru(adrGuru Prec, adrGuru P) {
    if (Prec != nullptr && P != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

adrGuru findGuru(ListGuru L, string nama) {
    adrGuru P = L.first;
    while (P != nullptr && P->info.namaGuru != nama) {
        P = P->next;
    }
    return P;
}
