//
// Created by Behlul on 21.12.2017.
//

#include "person.h"

person::person() {

}
void person::setId(unsigned int number) {
    id=number;
}
int person::getId() {
    return id;
}
void person::setName(string n) {
    name.assign(n);
}
string person::getName() {
    return name;
}
void person::setSurname(string s) {
    surname.assign(s);
}
string person::getSurname() {
    return surname;
}
void person::setPersonType(int p) {
    switch (p){
        case 0:
            personType1 = User;
            break;
        case 1:
            personType1 = Admin;
            break;
        default:
            cout << "Wrong typing." << endl;
    }
}
string person::getPersonType() {
    switch (personType1){
        case User:
            return "User";
        case Admin:
            return  "Admin";
        default:
            cout << "It was not initialized." << endl;
    }
}