#include "main.h"

void menuAdmin(ListGuru &LG){
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
              menuGuru(LG);
              continue;
           case 2  :
              cout << "you choose option 2" << endl;
              menuMataKuliah(LG);
              continue;
        }
    }
}


void menuGuru(ListGuru &LG){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Parent============ " << endl;
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
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;


              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;

            case 3  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 4  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 5  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 6  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 7  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 8  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 9  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
           case 10  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;


        }
    }
}

void menuMataKuliah(ListGuru &LG){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Child============ " << endl;
        cout << "|| 1. insert first          ||" << endl;
        cout << "|| 2. insert last           ||" << endl;
        cout << "|| .....dst                 ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              // write your code here

              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
            // continue for another case here
        }
    }
}
