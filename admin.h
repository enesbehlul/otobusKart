// Created by Behlul on 21.12.2017.
#ifndef OTOBUSKART_ADMIN_H
#define OTOBUSKART_ADMIN_H
#define MAXPERSON 10
#include <iostream>
#include <string>
#include "person.h"
#include "user.h"

class admin : public person{
public:
    admin();
    void createUser(person * list[MAXPERSON]);
    void deleteUser(person * list[MAXPERSON]);
    void showPersonStatus(person * list[MAXPERSON]);
    void showUserStatus(person * list[MAXPERSON]);
    user* findUser(person * list[MAXPERSON]);
    void combineUserCards(person * list[MAXPERSON]);
    unsigned int scanId();
    void renameUser(person *);
private:
};
#endif //OTOBUSKART_ADMİN_H