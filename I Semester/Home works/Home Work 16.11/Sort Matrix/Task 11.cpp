#include <iostream>
using namespace std;
int** get_matrix(int n, int m){
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        cout<<"Array_"<<i+1<<":"<<endl;
        for (int j = 0; j < m; j++) {
            cout<<"Enter a number: "<<endl;
            cin >> matrix[i][j];
        }

    }

    return matrix;
}
int check_colum(int **array, int n, int m){
    int array_num[n];
    for (int i = 0; i<n; ++i){
        array_num[i]=array[i][m];
    }
    for(int i = 0; i<n-1; ++i){
        if(array_num[i]<array_num[i+1]){
        }
        else{
            return 0;
        }
    }
    cout<<"Array :"<<endl;
    for(int i = 0; i < n; ++i){
        cout<<array_num[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n,m;
    int** matrix;
    cout<<"Enter a count of row: "<<endl;
    cin>>n;
    cout<<"Enter a count of colum: "<<endl;
    cin>>m;
    matrix = get_matrix(n,m);
    for(int i = 0; i<m; ++i){
        if(check_colum(matrix,n,i) != 0){
        }
        else{
            cout<<"Array"<<" dont creat increasing sequence"<<endl;
        }
    }
}