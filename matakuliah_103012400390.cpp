#include "guru.h"
#include "matakuliah.h"
#include <iostream>

adrMatkul createElmMatkul(infotype x) {
    adrMatkul p = new elmMataKuliah;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
};

void insertFirstMatkul(adrGuru &g, adrMatkul p) {
    if(g == nullptr){
      cout<<"Alamat guru tidak ada. "<<endl;
      return;
    }
    if(g->firstMatKul == nullptr){
        g->firstMatKul = p;
    }else{
        p->next = g->firstMatKul;
        g->firstMatKul->prev = p;
        g->firstMatKul = p;
    }
};

void insertLastMatkul(adrGuru &g, adrMatkul p) {
    if(g == nullptr){
      cout<<"Alamat guru tidak ada. "<<endl;
      return;
    }
    if(g->firstMatKul == nullptr){
        g->firstMatKul = p;
    }else{
        adrMatkul q = g->firstMatKul;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
};
void deleteAfterMatkul(adrGuru &g, adrMatkul prec, adrMatkul &p){
    if(g == nullptr || prec == nullptr || prec->next == nullptr){
        p = nullptr;
        return;
    }

    p = prec->next;
    prec->next = p->next;

    if(p->next != nullptr){
        p->next->prev = prec;
    }

    p->next = nullptr;
    p->prev = nullptr;
};

adrMatkul SearchMatkul(adrGuru g, string idMatkul){
     if(g == nullptr){
        return nullptr;
    }
    adrMatkul p;
    p = g->firstMatKul;
    while(p != nullptr && p->info.idMatkul != idMatkul){
        p = p->next;
    }
    return p;
};

int hitungMatkul(adrGuru g){
    if(g == nullptr){
        return 0;
    }

    int total = 0;
    adrMatkul p;
    p = g->firstMatKul;

    while(p != nullptr){
        total++;
        p = p->next;
    }
    return total;
};
