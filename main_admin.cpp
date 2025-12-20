#include <iostream>
#include "header.h"

using namespace std;

void menuAdmin(ListGuru &L) {
    int pilihan;

    do {
        cout << endl;
        cout << "============ Menu Admin ============" << endl;
        cout << "|| 1. Guru                        ||" << endl;
        cout << "|| 2. Mata Kuliah                 ||" << endl;
        cout << "|| 0. Kembali                     ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            menuGuru(L);
        } else if (pilihan == 2) {
            menuMataKuliah(L);
        } else if (pilihan != 0) {
            cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}

void menuGuru(ListGuru &L) {
    int pilihan;
    adrGuru P, Prec;
    infotypeGuru dataGuru;
    string nama;

    do {
        cout << endl;
        cout << "============ Menu Guru ============" << endl;
        cout << "|| 1. Insert First               ||" << endl;
        cout << "|| 2. Insert Last                ||" << endl;
        cout << "|| 3. Insert After               ||" << endl;
        cout << "|| 4. Delete First               ||" << endl;
        cout << "|| 5. Delete Last                ||" << endl;
        cout << "|| 6. Delete After               ||" << endl;
        cout << "|| 7. Show Guru                  ||" << endl;
        cout << "|| 8. Show All                   ||" << endl;
        cout << "|| 9. Cari Guru                  ||" << endl;
        cout << "|| 10. Hitung Guru               ||" << endl;
        cout << "|| 0. Kembali                    ||" << endl;
        cout << "===================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "ID Guru   : "; cin >> dataGuru.idGuru;
            cout << "Nama Guru : "; cin >> dataGuru.namaGuru;
            cout << "Kelas     : "; cin >> dataGuru.kelas;
            insertFirstGuru(L, createElmGuru(dataGuru));
            cout << "Guru berhasil ditambahkan!" << endl;

        } else if (pilihan == 2) {
            cout << "ID Guru   : "; cin >> dataGuru.idGuru;
            cout << "Nama Guru : "; cin >> dataGuru.namaGuru;
            cout << "Kelas     : "; cin >> dataGuru.kelas;
            insertLastGuru(L, createElmGuru(dataGuru));
            cout << "Guru berhasil ditambahkan!" << endl;

        } else if (pilihan == 3) {
            cout << "Nama guru sebelumnya: ";
            cin >> nama;
            Prec = findGuru(L, nama);
            if (Prec != nullptr) {
                cout << "ID Guru   : "; cin >> dataGuru.idGuru;
                cout << "Nama Guru : "; cin >> dataGuru.namaGuru;
                cout << "Kelas     : "; cin >> dataGuru.kelas;
                insertAfterGuru(Prec, createElmGuru(dataGuru));
                cout << "Guru berhasil ditambahkan!" << endl;
            } else {
                cout << "Guru tidak ditemukan!" << endl;
            }

        } else if (pilihan == 4) {
            deleteFirstGuru(L, P);
            if (P != nullptr) {
                cout << "Guru " << P->info.namaGuru << " berhasil dihapus!" << endl;
                delete P;
            }

        } else if (pilihan == 5) {
            deleteLastGuru(L, P);
            if (P != nullptr) {
                cout << "Guru " << P->info.namaGuru << " berhasil dihapus!" << endl;
                delete P;
            }

        } else if (pilihan == 6) {
            cout << "Nama guru sebelumnya: ";
            cin >> nama;
            Prec = findGuru(L, nama);
            if (Prec != nullptr) {
                deleteAfterGuru(Prec, P);
                if (P != nullptr) {
                    cout << "Guru " << P->info.namaGuru << " berhasil dihapus!" << endl;
                    delete P;
                } else {
                    cout << "Tidak ada guru setelahnya!" << endl;
                }
            } else {
                cout << "Guru tidak ditemukan!" << endl;
            }

        } else if (pilihan == 7) {
            cout << "Nama guru: ";
            cin >> nama;
            P = findGuru(L, nama);
            showGuru(P);

        } else if (pilihan == 8) {
            showAllGuru(L);

        } else if (pilihan == 9) {
            cout << "Cari nama guru: ";
            cin >> nama;
            P = findGuru(L, nama);
            if (P != nullptr) {
                cout << "Ditemukan: " << P->info.namaGuru << endl;
            } else {
                cout << "Tidak ditemukan!" << endl;
            }

        } else if (pilihan == 10) {
            cout << "Total guru: " << countGuru(L) << endl;

        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}

void menuMataKuliah(ListGuru &L) {
    int pilihan;
    adrGuru G;
    adrMatkul P, Prec;
    infotypeMatkul dataMatkul;
    string namaGuru, idMatkul;

    do {
        cout << endl;
        cout << "========= Menu Mata Kuliah =========" << endl;
        cout << "|| 1. Insert First                ||" << endl;
        cout << "|| 2. Insert Last                 ||" << endl;
        cout << "|| 3. Insert After                ||" << endl;
        cout << "|| 4. Delete First                ||" << endl;
        cout << "|| 5. Delete Last                 ||" << endl;
        cout << "|| 6. Delete After                ||" << endl;
        cout << "|| 7. Show Mata Kuliah            ||" << endl;
        cout << "|| 8. Cari Mata Kuliah            ||" << endl;
        cout << "|| 9. Hitung Mata Kuliah          ||" << endl;
        cout << "|| 0. Kembali                     ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 9) {
            cout << "Masukkan nama guru: ";
            cin >> namaGuru;
            G = findGuru(L, namaGuru);

            if (G == nullptr) {
                cout << "Guru tidak ditemukan!" << endl;
            } else {
                if (pilihan == 1) {
                    cout << "ID Matkul   : "; cin >> dataMatkul.idMatkul;
                    cout << "Nama Matkul : "; cin >> dataMatkul.namaMatkul;
                    cout << "SKS         : "; cin >> dataMatkul.sks;
                    insertFirstMatkul(G, createElmMatkul(dataMatkul));
                    cout << "Mata kuliah berhasil ditambahkan!" << endl;

                } else if (pilihan == 2) {
                    cout << "ID Matkul   : "; cin >> dataMatkul.idMatkul;
                    cout << "Nama Matkul : "; cin >> dataMatkul.namaMatkul;
                    cout << "SKS         : "; cin >> dataMatkul.sks;
                    insertLastMatkul(G, createElmMatkul(dataMatkul));
                    cout << "Mata kuliah berhasil ditambahkan!" << endl;

                } else if (pilihan == 3) {
                    cout << "ID Matkul sebelumnya: ";
                    cin >> idMatkul;
                    Prec = findMatkul(G, idMatkul);
                    if (Prec != nullptr) {
                        cout << "ID Matkul   : "; cin >> dataMatkul.idMatkul;
                        cout << "Nama Matkul : "; cin >> dataMatkul.namaMatkul;
                        cout << "SKS         : "; cin >> dataMatkul.sks;
                        insertAfterMatkul(Prec, createElmMatkul(dataMatkul));
                        cout << "Mata kuliah berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Matkul tidak ditemukan!" << endl;
                    }

                } else if (pilihan == 4) {
                    deleteFirstMatkul(G, P);
                    if (P != nullptr) {
                        cout << "Matkul " << P->info.namaMatkul << " berhasil dihapus!" << endl;
                        delete P;
                    } else {
                        cout << "Tidak ada mata kuliah!" << endl;
                    }

                } else if (pilihan == 5) {
                    deleteLastMatkul(G, P);
                    if (P != nullptr) {
                        cout << "Matkul " << P->info.namaMatkul << " berhasil dihapus!" << endl;
                        delete P;
                    } else {
                        cout << "Tidak ada mata kuliah!" << endl;
                    }

                } else if (pilihan == 6) {
                    cout << "ID Matkul sebelumnya: ";
                    cin >> idMatkul;
                    Prec = findMatkul(G, idMatkul);
                    if (Prec != nullptr) {
                        deleteAfterMatkul(Prec, P);
                        if (P != nullptr) {
                            cout << "Matkul " << P->info.namaMatkul << " berhasil dihapus!" << endl;
                            delete P;
                        } else {
                            cout << "Tidak ada matkul setelahnya!" << endl;
                        }
                    } else {
                        cout << "Matkul tidak ditemukan!" << endl;
                    }

                } else if (pilihan == 7) {
                    showMatkul(G);
                } else if (pilihan == 8) {
                    cout << "Masukkan ID Matkul: ";
                    cin >> idMatkul;
                    P = findMatkul(G, idMatkul);
                    if (P != nullptr) {
                        cout << "Ditemukan: " << P->info.namaMatkul << endl;
                    } else {
                        cout << "Matkul tidak ditemukan!" << endl;
                    }
                } else if (pilihan == 9) {
                    cout << "Total Matkul: " << countMatkul(G) << endl;
                }
            }
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}
