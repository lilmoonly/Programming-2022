#include <iostream>
using namespace std;
class Item {
private:
    string name;
    double price;
    int code;
public:
    Item() : name(" "), price(0), code(1) {}

    Item(string n, double p, int c) : name(n), price(p), code(c) {}

    Item(const Item &item) : name(item.name), price(item.price), code(item.code) {}

    double GetPrice() {
        return price;
    }

    string GetName() {
        return name;
    }
    int GetCode(){
        return code;
    }
    friend ostream &operator<<(ostream &os, const Item &p) {
        os << "Item: " << endl << "Name --- " << p.name << endl << "Price --- " << p.price << endl << "Code --- "
           << p.code;
        return os;
    };

    friend istream& operator>>(istream& is, Item& item) {
        cout << "Enter name:" << endl;
        is >> item.name;
        cout << "Enter price:" << endl;
        is >> item.price;
        cout << "Enter code:" << endl;
        is >> item.code;

        return is;
    }
};

class Cart{
private:
    int cur;
    Item* items;
    int* counts;
public:
    Cart(): cur(0){

        items = new Item[100];
        counts = new int[100]{};

    }
    int* getCount(){
        return counts;
    }
    Item* getItem(){
        return items;
    }
    int CountOfItems(){
        int n = 0;
        for(int i = 0; i < cur; i++){
            n += counts[i];
        }
        return n;
    }
    void addItem(Item item, int count){
        items[cur] = item;
        counts[cur] = count;
        cur++;
    }
    void removeItem(Item item, int count){
        for(int i = 0; i < cur; i++){
            if(items[i].GetCode() == item.GetCode() && counts[i] == count){
                for(int q = i; q<cur; q++){
                    items[q] = items[q+1];
                    counts[q] = counts[q+1];
                }
                cur--;
                break;
            }
            else if(items[i].GetCode() == item.GetCode() && counts[i] < count){
                cout<<"Incorrect count of product"<<endl;
                break;
            }
            else{
                counts[i]-=count;
                break;
            }
        }
    }
    double SumOfPrices(){
        double sum = 0;

        for (int i = 0; i < cur; i++) {
            sum += items[i].GetPrice() * counts[i];
        }
        return sum;
    }
    friend ostream& operator<<(ostream& os, Cart& cart) {
        os << "There are " << cart.CountOfItems()<< endl << "Total price is " << cart.SumOfPrices() << "$" << endl;
        os << "List:" << endl;
        for (int i = 0; i < 100; i++) {
            if(cart.getCount()[i] != 0) {
                os << cart.getItem()[i].GetName() << " - " << cart.getCount()[i] << endl;
            }
        }

        return os;
    }

};
int main() {

    Item i1;
    Item i2;
    Item i3;

    Cart c;
    cin>>i1;
    cin>>i2;
    cin>>i3;

    c.addItem(i1, 3);
    c.addItem(i2, 5);
    c.addItem(i3, 8);

    cout<< c;
    c.removeItem(i1, 3);
    c.removeItem(i2, 2);

    cout<<c;

    return 0;
}