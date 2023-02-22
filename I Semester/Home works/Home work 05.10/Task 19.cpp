//Перевірити чи введені три натуральні числа можуть представляти час доби в годинах, хвилинах, секундах
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
    if (0<= a and a < 24 and b >= 0 and b < 60 and c >= 0 and c < 60) {
        cout << "Yes, you can do this!" << endl;
    }
    else if (0<= b and b < 24 and a >= 0 and a < 60 and c >= 0 and c < 60) {
        cout << "Yes, you can do this!" << endl;
    }
    else if (0<= c and c < 24 and b >= 0 and b < 60 and a >= 0 and a < 60) {
        cout << "Yes, you can do this!" << endl;
    }
    else {
        cout<< "No, you can't do this!"<< endl;
    }
    return 0;
}
