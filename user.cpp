//
// Created by Behlul on 21.12.2017.
//

#include "user.h"
using namespace std;


user::user(){
    setPersonType(0);
}
user::user(string n, string s, unsigned int i) {
    setName(n);
    setSurname(s);
    setId(i);
    setPersonType(0);
    card1.setBalance(0);
    card2.setBalance(0);
}

user operator+(const card &c3){

}


void user::loadBalance(card c, unsigned int payment){
    c.setBalance(payment);
}
void user::readCard(card c){
    if(c.getCardType()=="Student" && c.getBalance()>=1000){
        c.setBalance(-1000);
        cout << "Odeme basarili"<< endl;
    }
    else if(c.getCardType()=="Retired"){
        cout << "Odeme basarili"<< endl;
    }
    else if(c.getCardType()=="Normal" && c.getBalance()>=2000){
        c.setBalance(-2000);
        cout << "Odeme basarili"<< endl;
    }
    else
        cout<<"Yetersiz bakiye"<<endl;
}
void user::showCardStatus(card c){
    cout<<"Kalan bakiyeniz: "<<c.getBalance()<<endl;
}