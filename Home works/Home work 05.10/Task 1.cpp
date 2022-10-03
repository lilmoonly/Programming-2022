#include <iostream>
using namespace std;
int main() {
    int sec;
    int min;
    int hour;
    cout << "Enter the count of second: " << endl;
    cin>>sec;
    min = sec / 60 % 60;
    hour = sec / 3600 % 24;
    if (min>1) {
        if (hour>1){
            cout<<hour<<" hours and "<<min<<" minutes have passed";
        }
        else if (hour == 1) {
            cout<<hour<<" hour and "<<min<<" minutes have passed";
        }
        else {
            cout<<min<<" minutes have passed";
        }
    }
    else if (hour>1) {
        if (min == 1) {
            cout<<hour<<" hours and "<<min<<" minute have passed";
        }
        else {
            cout<<hour<<" hours have passed";
        }
    }
    else if (hour == 1 and min == 1) {
        cout<<hour<<" hour and "<<min<<" minute have passed";
    }
    else if (hour == 1) {
        cout<<hour<<" hour have passed";
    }
    else {
        cout<<min<<" minute have passed";
    }
    return 0;
}
