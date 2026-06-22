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
    }
    size_ = std::strlen(str);
    data_ = new char(size_ + 1);
    std::strcpy(data_,str);
}
Mystring::~Mystring(){
    delete []data_;
}
size_t Mystring::size()const{
    return size_;
}
const char* Mystring::c_str() const {
    return data_ ? data_ : "";  // если nullptr — возвращаем пустую строку
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
Mystring::Mystring(const Mystring& other) {
    if (other.data_ == nullptr) {
        data_ = nullptr;
        size_ = 0;
        return;
    }
    
    size_ = other.size_;
    data_ = new char[size_ + 1];
    std::strcpy(data_, other.data_);
}
Mystring::Mystring(Mystring&&other)noexcept{
    this->data_ = other.data_;
    this->size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
    
}
Mystring& Mystring::operator=(Mystring&&other)noexcept{
    if (this == &other){
        return *this;
    }
    delete[]data_;
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
    return *this;
}
bool Mystring:: empty() const{
    if (size_ == 0){
        return true;
    }
    return false;
}
void Mystring::clear(){
    delete []data_;
    data_ = nullptr;
    size_ = 0;
}
bool Mystring::operator==(const Mystring&other)const{
    if (size_ != other.size_){
        return false;
    }
    if (data_ == nullptr && other.data_ == nullptr){
        return true;
    }
    if (data_ == nullptr || other.data_ == nullptr){
        return false;
    }
    return std::strcmp(data_,other.data_) == 0;
}
bool Mystring::operator!=(const Mystring&other)const{
    return !(*this == other);
}
Mystring Mystring::operator+(const Mystring&other)const{
    Mystring result;
    result.size_ = size_ + other.size_;
    if (result.size_ == 0){
        return result;
    }
    result.data_ = new char[result.size_ + 1];
    result.data_[0] = '/0';
    if (data_ != nullptr){
        std::strcpy(result.data_,data_);
    }
    if (other.data_ != nullptr){
        std::strcat(result.data_,other.data_);
    }
    return result;
}