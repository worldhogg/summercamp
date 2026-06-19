#include "MyString.h"
#include <iostream>

int main() {
    std::cout << "=== Тест 1: конструкторы ===\n";
    Mystring s1;
    Mystring s2("hello");
    std::cout << "s1 = \"" << s1 << "\" (size: " << s1.size() << ")\n";
    std::cout << "s2 = \"" << s2 << "\" (size: " << s2.size() << ")\n";
    
    std::cout << "\n=== Тест 2: конструктор копирования ===\n";
    Mystring s3 = s2;              // конструктор копирования
    std::cout << "s3 = \"" << s3 << "\" (size: " << s3.size() << ")\n";
    
    std::cout << "\n=== Тест 3: независимость копий ===\n";
    s3[0] = 'H';                   // меняем первый символ
    std::cout << "После s3[0] = 'H':\n";
    std::cout << "s2 = \"" << s2 << "\" (не должно измениться)\n";
    std::cout << "s3 = \"" << s3 << "\"\n";
    
    std::cout << "\n=== Тест 4: оператор присваивания ===\n";
    Mystring s4("world");
    s4 = s2;
    std::cout << "После s4 = s2:\n";
    std::cout << "s4 = \"" << s4 << "\" (должно быть \"hello\")\n";
    
    std::cout << "\n=== Тест 5: самоприсваивание ===\n";
    s4 = s4;
    std::cout << "После s4 = s4: \"" << s4 << "\" (не должно сломаться)\n";
    
    std::cout << "\n=== Тест 6: цепочка ===\n";
    Mystring a, b, c;
    a = b = c = Mystring("chain");
    std::cout << "a = \"" << a << "\", b = \"" << b << "\", c = \"" << c << "\"\n";
    
    std::cout << "\n=== Тест 7: доступ по индексу ===\n";
    Mystring s5("test");
    for (size_t i = 0; i < s5.size(); i++) {
        std::cout << "s5[" << i << "] = '" << s5[i] << "'\n";
    }
    std::cout << "\n=== Тест 8: конструктор перемещения ===\n";
{
    Mystring s1("hello");
    std::cout << "До move: s1 = \"" << s1 << "\", size = " << s1.size() << "\n";
    
    Mystring s2 = std::move(s1);  // перемещаем
    
    std::cout << "После move:\n";
    std::cout << "  s1 size = " << s1.size() << " (должно быть 0)\n";
    std::cout << "  s2 = \"" << s2 << "\", size = " << s2.size() << " (должно быть hello, 5)\n";
}

    std::cout << "\n=== Тест 9: оператор перемещающего присваивания ===\n";
{
    Mystring s1("world");
    Mystring s2("temporary");
    
    s1 = std::move(s2);
    
    std::cout << "После s1 = std::move(s2):\n";
    std::cout << "  s1 = \"" << s1 << "\" (должно быть temporary)\n";
    std::cout << "  s2 size = " << s2.size() << " (должно быть 0)\n";
}

    std::cout << "\n=== Тест 10: возврат из функции ===\n";
{
    auto makeString = []() {
        Mystring result("from function");
        return result;  // компилятор сделает move (или RVO)
    };
    
    Mystring s = makeString();
    std::cout << "s = \"" << s << "\" (должно быть from function)\n";
}
    return 0;
}