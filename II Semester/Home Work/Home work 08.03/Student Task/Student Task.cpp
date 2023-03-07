#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class CheatSheet{
protected:
    string Subject;
    int Number;
public:
    CheatSheet(): Subject(""), Number(0){}

    virtual void input(istream& is) = 0;
    virtual void output(ostream& os) = 0;

    friend istream& operator>>(istream& is, CheatSheet& cheat){
        cheat.input(is);

        return is;
    }
    friend ostream& operator<<(ostream& os, CheatSheet& cheat){
        cheat.output(os);

        return os;
    }
    string getSubject(){
        return Subject;
    }

    int getNumber(){
        return Number;
    }

    virtual string getDevice() = 0;
};
class PaperCheat: public CheatSheet{
private:
    double Size;
    string Place;
public:
    PaperCheat(): Size(0), Place(""){}

    void input(istream& is){
        is>>Subject>>Number>>Size>>Place;
    }
    void output(ostream& os){
        os<<"Subject - "<<Subject<<endl<<"Number - "<< Number<< endl<< "Size - "<< Size<<"cm^2"<<endl<< "Place - "<<Place;
    }
    string getDevice(){
        return "";
    }
};
class ElectronicCheat: public CheatSheet{
private:
    string Device;
public:
    ElectronicCheat():Device(""){}

    void input(istream& is){
        is>>Subject>>Number>>Device;
    }

    void output(ostream& os){
        os<<"Subject - "<<Subject<<endl<<"Number - "<<Number<<endl<<"Device - "<<Device<<endl;
    }
    string getDevice(){
        return Device;
    }

};
class Student{
private:
    string* FullName;
    string Group;
    vector<CheatSheet*> CheatList;
public:
    Student():Group(""){
        FullName = new string[3];
    }
    friend istream& operator>>(istream& is, Student& student) {
        student.FullName = new string[3];
        is >> student.FullName[0] >> student.FullName[1] >> student.FullName[2] >> student.Group;

        return is;
    }
    void addCheat(CheatSheet* cheat){
        CheatList.push_back(cheat);
    }
    vector<CheatSheet*> getCheat(){
        return CheatList;
    }
};
int main() {
    vector<Student> StudentList;
    int index = -1;
    ifstream file_1("data_1.txt");

    while (!file_1.eof()){
        int Numb;
        CheatSheet* temp;
        file_1>>Numb;
        if(Numb == -1){

            Student* student = new Student;
            file_1>>*student;
            StudentList.push_back(*student);
            index++;
        }
        if(Numb == -2 ){
            temp = new PaperCheat;
            temp->input(file_1);
            StudentList[index].addCheat(temp);
        }
        if(Numb == -3 ){
            temp = new ElectronicCheat;
            temp->input(file_1);
            StudentList[index].addCheat(temp);
        }

    }
    file_1.close();
    vector<CheatSheet*> allCheats;

    for (int i = 0; i < StudentList.size(); i++) {
        vector<CheatSheet*> tempArr = StudentList[i].getCheat();
        for (int j = 0; j < tempArr.size(); j++) {
            allCheats.push_back(tempArr[j]);
        }
    }

    ofstream file_2("return_1.txt");
    sort(allCheats.begin(), allCheats.end(), [](CheatSheet* a, CheatSheet* b) {return a->getNumber() < b->getNumber(); });

    for (int i = 0; i < allCheats.size(); i++) {
        allCheats[i]->output(file_2);
    }
    file_2 << "-------"<<endl;
    sort(allCheats.begin(), allCheats.end(), [](CheatSheet* a, CheatSheet* b) {return a->getSubject() < b->getSubject(); });

    for (int i = 0; i < allCheats.size(); i++) {
        allCheats[i]->output(file_2);
    }

    file_2.close();

    ofstream file_3("return2.txt");

    int counter = 0;

    for (int i = 0; i < allCheats.size(); i++) {
        if (allCheats[i]->getDevice() == "Mobile") {
            allCheats[i]->output(file_3);
            counter++;
        }
    }

    file_3 << "Amount: " << counter << endl;

    file_3.close();

    return 0;
}
