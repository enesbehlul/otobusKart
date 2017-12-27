//
// Created by Behlul on 21.12.2017.
//

#ifndef OTOBUSKART_ADMIN_H
#define OTOBUSKART_ADMIN_H

#include "person.h"

class admin : public person{
public:
    admin();
    void createUser(person * list[10]);
    void deleteUser();
    void showPersonStatus();
    void showUserStatus();
    void findUser();
    void combineUserCards();
private:
};
#endif //OTOBUSKART_ADMİN_H
