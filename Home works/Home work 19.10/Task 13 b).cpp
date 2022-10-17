#include <iostream>
using namespace std;
int main() {
    int list[10000];
    int list_result[1000];
    int n,m;
    cout<<"Enter a n: "<<endl;
    cin>>n;
    cout<<"Enter a m: "<< endl;
    cin>>m;
    if (n >= m){
        for (int i = 0; i <= n / 2; i++){
            list[i] = i+1;
        }

    }
    else if (n <= m){
        for (int i = 0; i <= m / 2; i++){
            list[i] = i+1;
        }
    }
    else{
        cout<<"Wrong type of n or m";
    }
    for (int i : list){
        int count = 0;
        if(n%i == 0 and m%i == 0){
            list_result[count] = i;
            count += 1;
            cout<<i<< endl;
            cout<<-i<< endl;
        }
    }

    return 0;
}
