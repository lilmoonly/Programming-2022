#include <iostream>
using namespace std;
int common_elem(int n_1, int *array_1, int n_2){
    bool r = false;
    for (int s = 0; s < n_2; ++s){
        if (array_1[s] == n_1){
            r = true;
        }
    }
    return r;
}
int main() {
    int a,b;
    //Creating array a
    cout<<"Enter size of array a: "<<endl;
    cin>>a;
    int *array_a = new int(a);
    for(int i = 0; i < a; ++i){
        cout<<"Enter an element of array a: "<<endl;
        cin>>array_a[i];
    }
    //Creating array b
    cout<<"Enter size of array b: "<<endl;
    cin>>b;
    int *array_b = new int(b);
    for(int i = 0; i < b; ++i) {
        cout << "Enter an element of array b: " << endl;
        cin >> array_b[i];
    }
    //Common elem
    int SIZE = 1;
    int count = 0;
    int *array_a_b = new int(SIZE);
    for (int i = 0; i < a; ++i){
        for (int u = 0; u < b; ++u){
            if (array_a[i]==array_b[u]){
                if(common_elem(array_a[i],array_a_b,count) == true){
                    break;
                }
                else{
                    ++SIZE;
                    array_a_b[count]=array_a[i];
                    ++count;
                }

            }
        }
    }
    for(int i = 0; i < SIZE-1; ++i){
        cout<<"Elem b_a = "<<array_a_b[i]<<endl;
    }
    return 0;
}
