#include "header.h"

adrMatkul createElmMatkul(infotypeMatkul x) {
    adrMatkul P = new elmMataKuliah;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstMatkul(adrGuru G, adrMatkul P) {
    if (G == nullptr || P == nullptr) {
        return;
    }

    if (G->firstMatkul == nullptr) {
        G->firstMatkul = P;
    } else {
        P->next = G->firstMatkul;
        G->firstMatkul->prev = P;
        G->firstMatkul = P;
    }
}

void insertLastMatkul(adrGuru G, adrMatkul P) {
    if (G == nullptr || P == nullptr) {
        return;
    }

    if (G->firstMatkul == nullptr) {
        G->firstMatkul = P;
    } else {
        adrMatkul Q = G->firstMatkul;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void insertAfterMatkul(adrMatkul Prec, adrMatkul P) {
    if (Prec == nullptr || P == nullptr) {
        return;
    }

    P->next = Prec->next;
    P->prev = Prec;

    if (Prec->next != nullptr) {
        Prec->next->prev = P;
    }
    Prec->next = P;
}


adrMatkul findMatkul(adrGuru G, string id) {
    if (G == nullptr) {
        return nullptr;
    }

    adrMatkul P = G->firstMatkul;
    while (P != nullptr && P->info.idMatkul != id) {
        P = P->next;
    }
    return P;
}
