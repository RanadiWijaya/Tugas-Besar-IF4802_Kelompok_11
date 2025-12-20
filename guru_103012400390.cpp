#include "header.h"
void deleteFirstGuru(ListGuru &L, adrGuru &P) {
    if (L.first == nullptr) {
        cout << "Daftar Guru kosong." << endl;
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastGuru(ListGuru &L, adrGuru &P) {
    if (L.first == nullptr) {
        cout << "Daftar Guru kosong." << endl;
        P = nullptr;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        adrGuru Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterGuru(adrGuru Prec, adrGuru &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

int countGuru(ListGuru L) {
    int count = 0;
    adrGuru P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void showGuru(adrGuru P) {
    if (P == nullptr) {
        cout << "Guru tidak ditemukan." << endl;
    } else {
        cout << "========== DATA GURU ==========" << endl;
        cout << "ID    : " << P->info.idGuru << endl;
        cout << "Nama  : " << P->info.namaGuru << endl;
        cout << "Kelas : " << P->info.kelas << endl;
        cout << "Mata Kuliah: ";
        adrMatkul M = P->firstMatkul;
        if (M == nullptr) {
            cout << "(tidak ada)";
        } else {
            while (M != nullptr) {
                cout << M->info.idMatkul;
                if (M->next != nullptr) cout << ", ";
                M = M->next;
            }
        }
        cout << endl;
        cout << "================================" << endl;
    }
}

void showAllGuru(ListGuru L) {
    if (L.first == nullptr) {
        cout << "Data guru kosong." << endl;
    } else {
        adrGuru P = L.first;
        int no = 1;
        cout << "========== DAFTAR GURU ==========" << endl;
        while (P != nullptr) {
            cout << "Guru ke-" << no++ << endl;
            cout << "ID    : " << P->info.idGuru << endl;
            cout << "Nama  : " << P->info.namaGuru << endl;
            cout << "Kelas : " << P->info.kelas << endl;
            cout << "Mata Kuliah: ";
            adrMatkul M = P->firstMatkul;
            if (M == nullptr) {
                cout << "(tidak ada)";
            } else {
                while (M != nullptr) {
                    cout << M->info.idMatkul;
                    if (M->next != nullptr) cout << ", ";
                    M = M->next;
                }
            }
            cout << endl;
            cout << "---------------------------------" << endl;
            P = P->next;
        }
    }
}
