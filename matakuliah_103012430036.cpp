#include "matakuliah.h"
#include <iostream>


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

