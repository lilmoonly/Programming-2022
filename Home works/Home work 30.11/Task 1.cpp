#include <iostream>
#include<math.h>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
struct Point{
    double x;
    double y;
};
class Line{
private:
    double a, b, c;
public:
    Line(): a(0), b(0), c(0){}
    Line (const Line & p):a(p.a), b(p.b), c(p.c){}
    Line(double a1, double b1, double c1): a(a1), b(b1), c(c1){}
    friend istream& operator >>(istream & is,  Line & line ){
        is>>line.a>>line.b>>line.c;
        return is;
    }
    friend ostream & operator<<(ostream & os, Line & line){
        os<<line.a<<'x'<<'+'<<line.b<<'y'<<'+'<<line.c<<'='<<'0';
        return os;
    }
    Point getInterception(Line line){
        double bottom = a*line.b - line.a*b;
        double x = (b*line.c - line.b*c)/bottom;
        double y = (c*line.a - line.c*a)/bottom;
        Point p;
        p.x =x;
        p.y = y;
        return p;
    }
    bool isInter(Line&line){
        double bottom = a*line.b - line.a*b;
        if(bottom == 0){
            return false;
        }
        else{
            return true;
        }
    }
    double Get_angle(Line&line){
        double angle = (line.a*a + line.b*b)/(sqrt(line.a*line.b + line.b*line.b)*sqrt(a*a + b*b));
        return angle;
    }
    bool Is_on_a_line(Point & p){
        if(a*p.x + b*p.y + c == 0){
            return true;
        }
        else{
            return false;
        }
    }
};
int main() {
    const int n = 10;
    Line line;
    Line *array = new Line[10];
    for(int i = 0; i < n; ++i){
        cin>>array[i];
    }
    for(int i = 0; i < n-1; ++i){
        for(int j = i +1; j < n-1; ++j){
            if(array[i].isInter(array[j])){
                cout<<"line"<<array[i]<<"intersepts"<<array[j]<<endl;
                cout<<"point of interseption is("<<array[i].getInterception(array[j]).x<<", "<<array->getInterception(array[i]).y<<')'<<endl;
            }
        }
    }
    int c1,c2 = 0;
    Line OX (0, 1, 0);
    for(int i = 0; i < n; ++i){
        if(array[i].isInter(OX)){
            c1++;
        }
        else if(array[i].Get_angle(OX)== M_PI_2){
            c2++;
        }
    }
    cout<<c1<<c2;
    return 0;
}
