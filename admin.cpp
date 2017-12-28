//
// Created by Behlul on 21.12.2017.
//

#include "admin.h"
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
void admin::showPersonStatus(person * list[10], unsigned int ID) {

}
void admin::showUserStatus(person * list[10], unsigned int ID) {
        user *a = findUser(list,ID);
}
user* admin::findUser(person * list[10],unsigned int ID) {
    int i;
    for(i = 0; i<10;i++){
        if(list[i]->getId()==ID){
            return ((user *)(list[i]));
        }
    }
}
void admin::combineUserCards() {

}