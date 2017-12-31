//
// Created by Behlul on 21.12.2017.
//

#include "user.h"
#include <iostream>
#include <string>
using namespace std;


user::user(){
    setPersonType(0);
}
user* user::operator+(user *a){
    a->card1->setBalance(a->card2->getBalance());
    a->card2->setBalance(0);
    return a;
}

void user::loadBalance(card *c, unsigned int payment){
    c->setBalance(payment);
}
void user::readCard(card *c){
    if(c->getCardType()=="Student" && c->getBalance()>=1000){
        c->setBalance(-1000);
        cout << "Odeme basarili"<< endl;
    }
    else if(c->getCardType()=="Retired"){
        cout << "Odeme basarili"<< endl;
    }
    else if(c->getCardType()=="Normal" && c->getBalance()>=2000){
        c->setBalance(-2000);
        cout << "Odeme basarili"<< endl;
    }
    else
        cout<<"Yetersiz bakiye"<<endl;
}
string user::showCardStatus(card *c){
    string bk = "Bakiyeniz: ";
    int b = c->getBalance();
    bk += to_string(b);
    return bk;
}