#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum Colors{
    GREEN,
    BLUE,
    RED,
    YELLOW,
    WHITE,
    BLACK,
    NOCOLOR = -1
};
void add_elem(Colors *array, int n){
    for(int i = 0; i < n; ++i){
        array[i] = Colors(rand() % 6);
    }
}
void print_colors(Colors *array, int n){
    for(int i = 0; i < n ; ++i){
        switch (array[i]) {
            case 0:
                cout << "Color -- " << "Green" << endl;
                break;
            case 1:
                cout << "Color -- " << "Blue" << endl;
                break;
            case 2:
                cout << "Color -- " << "Red" << endl;
                break;
            case 3:
                cout << "Color -- " << "Yellow" << endl;
                break;
            case 4:
                cout << "Color -- " << "White" << endl;
                break;
            case 5:
                cout << "Color -- " << "Black" << endl;
                break;
        }
    }
}
Colors str_to_color(string a){
    for (int i = 0; i < a.size();++i) {
        a[i] = tolower(a[i]);
    }
    if (a == "green"){
        return GREEN;
    }
    else if(a == "blue"){
        return BLUE;
    }
    else if(a == "red"){
        return RED;
    }
    else if(a == "yellow"){
        return YELLOW;
    }
    else if(a == "white"){
        return WHITE;
    }
    else if(a == "black"){
        return BLACK;
    }
    else{
        return NOCOLOR;
    }
}
void print_elem_arr_B(string *array, int n){
    for(int i = 0; i<n; ++i){
        cout << "Color -- " << array[i] << endl;
    }
}
int main() {
    //var
    int n,m, count = 0;
    string str_color;
    Colors result;
    int length_arr_b = 0;
    //input
    cout<<"Enter n: "<<endl;
    cin>>n;
    //input
    srand(time(NULL));
    string *array_B = new string[n];
    Colors *array_A = new Colors[length_arr_b];
    //add elem
    add_elem(array_A, n);
    //print elem
    print_colors(array_A,n);
    //input
    cout<<"Enter a number m: "<< endl;
    cin>>m;
    while(count<m){
        count+=1;
        int counter_2 = 0;
        cout<<"Enter a color: "<<endl;
        cin>>str_color;
        result = str_to_color(str_color);
        int counter_of_elem = 0;
        for(int i = 0; i < n; ++i){
            if(result == array_A[i]) {
                break;
            }
            else if(result != array_A[i]){
                ++counter_of_elem;
            }
        }
        if (counter_of_elem == n){
            length_arr_b += 1;
            array_B[length_arr_b-1] = str_color;
        }
    }
    print_elem_arr_B(array_B, length_arr_b);
    return 0;
}
