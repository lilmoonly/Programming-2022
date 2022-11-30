#include <string>
using namespace std;
bool is_uppercase(const string &s) {
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == ' '){
            continue;
        }
        if(s[i] != toupper(s[i])){
            return false;
        }
    }
    return true;
}
