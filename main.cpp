#include <iostream>
#include "header.h"

using namespace std;

int main() {
    ListGuru LG;
    createListGuru(LG);
    menuUtama(LG);
}

void menuUtama(ListGuru &L) {
    int pilihan;
    do {
        cout << endl;
        cout << "================================================" << endl;
        cout << "     SISTEM GURU N MATKUL    " << endl;
        cout << "================================================" << endl;
        cout << endl;
        cout << "  1. Test Case" << endl;
        cout << "  2. Study Case" << endl;
        cout << "  0. Keluar" << endl;
        cout << endl;
        cout << "================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            menuAdmin(L);
        } else if (pilihan == 2) {
            menuUser(L);
        } else if (pilihan == 0) {
            cout << "\nTerima kasih! SAMPAI JUMPA" << endl;
        } else {
            cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

}
