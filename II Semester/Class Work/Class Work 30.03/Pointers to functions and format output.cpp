#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;
string Table(double(*f)(double ), double min, double max, double step){
    stringstream table;
    cout<<"|"<<setw(8)<<"x"<<setw(8)<<"|"<<setw(15)<<"f(x)"<<setw(8)<<"|"<<endl;
    table << "|"<<setw(8)<<"x"<<setw(8)<<"|"<<setw(15)<<"f(x)"<<setw(8)<<"|"<<endl;
    for(double i = min; i < max; i+=step ){
        table<<"|"<<setw(8)<<i<<setw(8)<<"|"<<setw(15)<<f(i)<<setw(8)<<"|"<<endl;
        cout<<"|"<<setw(8)<<i<<setw(8)<<"|"<<setw(15)<<f(i)<<setw(8)<<"|"<<endl;
    }
    return table.str();
}

int main() {
    string st1 = Table(sin, 1,3,0.2);
    string st2 = Table([](double x){return sin(x) + 8* tan(x) - 24*pow(x, 2);}, -1, 5, 0.3);

    ofstream file1("result.txt");
    file1<<"sin(x)"<<endl<<st2;
    file1<<"sin(x) + 8* tg(x) - 24*x^2"<<endl<<st2;
    return 0;
}
