
#include "matakuliah.h"
#include <iostream>

adrMatkul createElmMatkul(infotype x) {
    adrMatkul p = new elmMataKuliah;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
};

void isnertFirstMatkul(ListMatkul &L, adrMatkul p) {
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
};

void insertLastMatkul(ListMatkul &L, adrMatkul p) {
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
};

void deleteAfteMatkul(ListMatkul &L, adrMatkul prec, adrMatkul &p){
    if (prec != nullptr && prec -> next != nullptr){
        p = prec -> next;
        prec -> next = p -> next;
        if (p -> next != nullptr){
            p -> next -> prev = prec;
        } else {
            L.last = prec; // Update last if menghapus element terakhir
        };
        p -> next = nullptr;
        p -> prev = nullptr;
    };
};

adrMatkul SearchMatkul(ListMatkul L, string idMatlkul){
    adrMatkul p = L.first;
    while (p != nullptr){
        if (p -> info.idMatkul == idMatlkul){
            return p;
        };
        p = p -> next;
    };
    return nullptr;
};

int hitungMatkul(ListMatkul L){
    int count = 0;
    adrMatkul p = L.first;
    while (p != nullptr){
        count++;
        p = p -> next;
    };
    return count;
};


