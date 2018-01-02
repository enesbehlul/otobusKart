// Created by Behlul on 21.12.2017.
#include "user.h"
using namespace std;

user::user(){
    setPersonType(0);
}
user* user::operator+(user *a){
    a->card1->setBalance(a->card2->getBalance());
    a->card2->setBalance(0);
    return a;
}
void user::setCards(card *c1, card *c2, int cardType){
    card1 = c1;
    card2 = c2;
    card1->setCardType(cardType);
    card2->setCardType(cardType);
}
card* user::getCard1() {
    return card1;
}
card* user::getCard2(){
    return card2;
}
void user::loadBalance(card *c, int payment){
    if(c->getCardType()!="Retired" && payment != 0){
        c->setBalance(payment);
    } else if(c->getCardType()!="Retired" && payment==0) {
        cout<<"Bir sey degismedi"<<endl;
    }
    else
        puts("Emeklilerden odeme almiyoruz.");
}
void user::readCard(card *c){
    if(c->getCardType()=="Student" && c->getBalance()>=1000){
        c->setBalance(-1000);
        cout << "Odeme basarili"<< endl;
    }
    else if(c->getCardType()=="Retired"){
        cout << "Ucretsiz yolculugun tadini cikarin."<< endl;
    }
    else if(c->getCardType()=="Normal" && c->getBalance()>=2000){
        c->setBalance(-2000);
        cout << "Odeme basarili"<< endl;
    }
    else
        cout<<"Yetersiz bakiye"<<endl;
}
string user::showCardStatus(card *c){
    string bk = "Bakiye: ";
    int b = c->getBalance();
    bk += to_string(b);
    return bk;
}