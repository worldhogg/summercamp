#pragma once
#include <cstddef>  // для size_t
#include <iostream> // для оператора
class Mystring{
private:
    char*data_;
    size_t size_;
public:
//создаем конструкторы
    Mystring();//пустая строка
    Mystring(const char*str);// иницализация с строки
    Mystring(const Mystring&other);// конструктор копирования
    Mystring(Mystring &&other)noexcept;//конструктор перемещения

    Mystring &operator=(const Mystring&other); // оператор присваивания
    Mystring&operator=(Mystring&&other)noexcept;//оператор пермещеающего присваивания 

    ~Mystring();// деструктор

    size_t size()const;//возврат размера
    const char* c_str() const;//указатель ну внутренний массив
    //доступ к символам
    bool empty() const;
    void clear();
    char& operator[](size_t index);          // изменение (s[0] = 'A')
    const char& operator[](size_t index) const;  // чтение (только const)
    friend std::ostream&operator<<(std::ostream&out,Mystring&s);
    bool operator==(const Mystring&other)const;
    bool operator!=(const Mystring &other)const;
    Mystring operator+(const Mystring&other)const;
};