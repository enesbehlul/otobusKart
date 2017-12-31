//
// Created by Behlul on 22.12.2017.
//

#include <iostream>
#include <string>
#include "card.h"
using namespace std;

card::card() {}

void card::setCardType(int c) {
    switch (c){
        case 0:
            cardType1 = Normal;
            break;
        case 1:
            cardType1 = Student;
            break;
        case 2:
            cardType1 = Retired;
            break;
        default:
            cout << "Wrong typing." << endl;
    }
}
string card::getCardType() {
    switch (cardType1){
        case Normal:
            return "Normal";
        case Student:
            return "Student";
        case Retired:
            return "Retired";
        default:
            cout << "Wrong typing." << endl;
    }
}
void card::setBalance(int payment) {
    if (getBalance()!=0){
        balance += payment;
    }
    else
        balance = payment;
}
int card::getBalance() {
    return balance;
}