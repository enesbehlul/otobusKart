#include <iostream>
#include <string>
#include "person.h"
#include "user.h"
#include "admin.h"
#define MAXPERSON 10

using namespace std;

void createPersonList(person *list[10]){
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
    card *c1 = new card();
    card *c2 = new card();
    c1->setBalance(5000);
    c2->setBalance(1000);
    cout<<c1->getBalance()<<endl;
    cout<<c2->getBalance()<<endl;
    b->card1=c1;
    cout<<b->showCardStatus(b->card1)<<endl;
    b->card2=c2;
    cout<<b->showCardStatus(b->card2);
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
void adminTransactions2(int i, person *list[10]){
    int number;
    printf("1- Kullanici olustur\n2- Kullanici sil\n3- Kisi durumunu goster\n4- Kullanici bul"
           "\n5-Kullanici kartlarini birlestir\n6- Ad soyad degistir\n7- Ana menu");
    scanf("%d",&number);
    switch (number) {
        case 1:
            ((admin *)(list[i]))->createUser(list);
            ;
            break;
        case 2:
            ((admin *)(list[i]))->deleteUser(list);
            break;
        case 3:
            ((admin *)(list[i]))->findUser(list);
            break;
        case 4:
           ((admin *)(list[i]))->showUserStatus(list);
            break;
        case 5:
            ((admin *)(list[i]))->combineUserCards(list);
            break;
        case 6:
            cout<<((admin *)(list[i]))->getSurname();
            cout<<((user *)(list[1]))->getSurname();
            break;
        case 7:
            return;
        default:
            puts("yanlis giris yaptiniz");
    }
}
void adminTransactions1(person *list[10]){
    int id,i;
    puts("Yonetici id giriniz:");
    scanf("%d",&id);
    for (i = 0; i < MAXPERSON; ++i) {
        if (list[i]->getId()==id && list[i]->getPersonType()=="Admin"){
            puts("Yoneticisiniz, yonetin o zaman, hadi, buyrun!");
            adminTransactions2(i,list);
            break;
        }
    }
}

void menu(person *list[10]){
    while(1){
        puts("1- Yonetici islemleri");
        puts("2- Kullanici islemleri");
        puts("3- Cikis");
        int a;
        scanf("%d",&a);
        switch (a) {
            case 1:
                adminTransactions1(list);
                break;
            case 2:
                break;
            case 3:
                return;
            default:
                puts("yanlis giris yaptiniz");
        }
    }
}
int main() {
    person *persons[10];
    createPersonList(persons);
    menu(persons);
    return 0;
}