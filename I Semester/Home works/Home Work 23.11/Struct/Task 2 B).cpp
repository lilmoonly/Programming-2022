#include <iostream>
using namespace std;
struct ColorBall {
    int radius, ball_number;
    string color;
};
ColorBall max_radius_ball(ColorBall *array, int n){
    int max_radius = 1;
    for(int i = 0; i < n; ++i){
        if (max_radius < array[i].radius){
            max_radius = array[i].radius;
        }
    }
    ColorBall ball;
    for(int i = 0; i < n; ++ i){
        if(max_radius == array[i].radius){
            ball = array[i];
        }
    }
    return ball;
}
void Print(ColorBall array){
    cout<<"Ball`s number -- "<<array.ball_number<<endl;
    cout<<"Ball`s color -- "<<array.color<<endl;
    cout<<"Ball`s radius -- "<<array.radius<<endl;
}
int main() {
    int n = 2;
    ColorBall *array = new ColorBall[n];
    for(int i = 0; i < n; ++i){
        cout<<"Ball number "<<i+1<<endl;
        array[i].ball_number = i+1;
        cout<<"Enter color: "<<endl;
        cin>>array[i].color;
        cout<<"Enter radius: "<<endl;
        cin>>array[i].radius;
    }

    ColorBall ball = max_radius_ball(array,n);
    Print(ball);
    return 0;
}
