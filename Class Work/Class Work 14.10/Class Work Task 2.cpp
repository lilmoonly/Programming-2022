#include <iostream>
#include <math.h>
#include <list>
using namespace std;

int main() {
    int m;
    cout<<"Enter m: "<<endl;
    cin>>m;
    int k;
    for ( k = 0; pow(4, k)< m; ++k )
        cout<<"k = "<<k<<endl;

    cout<<"Answer = "<<k-1<<endl<< pow(4, k-1)<<endl;
    return 0;
}
