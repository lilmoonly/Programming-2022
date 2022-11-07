#include <iostream>
using namespace std;
int main() {
    int n,m;
    int x = 0;
    int y = 0;
    int k = 0;
    cout<<"Enter n:"<<endl;
    cin>>n;
    cout<<"Enter m:"<<endl;
    cin>>m;
    int *arr_1 = new int[n];
    int *arr_2 = new int[m];
    int *arr_3 = new int[n+m];
    for (int i = 0; i < n; ++i){
        cout<<"Enter an elem arr_1:"<<endl;
        cin>>arr_1[i];
    }
    for (int i = 0; i < m; ++i){
        cout<<"Enter an elem arr_2"<<endl;
        cin>>arr_2[i];
    }
    while(true){
        if (arr_1[x]>arr_2[y]){
            arr_3[k] = arr_2[y];
            k++;y++;
            if (y == m){
                break;
            }
        }
        else {
            arr_3[k]=arr_1[x];
            k++; x++;
            if (x == n){
                break;
            }
        }
    }
    if (x<n){
        for (x ; x<n; ++x){
            arr_3[k]=arr_1[x];
            k++;
        }

    }
    else if (y<m){
        for (y; y<m; ++y){
            arr_3[k]=arr_2[y];
            k++;
        }
    }
    for(int w = 0; w<n+m; ++w){
        cout<<arr_3[w];
    }
    return 0;
}
