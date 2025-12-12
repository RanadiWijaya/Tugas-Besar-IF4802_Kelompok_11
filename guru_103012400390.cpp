#include <iostream>
#include "guru.h"
#include "matakuliah.h"

void insertAfterGuru(ListGuru &L, adrGuru prec, adrGuru p){
    if(prec != nullptr){
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirstGuru(ListGuru &L, adrGuru &p){
    if (L.first == nullptr){
        cout<< "Daftar Guru tidak ada. "<<endl;
    }else if(L.first->next == nullptr){// kondisi 1
      L.first = nullptr;
    }else{
        p = L.first;
        L.first =p->next;
        p->next =nullptr;
    }
}
void deleteLastGuru(ListGuru &L, adrGuru &p){
    if(L.first == nullptr){
        cout<< "Daftar Guru tidak ada. "<<endl;
    }else if(L.first->next == nullptr){// kondisi 1
      L.first = nullptr;
    }else{
        adrGuru q;
        q =L.first;
        while(q->next->next != nullptr){
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }

}


int hitungGuru(ListGuru L){
    int total = 0;
    adrGuru q;
    q = L.first;
    while(q != nullptr){
        total = total +1;
        q =q->next;
    }
    return total;
}

void showGuru(ListGuru L){
    if(L.first == nullptr){
        cout<<"Data Guru tidak ada. "<<endl;
    }else{
        adrGuru p;
        p = L.first;
        cout<<"===== GURU ====="<<endl;
        while(p != nullptr){
            cout<<"Nama: "<<p->info.namaGuru<<endl;
            cout<<"ID: "<<p->info.idGuru<<endl;
            cout<<"Kelas: "<<p->info.kelas<<endl;
            cout<<"."<<endl;
            cout<<"------------------------"<<endl;
            p = p->next;
        }
    }
}

