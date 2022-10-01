#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main()
{
	int a;
	int b;
	float aref;
	float geom;
	cout << "Enter the number a:" << endl;
	cin >> a;
	cout << "Enter the number b:" << endl;
	cin >> b;
	aref = (a + b) / 2;
	geom = sqrt((a * b));
	cout << "Arithmetic average value = " << aref << endl;
	cout << "Geometric mean value = " << geom << endl;


	return 0;
}