#include "header.h"
void deleteFirstMatkul(adrGuru G, adrMatkul &P) {
    if (G == nullptr || G->firstMatkul == nullptr) {
        P = nullptr;
        return;
    }
    P = G->firstMatkul;
    G->firstMatkul = P->next;

    if (G->firstMatkul != nullptr) {
        G->firstMatkul->prev = nullptr;
    }
    P->next = nullptr;
}

void deleteLastMatkul(adrGuru G, adrMatkul &P) {
    if (G == nullptr || G->firstMatkul == nullptr) {
        P = nullptr;
        return;
    }

    if (G->firstMatkul->next == nullptr) {
        P = G->firstMatkul;
        G->firstMatkul = nullptr;
    } else {
        adrMatkul Q = G->firstMatkul;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        P = Q;
        Q->prev->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfterMatkul(adrMatkul Prec, adrMatkul &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;

    if (P->next != nullptr) {
        P->next->prev = Prec;
    }
    P->next = nullptr;
    P->prev = nullptr;
}
int countMatkul(adrGuru G) {
    if (G == nullptr) {
        return 0;
    }

    int count = 0;
    adrMatkul P = G->firstMatkul;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

int totalSKS(adrGuru G) {
    if (G == nullptr) {
        return 0;
    }

    int total = 0;
    adrMatkul P = G->firstMatkul;
    while (P != nullptr) {
        total += P->info.sks;
        P = P->next;
    }
    return total;
}

void showMatkul(adrGuru G) {
    if (G == nullptr || G->firstMatkul == nullptr) {
        cout << "Mata kuliah kosong." << endl;
        return;
    }

    adrMatkul P = G->firstMatkul;
    int no = 1;

    cout << "=== DAFTAR MATA KULIAH ===" << endl;
    cout << "Guru: " << G->info.namaGuru << endl;
    cout << "--------------------------" << endl;
    while (P != nullptr) {
        cout << no++ << ". " << P->info.idMatkul << " | "
             << P->info.namaMatkul << " | "
             << P->info.sks << " SKS" << endl;
        P = P->next;
    }
    cout << "--------------------------" << endl;
    cout << "Total: " << countMatkul(G) << " matkul, "
         << totalSKS(G) << " SKS" << endl;
}
