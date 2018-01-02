// Created by Behlul on 21.12.2017.
#include "admin.h"
using namespace std;

admin::admin(){
    setPersonType(1);
}
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
            cin.ignore();
            getline(cin,ad);
            printf("\n\tSoyad: ");
            getline(cin,soyad);
            while(1){
                printf("\n\tId: ");
                cin>>id;
                if(id != 0)
                    break;
                else
                    cout<<"Kullanici id 0 olamaz";
            }
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
    if(p != nullptr && p->getId()!= 0){
    cout<<"\tAd: " <<p->getName()<<"\n\tSoyad: " <<p->getSurname()<<endl;
    }
    else
        cout<<"\tAd: Tanimlanmamis\n\tSoyad: Tanimlanmamis\n\tKullanici turu: Tanimlanmamis"<<endl;
}
void admin::showUserStatus(person * list[10]) {
    user *a = new user();
    person *p = new person();
    a = findUser(list);
    p = a;
    if(a != nullptr && a->getPersonType()=="User" && a->getId()!=0){
        cout<<"\tAd: " <<a->getName()<<"\n\tSoyad: " <<a->getSurname()<<"\n\tKullanici turu: "<<a->getCard1()->getCardType()<<"\nKart bilgileri\n\t1.Kart: "<<a->showCardStatus(a->getCard1())<<" tl\n\t2.Kart: "<<a->showCardStatus(a->getCard2())<<" tl\n";
    }
    else if(p != nullptr && p->getPersonType()=="Admin"){
        cout<<"\tAd: " <<a->getName()<<"\n\tSoyad: " <<a->getSurname()<<"\n\tKullanici turu: Yonetici"<<endl;
    }
    else
        cout<<"\tAd: Tanimlanmamis\n\tSoyad: Tanimlanmamis\n\tKullanici turu: Tanimlanmamis"<<endl;
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
        puts("Yeni ad giriniz:");
        string ad, soyad;
        cin.ignore();
        getline(cin,ad);
        puts("Yeni soyad giriniz:");
        getline(cin,soyad);
        person->setName(ad);
        person->setSurname(soyad);
    }
}