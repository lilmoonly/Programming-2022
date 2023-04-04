#include <iostream>
#include <vector>
using namespace std;
struct Milk{
    string name;
    int fatness;
    Milk(): name(""), fatness(0){}
    Milk(string name, int fatness): name(name), fatness(fatness){}

    friend ostream& operator<<(ostream& os, Milk milk){
        os<<milk.name<<' '<<milk.fatness<<'%'<<endl;
        return os;
    }
    friend istream& operator>>(istream& is, Milk milk){
        is>>milk.name>>milk.fatness;
        return  is;
    }
};

struct Date{
    int y;
    int m;
    int d;
    Date():d(0), m(0),y(0){}
    Date(int d, int m, int y ):d(d), m(m), y(y){}

    friend ostream& operator<<(ostream& os, Date date){
        os<<date.d<<'.'<<date.m<<'.'<<date.y<<endl;
    }

    friend istream& operator>>(istream& is, Date date){
        is>>date.d>>date.m>>date.y;
    }
    void addDays(int day){
        for(int i = 0; i < day; i++){
            if(d == 28){
                if(m == 2){
                    d = 0;
                    m = 3;
                }
            }
            if(d == 30){
                switch (m) {
                    case 4:
                        d = 0;
                        m = 5;
                        break;
                    case 6:
                        d = 0;
                        m = 7;
                        break;
                    case 9:
                        d = 0;
                        m = 10;
                        break;
                    case 11:
                        d = 0;
                        m = 12;
                        break;
                }
            }
            if(d == 31){
                switch (m) {
                    case 1:
                        d = 0;
                        m = 2;
                        break;
                    case 3:
                        d = 0;
                        m = 4;
                        break;
                    case 5:
                        d = 0;
                        m = 6;
                        break;
                    case 7:
                        d = 0;
                        m = 8;
                        break;
                    case 8:
                        d = 0;
                        m = 9;
                        break;
                    case 10:
                        d = 0;
                        m = 11;
                        break;
                    case 12:
                        d = 0;
                        m = 1;
                        y += 1;
                        break;
                }
            }
            d += 1;
        }
    }
};

template <typename T>
class Product{
private:
    T name;
    Date date;
    int expirationTime;
public:
    Product():name(), date(Date(1,1,2000)), expirationTime(0){}
    Product(T name, Date date, int expirationTime):name(name), date(date), expirationTime(expirationTime){}
    friend ostream& operator<<(ostream& os, Product& product){
        Date temp = product.getExpirationDate();
        os<<"Name - "<<product.name<<"Date - "<<product.date<<"Expiration date - "<<temp<<endl;
        return os;
    }

    friend istream& operator>>(istream& is, Product& product) {
        is >> product.name >> product.date >> product.expirationTime;
        return is;
    }
    Date getExpirationDate() {
        Date temp = date;
        temp.addDays(expirationTime);
        return temp;
    }
};
int main() {
    vector<Product<string>> string_vector;
    vector<Product<Milk>> milk_vector;

    Date date1(1, 1,2023);
    Product<string> ps1("Water",date1, 60);
    string_vector.push_back(ps1);

    Date date2(23, 4, 2023);
    Product<string> ps2("Tea", date2, 80);
    string_vector.push_back(ps2);

    for(auto elem: string_vector){
        cout<<elem;
    }

    cout<<"---------------"<<endl;

    Date date3(12, 6, 2023);
    Milk mk1("Milk", 30);
    Product<Milk> vm1(mk1, date3, 20);
    milk_vector.push_back(vm1);

    Date date4(13, 10, 2023);
    Milk mk2("Milk", 60);
    Product<Milk> vm2(mk2, date4, 20);
    milk_vector.push_back(vm2);

    for(auto elem: milk_vector){
        cout<<elem;
    }
    return 0;
}
