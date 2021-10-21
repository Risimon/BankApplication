//
// Created by Yevgeniy on 9/23/21.
//

#ifndef BANKAPPLICATION_BANK_H
#define BANKAPPLICATION_BANK_H

void showMenu() ;
void makeAccount () ;
void depositMoney();
void withdrawMoney () ;
void showAllAccInfo();
int getAccIdx(int);
void deleteAccount();
void deleteAllAccounts();
bool isValid(char*);
void pinCreation(char*);

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, DELETE, DELETE_ALL, EXIT };
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

typedef struct{
    int accID;
    int balance;
    char cusName[NAME_LEN];
    int attempt;
    char pin[NAME_LEN];
} Account;

#endif //BANKAPPLICATION_BANK_H
