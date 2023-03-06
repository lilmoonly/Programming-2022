#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Person{
protected:
    string Name;
    int Age;
public:
    Person():Name(" "), Age(0){}
    Person(string name, int age): Name(name), Age(age){}
    virtual void input(istream& is){
        is>>Age>>Name;
    }
    virtual int get_Salary() = 0;
    friend istream& operator>>(istream& is, Person& person) {
        person.input(is);
        return is;
    }
    virtual void output(ostream& os){
        os <<"Name: "<<Name<<endl<<"Age: "<<Age<<endl;
    }
    bool operator<(Person& person){
        return Name<person.Name;
    }
};
class Student: public Person{
private:
    int Group;
    double Scholarship;
public:
    void input(istream& is){
        Person::input(is);
        is>>Group>>Scholarship;
    }
    void output(ostream& os){
        Person::output(os);
        os<<"Group: "<<Group<<endl<<"Scholarship: "<<Scholarship<<endl;
    }
    int get_Salary(){
        return Scholarship;
    }
};
class Worker: public Person{
private:
    double Salary;
public:
    Worker(): Salary(0){}
    void input(istream& is){
        Person::input(is);
        is>>Salary;
    }
    void output(ostream& os){
        Person::output(os);
        os<<"Salary: "<<endl;
    }
    int get_Salary(){
        return Salary;
    }

};
int main() {
    vector<Person*> list;
    ifstream  file("data.txt");
    while(!file.eof()){
        int Number;
        Person* temp;
        file>>Number;
        cout<<"a";
        if(Number == 1){
            temp = new Student();
        }
        else{
            temp = new Worker();
        }
        temp->input(file);
        list.push_back(temp);
        temp->output(cout);

    };
    for(int i = 0; i < list.size(); i++){
        list[i]->output(cout);
    }
    sort(list.begin(), list.end());
    for(int i = 0; i < list.size(); i++){
        list[i]->output(cout);
    }
    file.close();
    return 0;
}
