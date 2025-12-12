#include "matakuliah.h"
#include <iostream>

void createListMatkul(ListMatkul &L) {
    L.first = nullptr;
    L.last = nullptr;
};

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

void insertAfterMatkul(ListMatkul &L, adrMatkul prec, adrMatkul p) {
    if (prec != nullptr) {
        p->next = prec->next;
        p->prev = prec;
        if (prec->next != nullptr) {
            prec->next->prev = p;
        } else {
            L.last = p; // Update last if inserting at the end
        }
        prec->next = p;
    }
};

void deleteFirstMatkul(ListMatkul &L, adrMatkul prec, adrMatkul p) {
    if (L.first != nullptr) {
        p = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = p->next;
            L.first->prev = nullptr;
            p -> next = nullptr;
        };
    };
};

void deleteLastMatkul(ListMatkul &L, adrMatkul &p){
    if(L.first != nullptr){
        p = L.last;
        if (L.first == L.last){
            p = L.last;
            L.first = nullptr;
            L.last = nullptr;
        }else{
            L.last = p -> prev;
            L.last -> next = nullptr;
            p -> prev = nullptr;
        };
    };
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

void showMatkul(ListMatkul L){
    adrMatkul p = L.first;
    if(p == nullptr){
        cout << "Matkul kosong" << endl;
    }else{
        cout << "\n=== Daftar Mata Kuliah ===" << endl;
        int no = 1;
        while (p != nullptr){
            cout << no << ". ID: " << p -> info.idMatkul << ", Nama: " << p -> info.namaMatkul << endl;
            p = p -> next;
            no++;
        }
    }
}
