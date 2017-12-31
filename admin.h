//
// Created by Behlul on 21.12.2017.
//

#ifndef OTOBUSKART_ADMIN_H
#define OTOBUSKART_ADMIN_H
#include <iostream>
#include <string>
#include "person.h"
#include "user.h"

class admin : public person{
public:
    admin();
    void createUser(person * list[10]);
    void deleteUser(person * list[10]);
    void showPersonStatus(person * list[10]);
    void showUserStatus(person * list[10]);
    user* findUser(person * list[10]);
    void combineUserCards(person * list[10]);
    unsigned int scanId();
private:
};
#endif //OTOBUSKART_ADMİN_H
