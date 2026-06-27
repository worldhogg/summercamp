#include <iostream>
#include <utility>
#include "Myvector.h"

int main() {
    // деструктор + push_back (база)
    Myvector<int> a;
    a.push_back(10);
    a.push_back(20);

    // копирующий конструктор — deep copy
    Myvector<int> b = a;
    b[0] = 999;
    std::cout << "copy ctor: " << a[0] << " " << b[0] << "\n";   // 10 999

    // копирующий operator= (copy-and-swap)
    Myvector<int> c;
    c = a;
    c[0] = 777;
    std::cout << "copy=:     " << a[0] << " " << c[0] << "\n";   // 10 777

    // move-конструктор
    Myvector<int> d = std::move(a);
    std::cout << "move ctor: " << d[0] << " " << d.getsize()
              << " | a empty: " << a.getsize() << "\n";          // 10 2 | a empty: 0

    // move operator=
    Myvector<int> e;
    e.push_back(1);
    e = std::move(b);
    std::cout << "move=:     " << e[0] << " " << e.getsize()
              << " | b empty: " << b.getsize() << "\n";          // 999 2 | b empty: 0

    std::cout << "no crash on exit = all 5 correct\n";
}