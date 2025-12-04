#include <iostream>
#include "guru.h"

void createListGuru(ListGuru &L){
    L.first = nullptr;
}
adrGuru createElmGuru(infoGuru x){
    adrGuru p;
    p->info =x;
    p->next = nullptr;
    p->firstMatKul = nullptr;
}
void insertFirstGuru(ListGuru &L, adrGuru p){
    if(L.first != nullptr){
        L.first = p;
    }else{
        p->next =L.first;
        L.first = p;
    }
}
void insertLastGuru(ListGuru &L, adrGuru p){
    adrGuru q;
    q = L.first;
    while (q->next != nullptr){
        q =q->next;
    }
    q->next = p;
}
void insertAfterGuru(ListGuru &L, adrGuru prec, adrGuru p){
    if(prec != nullptr){
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirstGuru(ListGuru &L, adrGuru &p){
    if (L.first == nullptr){
        cout<< "Daftar Guru tidak ada. "<<endl;
    }else{
        p = L.first;
        L.first =p->next;
        p->next =nullptr;
    }
}
void deleteLastGuru(ListGuru &L, adrGuru &p){
    if(L.first == nullptr){
        cout<< "Daftar Guru tidak ada. "<<endl;
    }else{
        adrGuru q;
        while(q->next->next != nullptr){
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }

}
void deleteAfterGuru(ListGuru &L, adrGuru prec, adrGuru &p){
    if(prec != nullptr && prec->next != nullptr){
        p =prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }else{
        cout<< "Tidak ada daftar Guru yang di hapus "<<endl;
    }
}

void SearchGuru(ListGuru L, adrGuru p);
int hitungGuru(ListGuru L);
void showAllData(ListGuru L);
void showGuru(ListGuru L);
