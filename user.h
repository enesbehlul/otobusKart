//
// Created by Behlul on 21.12.2017.
//

#ifndef OTOBUSKART_USER_H
#define OTOBUSKART_USER_H

#include "person.h"

class user : public person{
public:
    user();
    user(string,string, unsigned int);
    card card1;
    card card2;
    user operator+(const card &c2);
    void loadBalance(card,unsigned int);
    void readCard(card);
    void showCardStatus(card);
private:
};

#endif //OTOBUSKART_USER_H
