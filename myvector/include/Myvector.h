#include <iostream>
#pragma once
#include <utility>
template <class T>
class Myvector{
private:
    T*data;
    int size;
    int capacity;
public:
    Myvector(){
        capacity = 5;
        size = 0;
        data = new T[capacity];
    }
    ~Myvector(){
        delete[]data;
        data = nullptr;
    }
    int getsize()const{
        return this->size;
    }
    int getcapacity()const{
        return this->capacity;
    }
    void push_back(T value){
        if (this->size < this->capacity){
            data[size] = value;
            size++;
        }
        else {
            capacity *= 2;
            T*newdata = new T[capacity];
            for (int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            newdata[size] = value;
            size++;
            delete[]data;
            data = newdata;
        }
    }
    const T&operator[](int k)const{
        return data[k];
        }
    T&operator[](int k){
        return data[k];
    }
    void swap(Myvector& other) {
        std::swap(data, other.data);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
}
    Myvector(const Myvector&other){
        T *newdata = new T[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        for (int i = 0; i < other.size;i++){
            newdata[i] = other.data[i];
        }
        this->data = newdata;
    }
    Myvector& operator=(Myvector other) {   
        swap(other);                        
        return *this;                        
}
    Myvector(Myvector&&other)noexcept{
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    bool empty() const{
        return size == 0;
    }
    void pop_back(){
        if (size > 0){
            size--;
        }
    }

    void clear(){
        size = 0;
    }
    T&front(){
        return data[0];    }
    const T&front()const{
        return data[0];
    }
    T&back(){
        return data[size - 1];    }
    const T&back()const{
        return data[size - 1];
    }
};

