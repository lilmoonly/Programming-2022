#include <iostream>
using namespace std;
enum DogBreeds{
    SHPIC,//0
    HASKY,//1
    TAKSA,//2
    NOBREED = -1

};
void add_elem(DogBreeds *array, int n){
    for(int i = 0; i<n; ++i){
        array[i]= DogBreeds(rand() % 3);
    }
}
void print_breeds(DogBreeds *array_1, int n) {
    for (int i = 0; i < n; ++i) {
        switch (array_1[i]) {
            case 0:
                cout << "Breed -- " << "Shpic" << endl;
                break;
            case 1:
                cout << "Breed -- " << "Hasky" << endl;
                break;
            case 2:
                cout << "Breed -- " << "Taksa" << endl;
                break;
        }
    }
}
DogBreeds str_to_dogbreed(string a){
    //tolower(a);
    for (int i = 0; i < a.size();++i) {
        a[i] = tolower(a[i]);
    }
    if (a == "shpic"){
        return SHPIC;
    }
    else if(a == "hasky"){
        return HASKY;
    }
    else if(a == "taksa"){
        return TAKSA;
    }
    else{
        return NOBREED;
    }
}
int main() {
    int n;
    bool res = false;
    DogBreeds result;
    string breed;
    cout<<"Enter n: "<< endl;
    cin>>n;
    DogBreeds *array_breeds = new DogBreeds[n];
    add_elem(array_breeds, n);
    //print_breeds(array_breeds,n);
    while(res == false) {
        cout << "Enter a breed" << endl;
        cin>>breed;
        result = str_to_dogbreed(breed);
        for (int i = 0; i < n; ++i) {
            if (result == array_breeds[i]) {
                cout << "Breed is found" << endl;
                res = true;
                break;
            }
        }
        if (res == false) {
            cout << "Breed is not fund" << endl;
        }
    }
    return 0;
}
