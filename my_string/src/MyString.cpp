#include "MyString.h"
#include <cstring>
Mystring::Mystring(){
    data_ = nullptr;
    size_ = 0;
}
Mystring::Mystring(const char*str){
    if (str == nullptr){
        data_ = nullptr;
        size_ = 0;
        return;
    }
    size_ = std::strlen(str);
    data_ = new char[size_ + 1];
    std::strcpy(data_,str);
}
Mystring::~Mystring(){
    delete[]data_;
}
size_t Mystring::size()const{
    return size_;
}
const char* Mystring::c_str() const {
    return data_ ? data_ : "";  // если nullptr — возвращаем пустую строку
}
Mystring::Mystring(const Mystring & other){
    if (other.data_ == nullptr){
        this->data_ = nullptr;
        this->size_ = 0;
        return;
    }
    this->size_ = other.size_;
    this->data_ = new char[size_ + 1];
    std::strcpy(data_,other.data_);

}
Mystring& Mystring::operator=(const Mystring&other){
    if (this == &other){
        return *this;
    }
    char*newdata = nullptr;
    if (other.data_ != nullptr){
        newdata = new char(size_ + 1);
        std::strcpy(newdata,other.data_);
    }
    delete data_;
    data_ = newdata;
    size_ = other.size_;
    return *this;
}
char& Mystring::operator[](size_t index){
    return data_[index];
}
const char& Mystring::operator[](size_t index)const{
    return data_[index];
}
std::ostream&operator<<(std::ostream&out, Mystring&s){
    out << s.c_str();
    return out;
}