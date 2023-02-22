#include <iostream>
using namespace std;
class Client{
private:
    string name;
    string address;
    int number;
public:
    Client(): name(" "), address(" "), number(0){}
    Client(string name, string address, int number): name(name), address(address), number(number){}
    Client(const Client& p): name(p.name), address(p.address), number(p.number){}

    friend istream& operator>>(istream& is, Client& client) {
        cout << "Enter name:" << endl;
        is >> client.name;
        cout << "Enter address:" << endl;
        is >> client.address;
        cout << "Enter number:" << endl;
        is >> client.number;

        return is;
    }
    friend ostream& operator<<(ostream& os, Client& client) {
        os <<"Name: "<<client.name<<endl<<"Address: "<< client.address<<endl<<"Number: "<< client.number << endl;

        return os;
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    int getNumber(){
        return number;
    }
};
class Card{
private:
    Client clients;
    double balance;
    int numberOfBalance;

public:
    Card():clients(), balance(0), numberOfBalance(0){}

    Card(Client client, double balance, int numOfBal): clients(client), balance(balance), numberOfBalance(numOfBal){}

    double getNumberOfBalance(){
        return numberOfBalance;
    }
    double getBalance(){
        return balance;
    }
    void addMoney(double money){
                balance+=money;
    }
    void removeMoney(double money){
        if(balance<money){
                cout << "You don't have enough money" << endl;
        }
        else {
            balance -= money;
        }
    }
    bool checkFilter(int option, string text) {
        if (option == 0) {
            if (clients.getName() == text) {
                return true;
            }
        }
        else if (option == 1) {
            if (clients.getAddress() == text) {
                return true;
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& os, Card& card) {
            os << "Client" << endl << "Name: " << card.clients.getName() << endl<< "Address: "<<card.clients.getAddress()
            << endl<< "Phone number: "<<card.clients.getNumber()<< endl<< "Card number: "<<card.getNumberOfBalance()<<endl
            <<"Balance: "<<card.getBalance()<<'$'<<endl;

        return os;
    }
};
int main() {
    Card* Bank = new Card[10];
    Client c1("jone", "Lvivska 19", 3801);
    Client c2("Kate", "Lichakivska 31", 3824);
    Client c3("Niko", "Silska 5", 3845);
    Client c4("Emmi", "Doroshenka 9", 3898);
    Client c5("Andrew", "Yarmola 16", 3820);
    Client c6("Lila", "Shevchenka 15", 3835);
    Client c7("Nuke", "Lvova 59", 3866);
    Client c8("Olya", "Dzerelna 38", 3898);
    Client c9("Sasha", "Medovy 39", 3803);
    Client c10("Emin", "Ravska 89", 3808);

    Card cc1(c1, 300, 1000);
    Card cc2(c2, 500, 1001);
    Card cc3(c3, 700, 1002);
    Card cc4(c4, 3300, 1003);
    Card cc5(c5, 3700, 1004);
    Card cc6(c6, 800, 1005);
    Card cc7(c7, 7800, 1006);
    Card cc8(c8, 900, 1007);
    Card cc9(c9, 32100, 1008);
    Card cc10(c10, 3400, 1009);

    Bank[0] = cc1;
    Bank[1] = cc2;
    Bank[2] = cc3;
    Bank[3] = cc4;
    Bank[4] = cc5;
    Bank[5] = cc6;
    Bank[6] = cc7;
    Bank[7] = cc8;
    Bank[8] = cc9;
    Bank[9] = cc10;

    while(true){
        int option;
        cout<<"Search by name - 0, address -1" << endl;
        cin>>option;

        string input;
        cout<<"Enter...."<<endl;
        cin>>input;
        Card** filtered = new Card*[10];
        unsigned int count = 0;

        for (int i = 0; i < 10; i++) {
            if (Bank[i].checkFilter(option, input)) {
                filtered[count] = &Bank[i];
                cout << "#" << count << endl << Bank[i];
                count++;
            }
        }

        cout << "There are " << count << " accounts found"<<endl<<"Select one by entering its number in list" << endl;
        int n;
        cin >> n;

        cout << "Bank account selected" << endl << *filtered[n];

        cout << "0 - to add money, 1 - to remove money + amount of money: "<<endl;
        int op;
        double money;
        cin >> op >> money;

        if (op == 0) {
            filtered[n]->addMoney(money);
        }
        else if (op == 1) {
            filtered[n]->removeMoney(money);
        }

        cout << "Operation is finished!" << endl;
    }

}