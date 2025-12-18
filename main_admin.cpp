#include "main.h"
#include "guru.h"
#include "matakuliah.h"


void menuAdmin(){
    ListGuru L;
    createListGuru(L);
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin============ " << endl;
        cout << "|| 1. Guru                        ||" << endl;
        cout << "|| 2. Mata kuliah                 ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "=================================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuGuru(L);
              continue;
           case 2  :
              cout << "you choose option 2" << endl;
              menuMataKuliah(L);
              continue;
        }
    }
}


void menuGuru(ListGuru &L){
    adrGuru p, s;
    guru x;
    string nama;
    int total;
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Guru============ " << endl;
        cout << "|| 1. insert first          ||" << endl;
        cout << "|| 2. insert last           ||" << endl;
        cout << "|| 3. insert after          ||" << endl;
        cout << "|| 4. Delete first          ||" << endl;
        cout << "|| 5. Delete last           ||" << endl;
        cout << "|| 6. Delete after          ||" << endl;
        cout << "|| 7. Show Guru             ||" << endl;
        cout << "|| 8. Show All              ||" << endl;
        cout << "|| 9. Cari Guru             ||" << endl;
        cout << "|| 10. Hitung Guru          ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option){
            case 1:
                cout << "ID Guru: "; cin >> x.idGuru;
                cout << "Nama Guru: "; cin >> x.namaGuru;
                cout << "Kelas: "; cin >> x.kelas;
                insertFirstGuru(L, createElmGuru(x));
                break;

            case 2:
                cout << "ID Guru: "; cin >> x.idGuru;
                cout << "Nama Guru: "; cin >> x.namaGuru;
                cout << "Kelas: "; cin >> x.kelas;
                insertLastGuru(L, createElmGuru(x));
                break;

            case 3:
                cout << "Nama guru sebelumnya: ";
                cin >> nama;
                SearchGuru(L, nama, s);
                if(s != nullptr){
                    cout << "ID Guru: "; cin >> x.idGuru;
                    cout << "Nama Guru: "; cin >> x.namaGuru;
                    cout << "Kelas: "; cin >> x.kelas;
                    insertAfterGuru(L, s, createElmGuru(x));
                }else{
                    cout << "Guru tidak ditemukan"; cin.get(); cin.get();
                }
                break;

            case 4:
                deleteFirstGuru(L, p);
                break;

            case 5:
                deleteLastGuru(L, p);
                break;

            case 6:
                cout << "Nama guru sebelumnya: ";
                cin >> nama;
                SearchGuru(L, nama, s);
                deleteAfterGuru(L, s, p);
                cin.get(); cin.get();
                break;

            case 7:
                cout << "Nama guru: ";
                cin >> nama;
                SearchGuru(L, nama, p);
                showGuru(p);
                break;

            case 8:
                showAllData(L);
                cin.get(); cin.get();
                break;

            case 9:
                cout << "Cari nama guru: ";
                cin >> nama;
                SearchGuru(L, nama, p);
                if(p != nullptr){
                    cout << "Ditemukan: " << p->info.namaGuru;
                }else{
                    cout << "Tidak ditemukan";
                }
                cin.get(); cin.get();
                break;

            case 10:
                cout << "Total guru: " << hitungGuru(L);
                cin.get(); cin.get();
                break;
        }
    }
}

void menuMataKuliah(ListGuru &L){
    int option=-99;
    while (option != 0) {
        adrGuru g;
        adrMatkul p, prec;
        mataKuliah x;
        string namaGuru, idMatkul;
        system("cls");
        cout << "============ Menu Child============ " << endl;
        cout << "|| 1. insert first          ||" << endl;
        cout << "|| 2. insert last           ||" << endl;
        cout << "|| 3. insert after          ||" << endl;
        cout << "|| 4. Delete first          ||" << endl;
        cout << "|| 5. Delete last           ||" << endl;
        cout << "|| 6. Delete after          ||" << endl;
        cout << "|| 7. Show Mata Kuliah      ||" << endl;
        cout << "|| 8. Cari Mata Kuliah      ||" << endl;
        cout << "|| 9. Hitung Mata Kuliah    ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;

        if(option == 0) break;

        // PILIH GURU
        cout << "Masukkan nama guru: ";
        cin >> namaGuru;
        SearchGuru(L, namaGuru, g);

        if(g == nullptr){
            cout << "Guru tidak ditemukan!";
            continue;
        }

        switch(option) {
           case 1  :
                cout << "ID Matkul   : "; cin >> x.idMatkul;
                cout << "Nama Matkul : "; cin >> x.namaMatkul;
                cout << "Jam (SKS)   : "; cin >> x.jam;
                insertFirstMatkul(g, createElmMatkul(x));
                break;
           case 2  :
              cout << "ID Matkul   : "; cin >> x.idMatkul;
            cout << "Nama Matkul : "; cin >> x.namaMatkul;
            cout << "Jam (SKS)   : "; cin >> x.jam;
            insertLastMatkul(g, createElmMatkul(x));

              break;

            case 3  :
                cout << "Masukkan ID Matkul: ";
                cin >> idMatkul;
                prec = SearchMatkul(g, idMatkul);
              if(prec != nullptr){
                cout << "ID Matkul   : "; cin >> x.idMatkul;
                cout << "Nama Matkul : "; cin >> x.namaMatkul;
                cout << "Jam (SKS)   : "; cin >> x.jam;
                insertAfterMatkul(g, prec, createElmMatkul(x));
            }else{
                cout << "Matkul sebelumnya tidak ditemukan";
            }
              break;
           case 4  :
              deleteFirstMatkul(g, p);
            if(p != nullptr){
                cout << "Matkul: " << p->info.namaMatkul<<" telah dihapus! "<<endl;
                delete p;
            }
              break;
           case 5  :
               deleteLastMatkul(g, p);
              if(p != nullptr){
                cout << "Matkul: " << p->info.namaMatkul<<" telah dihapus! "<<endl;
                delete p;
            }
              break;
           case 6  :
                cout << "Masukkan ID Matkul: ";
                cin >> idMatkul;
                prec = SearchMatkul(g, idMatkul);
                deleteAfterMatkul(g, prec, p);
              if(p != nullptr){
                cout << "Matkul: " << p->info.namaMatkul<<" telah dihapus! "<<endl;
                delete p;
            }
              break;
           case 7  :
              showMatkul(g);
              break;
           case 8  :
            cout << "Masukkan ID Matkul: ";
            cin >> idMatkul;
            p = SearchMatkul(g,idMatkul);
            if(p != nullptr){
                cout << "Ditemukan: " << p->info.namaMatkul;
            }else{
                cout << "Matkul tidak ditemukan";
            }
              break;
           case 9  :
            cout << "Total Matkul: " << hitungMatkul(g);
              break;

        }
        cin.get(); cin.get();
    }
}
