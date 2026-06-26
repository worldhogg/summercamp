#include <iostream>
#include "Myvector.h"
int main(){
    Myvector<int> v;
    std::cout << v.getsize() << " " << v.getcapacity() << "\n"; 
}
