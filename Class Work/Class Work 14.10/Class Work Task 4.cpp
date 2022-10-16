#include <iostream>
using namespace std;
int main() {
    long long n, a, b;
    cin>>n;
    b = 0;
    while(n > 0){
        a = n%10;
        n/=10;
        b *= 10;
        b += a;
    }
    cout<<b<<endl;
    return 0;
}
