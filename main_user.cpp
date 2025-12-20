#include "header.h"

void menuUser(ListGuru &L) {
    int pilihan;

    do {
        cout << endl;
        cout << "================ Menu Study Case ================" << endl;
        cout << "|| 1. Insert Guru berdasarkan kondisi (urut)   ||" << endl;
        cout << "|| 2. Hapus Guru berdasarkan kondisi           ||" << endl;
        cout << "|| 3. Insert Matkul berdasarkan kondisi (urut) ||" << endl;
        cout << "|| 4. Hapus Matkul berdasarkan kondisi         ||" << endl;
        cout << "|| 5. Hitung total SKS dan rata-rata SKS guru  ||" << endl;
        cout << "|| 6. Cari Guru dengan SKS tertentu            ||" << endl;
        cout << "|| 7. Tampilkan semua data Guru                ||" << endl;
        cout << "|| 8. Tampilkan semua Matkul unik              ||" << endl;
        cout << "|| 0. Kembali                                  ||" << endl;
        cout << "=================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // STUDY CASE 1: Insert Guru berdasarkan kondisi (urut berdasarkan nama)
            cout << endl;
            cout << "=== INSERT GURU TERURUT (berdasarkan nama A-Z) ===" << endl;

            infotypeGuru dataGuru;
            cout << "ID Guru   : "; cin >> dataGuru.idGuru;
            cout << "Nama Guru : "; cin >> dataGuru.namaGuru;
            cout << "Kelas     : "; cin >> dataGuru.kelas;

            adrGuru P = createElmGuru(dataGuru);

            // Kondisi: insert terurut berdasarkan nama (ascending)
            if (L.first == nullptr) {
                // List kosong
                L.first = P;
                cout << "Guru berhasil ditambahkan!" << endl;
            } else if (dataGuru.namaGuru < L.first->info.namaGuru) {
                // Insert di awal (nama lebih kecil dari first)
                P->next = L.first;
                L.first = P;
                cout << "Guru berhasil ditambahkan di awal!" << endl;
            } else {
                // Cari posisi yang tepat
                adrGuru Q = L.first;
                while (Q->next != nullptr && Q->next->info.namaGuru < dataGuru.namaGuru) {
                    Q = Q->next;
                }
                P->next = Q->next;
                Q->next = P;
                cout << "Guru berhasil ditambahkan terurut!" << endl;
            }

        } else if (pilihan == 2) {
            // STUDY CASE 2: Hapus Guru berdasarkan kondisi (guru tanpa matkul)
            cout << endl;
            cout << "=== HAPUS GURU TANPA MATA KULIAH ===" << endl;

            if (L.first == nullptr) {
                cout << "Data guru kosong." << endl;
            } else {
                int countDeleted = 0;
                adrGuru P;

                // mengahpus dari depan jika tidak punya matkul
                while (L.first != nullptr && L.first->firstMatkul == nullptr) {
                    P = L.first;
                    L.first = P->next;
                    cout << "Guru " << P->info.namaGuru << " dihapus (tidak punya matkul)" << endl;
                    delete P;
                    countDeleted++;
                }

                // memngapus dari tengah/akhir
                if (L.first != nullptr) {
                    adrGuru Q = L.first;
                    while (Q->next != nullptr) {
                        if (Q->next->firstMatkul == nullptr) {
                            P = Q->next;
                            Q->next = P->next;
                            cout << "Guru " << P->info.namaGuru << " dihapus (tidak punya matkul)" << endl;
                            delete P;
                            countDeleted++;
                        } else {
                            Q = Q->next;
                        }
                    }
                }

                if (countDeleted == 0) {
                    cout << "Tidak ada guru tanpa mata kuliah." << endl;
                } else {
                    cout << "Total " << countDeleted << " guru dihapus." << endl;
                }
            }

        } else if (pilihan == 3) {
            // STUDY CASE 3: Insert Matkul berdasarkan kondisi (urut berdasarkan SKS)
            cout << endl;
            cout << "=== INSERT MATKUL TERURUT (berdasarkan SKS ascending) ===" << endl;

            string namaGuru;
            cout << "Masukkan nama guru: ";
            cin >> namaGuru;
            adrGuru G = findGuru(L, namaGuru);

            if (G == nullptr) {
                cout << "Guru tidak ditemukan!" << endl;
            } else {
                infotypeMatkul dataMatkul;
                cout << "ID Matkul   : "; cin >> dataMatkul.idMatkul;
                cout << "Nama Matkul : "; cin >> dataMatkul.namaMatkul;
                cout << "SKS         : "; cin >> dataMatkul.sks;

                adrMatkul P = createElmMatkul(dataMatkul);

                //insert terurut berdasarkan SKS (ascending)
                if (G->firstMatkul == nullptr) {
                    // List kosong
                    G->firstMatkul = P;
                    cout << "Matkul berhasil ditambahkan!" << endl;
                } else if (dataMatkul.sks < G->firstMatkul->info.sks) {
                    // Insert di awal (SKS lebih kecil dari first)
                    P->next = G->firstMatkul;
                    G->firstMatkul->prev = P;
                    G->firstMatkul = P;
                    cout << "Matkul berhasil ditambahkan di awal!" << endl;
                } else {
                    // Cari posisi yang tepat
                    adrMatkul Q = G->firstMatkul;
                    while (Q->next != nullptr && Q->next->info.sks < dataMatkul.sks) {
                        Q = Q->next;
                    }
                    P->next = Q->next;
                    P->prev = Q;
                    if (Q->next != nullptr) {
                        Q->next->prev = P;
                    }
                    Q->next = P;
                    cout << "Matkul berhasil ditambahkan terurut!" << endl;
                }
            }

        } else if (pilihan == 4) {
            // STUDY CASE 4: Hapus Matkul berdasarkan kondisi (SKS < 2)
            cout << endl;
            cout << "=== HAPUS MATKUL DENGAN SKS < 2 ===" << endl;
            if (L.first == nullptr) {
                cout << "Data guru kosong." << endl;
            } else {
                int totalDeleted = 0;
                adrGuru G = L.first;
                while (G != nullptr) {
                    adrMatkul P;
                    // menghapus dari depan jika SKS < 2
                    while (G->firstMatkul != nullptr && G->firstMatkul->info.sks < 2) {
                        P = G->firstMatkul;
                        G->firstMatkul = P->next;
                        if (G->firstMatkul != nullptr) {
                            G->firstMatkul->prev = nullptr;
                        }
                        cout << "Matkul " << P->info.namaMatkul << " (SKS: " << P->info.sks << ") dihapus dari " << G->info.namaGuru << endl;
                        delete P;
                        totalDeleted++;
                    }

                    // Hapus dari tengah/akhir
                    if (G->firstMatkul != nullptr) {
                        adrMatkul Q = G->firstMatkul;
                        while (Q->next != nullptr) {
                            if (Q->next->info.sks < 2) {
                                P = Q->next;
                                Q->next = P->next;
                                if (P->next != nullptr) {
                                    P->next->prev = Q;
                                }
                                cout << "Matkul " << P->info.namaMatkul << " (SKS: " << P->info.sks << ") dihapus dari " << G->info.namaGuru << endl;
                                delete P;
                                totalDeleted++;
                            } else {
                                Q = Q->next;
                            }
                        }
                    }

                    G = G->next;
                }

                if (totalDeleted == 0) {
                    cout << "Tidak ada matkul dengan SKS < 2." << endl;
                } else {
                    cout << "Total " << totalDeleted << " matkul dihapus." << endl;
                }
            }

        } else if (pilihan == 5) {
            // STUDY CASE 5: PERHITUNGAN - Total SKS dan Rata-rata SKS per Guru
            cout << endl;
            cout << "=== {PERHITUNGAN: TOTAL SKS & RATA-RATA SKS ===" << endl;

            if (L.first == nullptr) {
                cout << "Data guru kosong." << endl;
            } else {
                adrGuru P = L.first;
                int grandTotalSKS = 0;
                int grandTotalMatkul = 0;
                int jumlahGuru = 0;

                cout << endl;
                cout << "Detail per Guru:" << endl;
                cout << "--------------------------------" << endl;

                while (P != nullptr) {
                    int sksGuru = totalSKS(P);
                    int matkulGuru = countMatkul(P);
                    float rataRata = 0;

                    if (matkulGuru > 0) {
                        rataRata = (float)sksGuru / matkulGuru;
                    }

                    cout << "Guru: " << P->info.namaGuru << endl;
                    cout << "  - Jumlah Matkul : " << matkulGuru << endl;
                    cout << "  - Total SKS     : " << sksGuru << endl;
                    cout << "  - Rata-rata SKS : " << rataRata << endl;
                    cout << endl;

                    grandTotalSKS += sksGuru;
                    grandTotalMatkul += matkulGuru;
                    jumlahGuru++;

                    P = P->next;
                }

                cout << "================================" << endl;
                cout << "TOTAL KESELURUHAN:" << endl;
                cout << "  - Total Guru        : " << jumlahGuru << endl;
                cout << "  - Total Mata Kuliah : " << grandTotalMatkul << endl;
                cout << "  - Total SKS         : " << grandTotalSKS << endl;
                if (jumlahGuru > 0) {
                    cout << "  - Rata-rata SKS/Guru: " << (float)grandTotalSKS / jumlahGuru << endl;
                }
                cout << "================================" << endl;
            }

        } else if (pilihan == 6) {
            // STUDY CASE 6: Pencarian berdasarkan kondisi (Guru dengan total SKS >= X)
            cout << endl;
            cout << "=== CARI GURU DENGAN TOTAL SKS >= X ===" << endl;

            int minSKS;
            cout << "Masukkan minimal SKS: ";
            cin >> minSKS;

            if (L.first == nullptr) {
                cout << "Data guru kosong." << endl;
            } else {
                adrGuru P = L.first;
                int found = 0;

                cout << endl;
                cout << "Guru dengan total SKS >= " << minSKS << ":" << endl;
                cout << "--------------------------------" << endl;

                while (P != nullptr) {
                    int sksGuru = totalSKS(P);
                    if (sksGuru >= minSKS) {
                        cout << "- " << P->info.namaGuru << " (SKS: " << sksGuru << ")" << endl;
                        found++;
                    }
                    P = P->next;
                }

                if (found == 0) {
                    cout << "Tidak ada guru dengan total SKS >= " << minSKS << endl;
                } else {
                    cout << "--------------------------------" << endl;
                    cout << "Total ditemukan: " << found << " guru" << endl;
                }
            }

        } else if (pilihan == 7) {
            // STUDY CASE 7: Menampilkan semua data Parent(Guru)
            cout << endl;
            cout << "=== TAMPILKAN SEMUA DATA GURU ===" << endl;
            showAllGuru(L);

        } else if (pilihan == 8) {
            // STUDY CASE 8: Menampilkan semua data Child(Matkul tanpa duplikat)
            cout << endl;
            cout << "=== TAMPILKAN SEMUA MATKUL (UNIK) ===" << endl;

            if (L.first == nullptr) {
                cout << "Data guru kosong." << endl;
            } else {
                string displayed[100];
                int displayCount = 0;
                adrGuru G = L.first;
                int no = 1;

                cout << endl;
                cout << "No | ID Matkul | Nama Matkul | SKS | Diajar oleh" << endl;
                cout << "---|-----------|-------------|-----|------------" << endl;

                while (G != nullptr) {
                    adrMatkul M = G->firstMatkul;

                    while (M != nullptr) {
                        bool isDuplicate = false;
                        int i = 0;
                        while (i < displayCount && !isDuplicate) {
                            if (displayed[i] == M->info.idMatkul) {
                                isDuplicate = true;
                            }
                            i++;
                        }
                        // Jika belum ditampilkan, tampilkan dan simpan
                        if (!isDuplicate) {
                            cout << no++ << "  | " << M->info.idMatkul << " | "
                                 << M->info.namaMatkul << " | "
                                 << M->info.sks << "   | "
                                 << G->info.namaGuru << endl;
                            displayed[displayCount] = M->info.idMatkul;
                            displayCount++;
                        }
                        M = M->next;
                    }

                    G = G->next;
                }
                if (displayCount == 0) {
                    cout << "Tidak ada mata kuliah." << endl;
                } else {
                    cout << "---|-----------|-------------|-----|------------" << endl;
                    cout << "Total: " << displayCount << " mata kuliah unik" << endl;
                }
            }
        } else if (pilihan != 0) {
            cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}
