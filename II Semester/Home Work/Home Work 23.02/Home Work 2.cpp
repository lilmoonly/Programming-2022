#include <iostream>
using namespace std;
class Student{
private:
    string name;
    string specialty;
    int id_number;
public:
    Student():name(" "), specialty(" "), id_number(0){}
    Student(string name, string specialty, int id_number):name(name), specialty(specialty), id_number(id_number){}
    Student(const Student& student): name(student.name), specialty(student.specialty), id_number(student.id_number){}

    string getName(){
        return name;
    }

    string getSpecialty(){
        return specialty;
    }

    int getId_number(){
        return id_number;
    }

    friend istream& operator>>(istream& is, Student& student) {
        cout << "Enter name:" << endl;
        is >> student.name;
        cout << "Enter specialty:" << endl;
        is >> student.specialty;
        cout << "Enter ID number:" << endl;
        is >> student.id_number;

        return is;
    }
    friend ostream& operator<<(ostream& os, Student& student) {
        os << "Name: " << student.name << endl << "Specialty: " << student.specialty << endl << "ID number: "
           << student.id_number << endl;
    }
};

class Course{
private:
    string courseName;
    string courseSpecialty;
    int courseNumber;
public:
    Course():courseName(" "), courseSpecialty(" "), courseNumber(0){}
    Course(string name, string specialty, int number):courseName(name), courseSpecialty(specialty), courseNumber(number){}
    Course(const Course& course): courseName(course.courseName), courseSpecialty(course.courseSpecialty), courseNumber(course.courseNumber){}

    string getCourseName(){
        return courseName;
    }

    string getCourseSpecialty(){
        return courseSpecialty;
    }

    int getCourseNumber(){
        return courseNumber;
    }

    friend istream& operator>>(istream& is, Course& course) {
        cout << "Enter course name:" << endl;
        is >> course.courseName;
        cout << "Enter course specialty:" << endl;
        is >> course.courseSpecialty;
        cout << "Enter course number:" << endl;
        is >> course.courseNumber;

        return is;
    }
    friend ostream& operator<<(ostream& os, Course& course) {
        os <<"Course: "<<endl<< "Name: " << course.courseName << endl << "Specialty: " << course.courseSpecialty <<
        endl << "Number: "<< course.courseNumber << endl<<endl;
    }
};

class University{
private:
    string universityName;
    string universityLocation;
    Student* studentArray;
    Course* courseArray;
    int countStudent;
    int countCourse;
public:
    University():universityName(" "), universityLocation(" "), countStudent(0), countCourse(0){
        studentArray = new Student[0];
        courseArray = new Course[0];
    }
    University(string univName, string univLoc):universityName(univName), countStudent(0),
    universityLocation(univLoc), countCourse(0){
        studentArray = new Student[100];
        courseArray = new Course[100];
    }
    Student* getStudentArray(){
        return studentArray;
    }
    Course* getCourseArray(){
        return courseArray;
    }
    string getUniversityName(){
        return universityName;
    }
    string getUniversityLocation(){
        return universityLocation;
    }
    void addStudent(Student student){
        studentArray[countStudent] = student;
        countStudent++;
    }
    void addCourse(Course course){
        courseArray[countCourse] = course;
        countCourse++;
    }
    void removeStudent(Student student){
        for(int i = 0; i < countStudent; i++){
            if(studentArray[i].getId_number() == student.getId_number()){
                for(int j = i; j < countStudent; j++){
                    studentArray[j] = studentArray[j+1];
                }
            }
        }
        countStudent--;
    }
    void removeCourse(Course course){
        for(int i = 0; i < countCourse; i++){
            if(courseArray[i].getCourseName() == course.getCourseName()){
                for(int j = i; j < countCourse; j++){
                    courseArray[j] = courseArray[j+1];
                }
            }
        }
    }
    void studentForCourse(string courseName) {
        cout<<courseName<<" suitable for such students: "<<endl<<endl;
        for(int i = 0; i < countCourse; i++){
            if(courseName==courseArray[i].getCourseName()){
                for(int j = 0; j<countStudent; j++){
                    if(courseArray[i].getCourseSpecialty()==studentArray[j].getSpecialty()){
                        cout<<studentArray[j]<<endl;
                    }
                }
            }
        }
    }
    void courseForStudent(string name){
        cout<<name<<" these courses will do:"<<endl<<endl;
        for(int i = 0; i < countStudent; i++){
            if(name==studentArray[i].getName()){
                for(int j = 0; j<countCourse; j++){
                    if(studentArray[i].getSpecialty()==courseArray[j].getCourseSpecialty()){
                        cout<<courseArray[j];
                    }
                }
            }
        }
    }

    void printStudent(){
        for(int i = 0; i < countStudent;i++) {
            if (studentArray[i].getName() != " ") {
                cout<<"Student: "<<endl;
                cout << "Name: " << studentArray[i].getName() << endl << "Speciality: "
                     << studentArray[i].getSpecialty() << endl
                     << "ID number: " << studentArray[i].getId_number() << endl<<endl;
            }
        }
    }
    void printCourse(){
        for(int i = 0; i < countCourse; i++) {
            if (courseArray[i].getCourseNumber() != 0) {
                cout<<"Course:"<<endl;
                cout << "Name: " << courseArray[i].getCourseName() << endl << "Speciality: "
                     << courseArray[i].getCourseSpecialty()
                     << endl << "Number: " << courseArray[i].getCourseNumber() << endl<<endl;
            }
        }
    }
};
int main() {
    University u("LNU", "Lviv");

    Student s1("Jone", "Math", 121);
    Student s2("Kate", "Math", 121);
    Student s3("Andrew", "Bio", 125);
    Student s4("Nikola", "IT", 112);

    Course c1("Discrete Math", "Math", 12);
    Course c2("Math Analysis", "Math", 15);
    Course c3("Bioengineering", "Bio", 7);
    Course c4("Programming", "IT", 2);

    u.addCourse(c1);
    u.addCourse(c2);
    u.addCourse(c3);
    u.addCourse(c4);

    u.addStudent(s1);
    u.addStudent(s2);
    u.addStudent(s3);
    u.addStudent(s4);


    u.printCourse();
    u.printStudent();
    cout<<"----------"<<endl<<endl;
    u.studentForCourse("Discrete Math");
    u.courseForStudent("Kate");
    cout<<"----------"<<endl<<endl;
    u.removeStudent(s4);
    u.removeCourse(c4);

    u.printCourse();
    u.printStudent();
    return 0;
}
