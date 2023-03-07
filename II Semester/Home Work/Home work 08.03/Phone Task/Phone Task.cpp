#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Phone{
protected:
    string Name;
    string Brand;
    double Price;
public:
    Phone(): Name(" "), Brand(" "), Price(0){}
    Phone(string name, string brand, double price): Name(name), Brand(brand), Price(price){}

    virtual void input(istream& is){
        is>>Name>>Brand>>Price;
    }

    virtual void output(ostream& os){
        os<< "Name - "<<Name<<endl<< "Brand - "<< Brand<< endl<< "Price - "<<Price<<'$'<< endl;
    }

    virtual double get_Price(){
        return Price;
    };
    virtual string get_AM() = 0;

};
class MobilePhone: public Phone{
private:
    string Color;
    int RAM;
public:
    void input(istream& is){
        Phone::input(is);
        is>>Color>>RAM;
    }
    void output(ostream& os){
        Phone::output(os);
        os<<"Color - "<< Color<< endl<< "RAM - "<<RAM<<"gb"<< endl;
    }
    double get_Price(){
        return Price;
    }
    string get_AM(){
        return "false";
    }
};
class RadioPhone: public Phone{
private:
    double Radius;
    string AM;
public:
    void input(istream& is){
        Phone::input(is);
        is>>Radius>>AM;
    }
    void output(ostream& os){
        Phone::output(os);
        os<<"Radius - "<<Radius<<"m"<<endl<< "Answering machine - "<< AM<< endl;
    }
    double get_Price(){
        return Price;
    }
    string get_AM(){
        return AM;
    }
};
int main() {
    vector<Phone*> list;
    ifstream file_1("data_1.txt");
    while(!file_1.eof()){
        Phone* temp;
        temp = new MobilePhone;
        temp->input(file_1);
        list.emplace_back(temp);
        temp->output(cout);
        cout<<endl;
    }
    file_1.close();
    ifstream file_2("data_2.txt");
    while(!file_2.eof()){
        Phone* temp;
        temp = new RadioPhone;
        temp->input(file_2);
        list.emplace_back(temp);
        temp->output(cout);
        cout<<endl;
    }
    double sum = 0;
    for(auto elem:list){
        sum += elem->get_Price();
    }
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = i; j < list.size(); j++)
        {
            if (list[i]->get_Price() < list[j]->get_Price())
            {
                swap(list[i], list[j]);
            }
        }
    }
    cout<<"Sum - "<<sum<<'$'<<endl<< endl;
    cout<<"Sorted: "<<endl<<endl;
    for(int i = 0; i < list.size(); i++){
        list[i]->output(cout);
        cout<<endl;
    }
    ofstream file_3("return.txt");
    for(auto elem: list){
        elem->output(file_3);
    }
    for(auto elem: list){
        if(elem->get_AM()=="true"){
            elem->output(file_3);
        }
    }
    return 0;
}
