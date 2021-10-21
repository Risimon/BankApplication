#include <iostream>
#include "bank.h"
using namespace std;

int main(void) {
    int choice;

    while (1) {
        showMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
            case bank::MAKE:
                makeAccount();
                break;
            case bank::DEPOSIT:
                depositMoney();
                break;
            case bank::WITHDRAW:
                withdrawMoney();
                break;
            case bank::INQUIRE:
                showAllAccInfo();
                break;
            case bank::DELETE:
                deleteAccount();
                break;
            case bank::DELETE_ALL:
                deleteAllAccounts();
                break;
            case bank::EXIT:
                return 0;
            default:
                cout << "Illegal selection.." << endl;
        }
    }
}