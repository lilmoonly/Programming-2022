#include <iostream>
using namespace std;
class Car{
private:
    string color;
    string name;
    int price;
public:
    Car():price(0),name(""),color(""){

    }
    Car(int p, string n, string c):price(p),name(n),color(c){
    }
    string Get_Name(){
        return name;
    }
    string Get_color(){
        return color;
    }
    int Get_Price(){
        return price;
    }
    void Set_Price(int new_price){
        price = new_price;
    }
    void Input(){
        cout<<"Enter name of car: "<<name<<endl;
        cin>>name;
        cout<<"Enter color of car"<<color<<endl;
        cin>>color;
        cout<<"Enter price of car"<<price<<endl;
    }
    void Print(){
        cout<<"Name of car -- "<<name<<endl;
        cout<<"Color of car -- "<<color<<endl;
        cout<<"Price of car -- "<<price<<endl;
    }

};
int main() {
    string color;
    Car car1;
    Car car2(1000,"Opel","red");
    int n;
    cout<<"Enter amount of car"<<endl;
    cin>>n;
    Car *array = new Car[n];
    array[0]=car1;
    array[1]=car2;
    for (int i = 2; i<n;++n){
        array[i].Input();
    }
    cout<<"Enter color"<<endl;
    cin>>color;
    for(int i = 0;i<n;++i){
        if(array[i].Get_color()==color){
            array[i].Print();
        }
    }
    for(int i = 0; i<n;i++){
        if(array[i].Get_color()=="gold"){
            array[i].Set_Price(array[i].Get_Price()*0.9);
            }
        array[i].Print();
        }

    return 0;

}
