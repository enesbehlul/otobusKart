//
// Created by Behlul on 22.12.2017.
//

#ifndef OTOBUSKART_CARD_H
#define OTOBUSKART_CARD_H

#include <string>

using namespace std;

typedef enum cardType{
    Normal, Student, Retired
}cardType;
class card{
public:

    card();

    void setCardType(int);
    string getCardType();
    void setBalance(int);
    int getBalance();
private:
    unsigned int balance;
    cardType cardType1;
};
#endif //OTOBUSKART_CARD_H
