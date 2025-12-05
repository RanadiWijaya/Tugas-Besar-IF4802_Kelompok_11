#include <iostream>
#include "guru.h"
#include "matakuliah.h"
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

void SearchGuru(ListGuru L, string nama, adrGuru p){
    if(L.first != nullptr){
        adrGuru q;
        q = L.first;
        while((q != nullptr) && (q->info.namaGuru != nama)){
            q =q->next;
        }
    }else{
        cout<<"Daftar Guru tidak ada. "<<endl;
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
}
void showAllData(ListGuru L){
    if(L.first == nullptr){
        cout<<"Data Guru tidak ada. "<<endl;
    }else{
        adrGuru p;
        adrMatkul q;
        p = L.first;
        cout<<"===== DAFTAR GURU ====="<<endl;
        while(p != nullptr){
            cout<<"Nama: "<<p->info.namaGuru<<endl;
            cout<<"ID: "<<p->info.idGuru<<endl;
            cout<<"Kelas: "<<p->info.kelas<<endl;
            cout<<"Mata Kuliah: ";
            q = p->firstMatKul;
            while(q != nullptr){
                cout<< q->info.idMatkul<< ", ";
                q = q->next;
            }
            cout<<"."<<endl;
            cout<<"------------------------"<<endl;
            p = p->next;
        }
    }
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
