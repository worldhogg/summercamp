#include <iostream>
#include "Myvector.h"
int main(){
    Myvector<int> v;
    for (int i = 0; i < 7; i++) v.push_back(i * 10);
    std::cout << v.getsize() << " " << v.getcapacity() << "\n";   // ждём: 7 10
    std::cout << v.operator[](2) ;
    std::cout << "\n";
    v[0] = 999;                          // проверка записи
    std::cout << v[0] << "\n"; 
}
