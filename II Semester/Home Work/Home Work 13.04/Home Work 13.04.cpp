#include <iostream>
#include <vector>
using namespace std;
template <typename T>
vector<T> func(vector<T> array, size_t size){
    vector<T> result;
    try {
        if (array.size() != size) {
            throw "The array size and the passed size are different";
        }
        for(int i = 0; i < size; i++){
            if(i%2==0){
                result.push_back(array[i]);
                result.push_back(array[i]);
            }
            else{
                result.push_back(array[i]);
            }
        }
    }
    catch (const char* e){
        cerr<<e<<endl;
    }
    return result;
}

int main() {
    //should equal "The array size and the passed size are different"
    vector<string> vec1{"QWERTY","aw","rt","loc"};
    vec1 = func(vec1, 1);
    for(auto elem: vec1){
        cout<<elem;
    }

    //should equal QWERTYQWERTYawrtrtloc
    vector<string> vec2{"QWERTY","aw","rt","loc"};
    vec2 = func(vec2, 4);
    for(auto elem: vec2){
        cout<<elem;
    }
    cout<<endl;

    //should equal nothing
    vector<int> vec3{};
    vec3 = func(vec3, 0);
    for(auto elem: vec3){
        cout<<elem;
    }

    //should equal 112334
    vector<int> vec4{1,2,3,4};
    vec4 = func(vec4, 4);
    for(auto elem: vec4){
        cout<<elem;
    }
    cout<<endl;
    return 0;
}
