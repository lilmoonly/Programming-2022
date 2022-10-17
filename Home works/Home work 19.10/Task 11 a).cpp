#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    double count = 0;
    int school[2] = {0,0};
    int buildings[100][2];
    double distances[100];
    cout<<"Enter a number of house(n<100): "<< endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        cout<<"Enter x and y: "<<endl;
        cin>>buildings[i][0]>>buildings[i][1];
        distances[i] = sqrt(((pow(buildings[i][0]-school[0], 2)) + (pow(buildings[i][1]-school[1], 2))));
        cout<<"Distance to "<< i + 1<< " building: "<<distances[i]<<endl;
    }
    for ( double & i : distances){
        count += i;
    }
    cout<<"Mean distance: "<<count/n<<endl;


    return 0;
}
