//
// Created by Behlul on 21.12.2017.
//

#include "admin.h"
#include <iostream>
#include <string>
#include "user.h"
using namespace std;
#define MAXPERSON = 10
admin::admin(){

}
void admin::createUser(person * list[10]) {
    int i;
    unsigned int id;
    string ad, soyad;
    for (i = 0; i < 10; i++) {
        if(list[i]->getId()==0){
            user *u = new user();
            puts("Bilgileri giriniz...");
            printf("\nKart sahibi>\n\tAd: ");
            scanf("%s",ad);
            printf("\n\tSoyad: ");
            scanf("%s",soyad);
            printf("\n\tId: ");
            scanf("%u",&id);
            u->setPersonType(0);
            u->setName(ad);
            u->setSurname(soyad);
            u->setId(id);
            list[i]=u;
            puts("Olusturuldu");
            return;
        }
    }
    puts("listede yer kalmamis.");
}
void admin::deleteUser(person * list[10]) {
    unsigned int id = 0;
    int i;
    printf("Id giriniz...\n\tId: ");
    scanf("%u",&id);
    for (i = 0; i < 10; i++) {
        if(list[i]->getId()==id && list[i]->getPersonType()=="User"){
            list[i]->setPersonType(0);
            list[i]->setId(0);
            list[i]->setName(" ");
            list[i]->setSurname(" ");
            puts("Silme tamamlandi");
            return;
        }
        else if(list[i]->getId()==id && list[i]->getPersonType()=="Admin"){
            puts("Admin silemezsin.");
            return;
        }
    }
    puts("Boyle bir kullanici bulunamadi.");
}
void admin::showPersonStatus(person * list[10]) {
    user *a = findUser(list);
}
void admin::showUserStatus(person * list[10]) {
    user *a = new user();
    a = findUser(list);
    cout<<"\n\tAd: " <<a->getName()<<"\n\tSoyad: " <<a->getSurname()<<"\nKart bilgileri\n\tKart1"<<a->card1->getBalance()<<"\n\tKart2"<<a->showCardStatus(a->card2);
}
user* admin::findUser(person * list[10]) {
    int i;
    unsigned int ID = scanId();
    for(i = 0; i<10;++i){
        if(list[i]->getId()==ID){
            puts("Kullanici bulundu");
            return ((user *)(list[i]));
        }
    }
    puts("Kullanici bulunamadi");
    return new user();
}
void admin::combineUserCards(person * list[10]) {
    user *a = findUser(list);
    user *b = *a+a;
    cout<<b->showCardStatus(b->card1);
}
unsigned int admin::scanId(){
    unsigned int id;
    puts("Id giriniz.");
    scanf("%u",&id);
    return id;
}