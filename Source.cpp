#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <math.h>
using namespace std;


int main()
{
	float r;
	cout << "Enter the radius:" << endl;
	cin >> r;
	float l;
	float s;
	float v;
	l = r * 2 * M_PI;
	s = pow(r, 2) * M_PI;
	v = 4 / 3 * M_PI * pow(r, 3);
	cout << "Circle length = " << l << endl << "Circle area = " << s << endl << "Volume of the sphere = " << v << endl;
	return 0;
}