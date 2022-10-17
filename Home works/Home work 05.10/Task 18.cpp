//Знайти суму  цифр введеного трьохзначного числа
#include <iostream>
using namespace std;
int main() {
    int num;
    int a;
    int b;
    int c;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    if (num >=100 and num <= 999) {
        a = num % 10;
        b = num % 100 / 10;
        c = num % 1000 / 100;
        cout << a + b + c << endl;
    }
    else{
        cout<<"Incorrect number"<<endl;
    }
    return 0;
}
