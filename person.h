//
// Created by Behlul on 21.12.2017.
//

#ifndef OTOBUSKART_PERSON_H
#define OTOBUSKART_PERSON_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;
typedef enum personType{User, Admin}personType;
class person{
public:
    void setName(string);
    string getName();

    void setSurname(string);
    string getSurname();

    void setId(unsigned int);
    int getId();

    void setPersonType(int);
    string getPersonType();
private:
    string name;
    string surname;
    unsigned int id;
    personType personType1;
};


#endif //OTOBUSKART_PERSON_H