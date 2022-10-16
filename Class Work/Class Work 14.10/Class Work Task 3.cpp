#include <iostream>
using namespace std;
int main() {
    int n;
    int u0 = 0, u1 = 1, u;
    cout<< "Enter n: "<< endl;
    cin>>n;
    cout<<u0<<endl;
    cout<<u1<<endl;
    for (int i = 2; i <= n; ++i){
        u = u0 + u1;
        cout<<u<<endl;
        u0 = u1;
        u1 = u;

    }

    return 0;
}
