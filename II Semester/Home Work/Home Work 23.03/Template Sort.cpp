#include <iostream>
using namespace std;
struct Person{
    string name;
    string address;
    Person(string name, string address): name(name), address(address){}

    bool operator<(Person& other){
        if(name < other.name){
            return true;
        }
        return false;
    }
    bool operator>(Person& other){
        if(name > other.name){
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, Person person){
        os<<person.name;
        return os;
    }
};
template <typename T>
void sort(T* array, size_t size){
    int i, j;
    for( i = 0; i < size - 1 ; i++){
        for( j= 0 ; j < size - i - 1; j++ ){
            if(array[j]>array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}
template <typename T>
void print(T* array, size_t size){
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
}
int main() {
    //int array
    int* array1 = new int[5]{2,3,1,6,7};
    cout<<"Unsorted - ";
    print(array1,5);
    cout<<endl;
    sort(array1, 5);
    cout<<"Sorted - ";
    print(array1,5);
    cout<<endl;

    //string array
    string* array2 = new string[5]{"Phone", "Clock", "Apple", "Window", "Dog"};
    cout<<"Unsorted - ";
    print(array2,5);
    cout<<endl;
    sort(array2, 5);
    cout<<"Sorted - ";
    print(array2,5);
    cout<<endl;

    //Person array
    Person* array3 = new Person[5]{Person("Andrew","12"), Person("Niko", "13"), Person("Lubomir", "22"), Person("Kate", "01"), Person("Jake", "02")};
    cout<<"Unsorted - ";
    print(array3, 5);
    cout<<endl;
    sort(array3, 5);
    cout<<"Sorted - ";
    print(array3,5);
    cout<<endl;
    return 0;
}
