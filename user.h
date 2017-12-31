//
// Created by Behlul on 21.12.2017.
//

#ifndef OTOBUSKART_USER_H
#define OTOBUSKART_USER_H

#include "person.h"
#include <iostream>
#include <string>

class user : public person{
public:
    user();
    card *card1;
    card *card2;
    user* operator+(user*);
    void loadBalance(card*,unsigned int);
    void readCard(card*);
    string showCardStatus(card*);
private:
};

#endif //OTOBUSKART_USER_H
