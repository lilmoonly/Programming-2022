#include <iostream>
using namespace std;
#include <math.h>
//sum x^2, i = 0
int sum_x(int x_1[20]){
int sum_x_1=0;
for(int i = 0; i < 20; ++i){
sum_x_1 += pow(x_1[i], 2);
}
return sum_x_1;
}
//sum y^2, i = 10
int sum_y(int y_1[20]){
    int sum_y_1=0;
    for(int i = 10; i < 20; ++i){
        sum_y_1 += pow(y_1[i],2);
    }
    return sum_y_1;
}
//sum xy, i = 0
int sum_xy(int x_1[20],int y_1[20]){
    int sum_xy_1=0;
    for(int i = 0; i < 15; ++i){
        sum_xy_1 += y_1[i]*x_1[i];
    }
    return sum_xy_1;
}

int main() {
    int u;
    int *arr_x = new int[20];
    int *arr_y = new int[20];
    for (int i = 0; i < 20; ++i){
        cout<<"Enter x:"<<endl;
        cin>>arr_x[i];
    }
    for(int i = 0; i < 20; ++i){
        cout<<"Enter y:"<<endl;
        cin>>arr_y[i];
    }
    if(sum_xy(arr_x,arr_y) > 0){
        u = sum_x(arr_x);
    }
    else{
        u = sum_y(arr_y);
    }
    cout<<"u = "<<u;
    return 0;
}

