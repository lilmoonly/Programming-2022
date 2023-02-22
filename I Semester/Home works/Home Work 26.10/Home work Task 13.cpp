#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x;
    double h;
    double e = pow(10, -5);
    double sum = M_PI;
    double x_list[10],y_list[10], s_list[10], p_list[10];

    cout<<"Enter x: "<<endl;
    cin>>x;
    cout<<"Enter h: "<<endl;
    cin>>h;

    for (int i = 0; i < 10; ++i ){

        x_list[i] = x + h * i;
        y_list[i] = M_PI / 2 - atan(x);

        for (int k = 1; 1 / x*pow(x,k) - (1/ x*pow(x,k+2) >= e); k += 2){
            sum +=   1 / x*pow(x,k);
            s_list[i] = sum;
        }
        sum = M_PI;
        p_list[i] = abs((s_list[i] - y_list[i]) / y_list[i]) * 100;


    }
    cout << endl << "X   S   Y   Pohubka";
    for (int i = 0; i < 10; ++i)
    {
        cout << endl << x_list[i] << "  " << s_list[i] << "  " << y_list[i] << "  " << p_list[i];
    }
    return 0;
}
