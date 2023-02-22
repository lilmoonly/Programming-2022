#include <iostream>
using namespace std;
string fakeBin(string str){
    string output = "";
    for(int i = 0; i < str.length(); ++i){
        if( str[i] == '0' or str[i] == '1' or str[i] == '2' or str[i] == '3' or str[i] == '4'){
            output += '0';
        }
        else{
            output += '1';
        }
    }
    return output;
}