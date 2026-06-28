#include <iostream>
#include <utility>
#include "Myvector.h"

int main() {
    Myvector<int> v;
    std::cout << v.empty() << "\n";        // 1 (пустой)
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::cout << v.empty() << "\n";        // 0
    std::cout << v.front() << " " << v.back() << "\n";  // 10 30
    v.pop_back();
    std::cout << v.back() << " " << v.getsize() << "\n"; // 20 2
    v.clear();
    std::cout << v.empty() << " " << v.getsize() << "\n"; // 1 0
}