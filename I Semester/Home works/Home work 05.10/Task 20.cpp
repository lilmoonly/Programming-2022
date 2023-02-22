//Перевірити, чи введені три натуральні числа можуть бути послідовними членами деякої арифметичної  послідовності?
#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int c;
    cout<<"Enter the first number: "<< endl;
    cin>> a;
    cout<<"Enter the second number: "<< endl;
    cin>> b;
    cout<<"Enter the third number: "<< endl;
    cin>> c;
    if ((a+b)/2 == c) {
        cout<< "Yes, they can!";
    }
    else if ((a+c)/2 == b) {
        cout<< "Yes, they can!";
    }
    else if ((c+b)/2 == a) {
        cout<< "Yes, they can!";
    }
    else {
        cout<< "No, they can't!";
    }
    return 0;
}
