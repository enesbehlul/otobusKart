// Created by Behlul on 21.12.2017.
#include "admin.h"
using namespace std;

admin::admin(){}
void admin::createUser(person * list[10]) {
    int i, cardType;
    unsigned int id;
    string ad, soyad;
    for (i = 0; i < 10; i++) {
        if(list[i]->getId()==0){
            user *u = new user();
            card *c1 = new card();
            card *c2 = new card();
            puts("Bilgileri giriniz...");
            printf("\nKart sahibi>\n\tAd: ");
            cin>>ad;
            printf("\n\tSoyad: ");
            cin>>soyad;
            printf("\n\tId: ");
            cin>>id;
            u->setPersonType(0);
            u->setName(ad);
            u->setSurname(soyad);
            u->setId(id);
            puts("Normal kullanici ise 0, ogrenci ise 1, emekli ise 2 giriniz.");
            cin>>cardType;
            u->setCards(c1,c2,cardType);
            list[i]=u;
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
    person *p= new person();
    p = findUser(list);
    if(p != nullptr){
    cout<<"\tAd: " <<p->getName()<<"\n\tSoyad: " <<p->getSurname()<<endl;
    }
}
void admin::showUserStatus(person * list[10]) {
    user *a = new user();
    a = findUser(list);
    if(a != nullptr){
        cout<<"\tAd: " <<a->getName()<<"\n\tSoyad: " <<a->getSurname()<<"\nKart bilgileri\n\t1.Kart: "<<a->showCardStatus(a->getCard1())<<" tl\n\t2.Kart: "<<a->showCardStatus(a->getCard2())<<" tl\n";
    }
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
    return nullptr;
}
void admin::combineUserCards(person * list[10]) {
    user *a = findUser(list);
    if(a != nullptr){
        a = *a+a;
        a->getCard2()->setBalance(0);
        cout<<a->showCardStatus(a->getCard1())<<endl;
        int i;
        for (i = 0; i <10; ++i) {
            if (list[i]->getId()==a->getId()){
                list[i]=a;
            }
        }
    }
}
unsigned int admin::scanId(){
    unsigned int id;
    puts("Id giriniz.");
    cin>>id;
    return id;
}
void admin::renameUser(person *person) {
    if(person != nullptr){
        puts("Yeni adı giriniz:");
        string ad, soyad;
        cin>>ad;
        puts("Yeni soyadı giriniz:");
        cin>>soyad;
        person->setName(ad);
        person->setSurname(soyad);
    }
}