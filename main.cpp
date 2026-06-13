#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
int main(){
    unordered_map<string,int>mymap;
    mymap["artem"] = 12;
    cout << mymap["artem"];
    if (mymap.find("artem") != mymap.end()){
        cout << "нашел";
    }
}
