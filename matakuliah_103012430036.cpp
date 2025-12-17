#include "matakuliah.h"
#include "guru.h"
#include <iostream>



void insertAfterMatkul(adrGuru &g, adrMatkul prec, adrMatkul p) {
    if(g == nullptr || prec == nullptr){
      cout<<"Alamat guru atau prec tidak ada. "<<endl;
      return;
    }

    p->next = prec->next;
    p->prev = prec;

    if(prec->next != nullptr){
        prec->next->prev = p;
    }
    prec->next = p;
};

void deleteFirstMatkul(adrGuru &g, adrMatkul &p) {
     if(g == nullptr || g->firstMatKul == nullptr){
        p = nullptr;
        return;
    }

    p = g->firstMatKul;
    g->firstMatKul = p->next;

    if(g->firstMatKul != nullptr){
        g->firstMatKul->prev = nullptr;
    }

    p->next = nullptr;
};

void deleteLastMatkul(adrGuru &g, adrMatkul &p){
     if(g == nullptr || g->firstMatKul == nullptr){
        p = nullptr;
        return;
    }

    adrMatkul q = g->firstMatKul;

    if(q->next == nullptr){
        p = q;
        g->firstMatKul = nullptr;
    }else{
        while(q->next != nullptr){
            q = q->next;
        }
        p = q;
        q->prev->next = nullptr;
        p->prev = nullptr;
    }
};


void showMatkul(adrGuru g){
    if(g == nullptr || g->firstMatKul == nullptr){
        cout << "Mata kuliah kosong" << endl;
        return;
    }

    adrMatkul p = g->firstMatKul;
    int no = 1;

    cout << "=== DAFTAR MATA KULIAH ===" << endl;
    while(p != nullptr){
        cout << no++ << ". "
             << p->info.idMatkul << " | "
             << p->info.namaMatkul << " | "
             << p->info.jam << endl;
        p = p->next;
    }
}

