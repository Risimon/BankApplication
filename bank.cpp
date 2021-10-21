/*
//
// Created by Yevgeniy on 9/23/21.
//

#include <iostream>
#include "bank.h"
using namespace std;

Account accArr[MAX_ACC_NUM];
int accNum = 0;

void showMenu(void) {
    cout << "------Menu------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Display all" << endl;
    cout << "5. Delete account" << endl;
    cout << "6. Delete all accounts" << endl;
    cout << "7. Exit program" << endl;
}

void makeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int pin;

    if (accNum >= MAX_ACC_NUM) {
        cout << "Sorry! cannot make an account anymore." << endl;
        return;
    }
    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Customer Name: ";
    cin >> name;
    cout << "PIN: ";
    cin >> pin;
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;

    if (getAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    accArr[accNum].pin = pin;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void depositMoney(void) {
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void withdrawMoney(void) {
    int money;
    int id;
    int pin;

    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].attempt == 3)
            return;
        if (accArr[i].accID == id) {
            cout << "Enter PIN: ";
            cin >> pin;
            if (accArr[i].pin != pin){
                cout << "Incorrect PIN!!!" << endl << endl;
                accArr[i].attempt++;
                return;
            }
        }
    }
    cout << "Withdrawal amount: ";
    cin >> money;
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            if (accArr[i].balance < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }
            accArr[i].balance -= money;
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        cout << "Account ID: " << accArr[i].accID << endl;
        cout << "Name: " << accArr[i].cusName << endl;
        cout << "Balance: " << accArr[i].balance << endl << endl;
    }
}

int GetAccIdx(int id) {
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            return i;
        }
    }
    return -1;
}

void DeleteAccount() {
    int id, pin;
    cout << "Account ID to be deleted: ";
    cin >> id;
    if (GetAccIdx(id) == -1){
        cout << endl << "User is not found!" << endl << endl;
        return;
    }
    cout << "PIN: ";
    cin >> pin;
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].attempt == 3)
            return;
        if (accArr[i].accID == id) {
            if (accArr[i].pin != pin){
                cout << "Incorrect PIN!!!" << endl << endl;
                accArr[i].attempt++;
                return;
            }
        }
        if (accArr[i].accID == id) {
            accArr[i].accID = NULL;
            accArr[i].balance = NULL;
            memset(accArr[i].cusName, 0, 40);
            memset(accArr[i].cusName, 0, 40);
        }
    }
    cout << "Account (" << id << ") was successfully deleted." << endl << endl;
}
void DeleteAllAccounts(){
    char pwd[20];
    int attempt = 0;
    cin >> pwd;
    if (pwd != ADMIN_PWD){
        cout << "Incorrect admin password!!!";
    }
    for (int i = 0; i < accNum; i++) {
        accArr[i].accID = NULL;
        accArr[i].balance = NULL;
        memset(accArr[i].cusName, 0, 40);
    }
    cout << "All accounts were successfully deleted." << endl << endl;
    accNum = 0;
    return;
}*/

#include <iostream>
#include "bank.h"
#include "string.h"
using namespace std;

Account accArr[MAX_ACC_NUM];
int accNum = 0;

void showMenu() {
    cout << "------Menu------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Display all" << endl;
    cout << "5. Delete account" << endl;
    cout << "6. Delete all accounts" << endl;
    cout << "7. Exit program" << endl;
}
void makeAccount() {
    int id;
    char name[NAME_LEN];
    int balance;
    char pin[40];

    if (accNum >= MAX_ACC_NUM) {
        cout << "Sorry! Cannot make an account anymore." << endl;
        return;
    }

    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;

    if (getAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    cout << "Customer Name: ";
    cin >> name;
    pinCreation(pin);
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    strcpy(accArr[accNum].pin, pin);
    accNum++;
}
void depositMoney() {
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}
void withdrawMoney() {
    int money;
    int id;
    char pin[4];
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            if (accArr[i].balance < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }

            accArr[i].balance -= money;
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "ID or PIN is invalid." << endl << endl;
}
void showAllAccInfo() {
    for (int i = 0; i < accNum; i++) {
        cout << "Accoount ID: " << accArr[i].accID << endl;
        cout << "Name: " << accArr[i].cusName << endl;
        cout << "Balance: " << accArr[i].balance << endl << endl;
    }
}
int getAccIdx(int id) {
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            return i;
        }
    }
    return -1;
}
void deleteAccount()
{
    int id;
    cout << "Please enter ID of account to be delted: ";
    cin >> id;
    int idx = getAccIdx(id); // saving index of deleted acc in order to assign last account in accArr[] to this index

    if (idx == -1) {
        std::cout << "\nAccount was not find\n\n";
        return;
    }

    if (idx != accNum){
        accArr[idx].accID = accArr[accNum-1].accID;
        accArr[idx].balance = accArr[accNum-1].balance;
        strcpy(accArr[idx].cusName, accArr[accNum-1].cusName);
    }

    accArr[accNum-1].accID = 0;
    accArr[accNum-1].balance = 0;
    strcpy(accArr[accNum-1].cusName, "");

    accNum--;

    cout << "\nAccount was deleted" << endl << endl;
}
void deleteAllAccounts()
{
    for (int i = 0; i < accNum; i++) {
        accArr[accNum].accID = 0;
        accArr[accNum].balance = 0;
        strcpy(accArr[accNum].cusName, "");
    }
    accNum = 0;
    cout << "\nAccounts are deleted\n\n";
}

bool isValid(char* p){
    if (isdigit(*p) && strlen(p) == 4) {
        return true;
    }
    return false;
}

void pinCreation(char*p){
    while (1){
        char pin[40];
        char temp_pin[40];
        cout << "Create PIN: ";
        cin >> pin;
        strcpy(temp_pin, pin);
        cout << "re-inter created PIN: ";
        cin >> pin;
        if (strcmp(pin, temp_pin) == 0 && isValid(pin)){
            p = pin;
            break;
        }
        else{
            cout << "There is not match in PIN or it is bigger than 4 digits. Try again." << endl;
        }
    }
}