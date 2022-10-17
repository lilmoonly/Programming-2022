//За введеною датою Day, Month (цілі числа 1-31,1-12) вивести знак Зодіаку, для цієї дати.
#include <iostream>
using namespace std;
int main() {
    int day;
    int month;
    cout<<"Enter the number of day: "<<endl;
    cin>>day;
    cout<<"Enter the number of month: "<< endl;
    cin>>month;
    if (month <= 12 and month>0 and day <= 31 and day>0){

        if (day >= 21 and day <=31 and month == 3 or day >= 19 and day <= 19 and month == 4){
            cout<<"You are Aries"<<endl;
        }
        else if (day >= 20 and day <= 30 and month == 4 or day >= 1 and day <= 20 and month == 5){
            cout<<"You are Taurus"<<endl;
        }
        else if (day >= 21 and day <= 31 and month == 5 or day >= 1 and day <= 20 and month == 6){
            cout<<"You are Gemini"<<endl;
        }
        else if (day >= 21 and day <= 30 and month == 6 or day >= 1 and day <= 22 and month == 7){
            cout<<"You are Cancer"<<endl;
        }
        else if (day >= 23 and day <= 31 and month == 7 or day >= 1 and day <= 22 and month == 8){
            cout<<"You are Leo"<<endl;
        }
        else if (day >= 23 and day <= 31 and month == 8 or day >= 1 and day <= 22 and month == 9){
            cout<<"You are Virgo"<<endl;
        }
        else if (day >= 23 and day <= 30 and month == 9 or day >= 1 and day <= 22 and month == 10){
            cout<<"You are Libra"<<endl;
        }
        else if (day >= 23 and day <= 31 and month == 10 or day >= 1 and day <= 21 and month == 11){
            cout<<"You are Scorpio"<<endl;
        }
        else if (day >= 22 and day <= 30 and month == 11 or day >= 1 and day <= 21 and month == 12){
            cout<<"You are Sagittarius"<<endl;
        }
        else if (day >= 22 and day <= 31 and month == 12 or day >= 1 and day <= 19 and month == 1){
            cout << "You are Capricorn" << endl;
        }
        else if (day >= 20 and day <= 31 and month == 1 or day >= 1 and day <= 18 and month == 2){
            cout << "You are Aquarius" << endl;
        }
        else if (day >= 19 and day <= 28 and month == 2 or day >= 1 and day <= 20 and month == 3){
            cout << "You are Aquarius" << endl;
        }
    }
    else{
        cout<<"Incorrect date"<<endl;
    }
    return 0;
}
