#include <iostream>
#include "person.h"
#include "user.h"
#include "admin.h"
#define MAXPERSON 10

using namespace std;
void pauseAndClearScreen(){
    system("pause");
    system("cls");
}
void createPersonList(person *list[MAXPERSON]){
    admin *a = new admin();
    user *b = new user();

    a->setPersonType(1);
    a->setId(1234);
    a->setName("hakki");
    a->setSurname("hakli");

    b->setPersonType(0);
    b->setId(4321);
    b->setName("burcin");
    b->setSurname("keskin");

    card* c1 = new card();
    card *c2 = new card();
    c1->setBalance(750);
    c2->setBalance(250);
    b->setCards(c1,c2,1);

    list[0] = a;
    list[1] = b;
    int i;
    for (i = 2; i < MAXPERSON; i++) {
        person *p = new person();
        list[i]=p;
        list[i]->setPersonType(0);
        list[i]->setId(0);
        list[i]->setName(" ");
        list[i]->setSurname(" ");
    }
}

void userTransactions(int i, person *list[MAXPERSON]){
    int number, cardNumber, payment;;

    while(1){
        printf("1- Bakiye yukle\n2- Kart okut\n3- Kart durumunu goster\n4- Ana menu\n");
        cin>>number;
        switch (number) {
            case 1:
                puts("Hangi kartiniza yukleme yapmak istiyorsunuz? 1/2");
                cin>>cardNumber;
                puts("Ne kadar yukleme yapmak istiyorsunuz.");
                cin>>payment;
                if(cardNumber==1){
                    ((user *)(list[i]))->loadBalance(((user *)(list[i]))->getCard1(),payment);
                }
                else if(cardNumber == 2){
                    ((user *)(list[i]))->loadBalance(((user *)(list[i]))->getCard2(),payment);
                }
                pauseAndClearScreen();
                break;
            case 2:
                puts("Hangi kartinizi kullanmak istiyorsunuz? 1/2");
                cin>>cardNumber;
                if(cardNumber==1){
                    ((user *)(list[i]))->readCard(((user *)(list[i]))->getCard1());
                }
                else if(cardNumber == 2){
                    ((user *)(list[i]))->readCard(((user *)(list[i]))->getCard2());
                }
                pauseAndClearScreen();
                break;
            case 3:
                cout<<((user *)(list[i]))->showCardStatus(((user *)(list[i]))->getCard1())<<endl;
                cout<<((user *)(list[i]))->showCardStatus(((user *)(list[i]))->getCard2())<<endl;
                pauseAndClearScreen();
                break;
            case 4:
                system("cls");
                return;
            default:
                puts("yanlis giris yaptiniz");
        }
    }
}
void adminTransactions(int i, person *list[MAXPERSON]){
    int number;

    while(1){
        system("cls");
        printf("1- Kullanici olustur\n2- Kullanici sil\n3- Kisi durumunu goster\n4- Kullanici bul"
                       "\n5- Kullanici kartlarini birlestir\n6- Ad soyad degistir\n7- Ana menu\n");
        cin>>number;
        switch (number) {
            case 1:
                system("cls");
                ((admin *)(list[i]))->createUser(list);
                break;
            case 2:
                system("cls");
                ((admin *)(list[i]))->deleteUser(list);
                pauseAndClearScreen();
                break;
            case 3:
                system("cls");
                ((admin *)(list[i]))->showUserStatus(list);
                pauseAndClearScreen();
                break;
            case 4:
                system("cls");
                ((admin *)(list[i]))->showPersonStatus(list);
                pauseAndClearScreen();
                break;
            case 5:
                system("cls");
                ((admin *)(list[i]))->combineUserCards(list);
                pauseAndClearScreen();
                break;
            case 6:
                system("cls");
                ((admin *)(list[i]))->renameUser((person *)(((admin *)(list[i]))->findUser(list)));
                pauseAndClearScreen();
                break;
            case 7:
                system("cls");
                return;
            default:
                puts("yanlis giris yaptiniz");
        }
    }
}
void isItAdmin(person *list[MAXPERSON]){
    int id,i;
    puts("Yonetici id giriniz:");
    cin>>id;
    for (i = 0; i < MAXPERSON; ++i) {
        if (list[i]->getId()==id && list[i]->getPersonType()=="Admin"){
            adminTransactions(i,list);
            break;
        }
    }
    puts("Boyle bir yonetici yok");
}
void isItUser(person *list[MAXPERSON]){
    int id,i;
    puts("Kullanici id giriniz:");
    cin>>id;
    for (i = 0; i < MAXPERSON; ++i) {
        if (list[i]->getId()==id && list[i]->getPersonType()=="User"){
            userTransactions(i,list);
            break;
        }
    }
    puts("Boyle bir kullanici yok");
}
void menu(person *list[MAXPERSON]){
    while(1){
        puts("1- Yonetici islemleri");
        puts("2- Kullanici islemleri");
        puts("3- Cikis");
        int a;
        cin>>a;
        switch (a) {
            case 1:
                system("cls");
                isItAdmin(list);
                break;
            case 2:
                system("cls");
                isItUser(list);
                break;
            case 3:
                return;
            default:
                puts("yanlis giris yaptiniz");
                pauseAndClearScreen();
        }
    }
}
int main() {
    person *persons[MAXPERSON];
    createPersonList(persons);
    menu(persons);
    return 0;
}